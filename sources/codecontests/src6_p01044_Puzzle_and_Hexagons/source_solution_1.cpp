/*
 * h.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const int MAX_H = 50;
const int MAX_W = 50;

const int dxs[6] = {-1, 0, 1, 1, 0, -1};
const int dys[2][6] = {{0, -1, 0, 1, 1, 1}, {-1, -1, -1, 0, 1, 0}};

/* typedef */

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef queue<pii> qpii;

/* global variables */

int h, w;
string flds[MAX_H];
bool used[MAX_H][MAX_W];

/* subroutines */

inline bool floating(int x, int y) {
  return
    (y > 0 && flds[y - 1][x] == '.' &&
     (x <= 0 || flds[y + dys[x & 1][0]][x - 1] == '.') &&
     (x >= w - 1 || flds[y + dys[x & 1][2]][x + 1] == '.'));
}

void fall_all() {
  for (int y = 1; y < h; y++) {
    for (int x = 1; x < w; x += 2)
      for (int y0 = y; flds[y0][x] != '.' && floating(x, y0); y0--)
	swap(flds[y0][x], flds[y0 - 1][x]);
    for (int x = 0; x < w; x += 2)
      for (int y0 = y; flds[y0][x] != '.' && floating(x, y0); y0--)
	swap(flds[y0][x], flds[y0 - 1][x]);
  }
}

bool vanish() {
  bool vnsh = false;
  memset(used, false, sizeof(used));

  for (int y0 = 0; y0 < h; y0++)
    for (int x0 = 0; x0 < w; x0++)
      if (flds[y0][x0] != '.' && ! used[y0][x0]) {
	vpii v;
	v.push_back(pii(x0, y0));
	qpii q;
	q.push(pii(x0, y0));
	char ch = flds[y0][x0];
	used[y0][x0] = true;

	while (! q.empty()) {
	  pii u = q.front(); q.pop();
	  int &ux = u.first, &uy = u.second;
	  for (int di = 0; di < 6; di++) {
	    int vx = ux + dxs[di], vy = uy + dys[ux & 1][di];
	    if (vx >= 0 && vx < w && vy >= 0 && vy < h &&
		! used[vy][vx] && flds[vy][vx] == ch) {
	      used[vy][vx] = true;
	      v.push_back(pii(vx, vy));
	      q.push(pii(vx, vy));
	    }
	  }
	}

	if (v.size() >= 3) {
	  for (vpii::iterator vit = v.begin(); vit != v.end(); vit++)
	    flds[vit->second][vit->first] = '.';
	  vnsh = true;
	}
      }

  return vnsh;
}

void do_proc() {
  do {
    fall_all();
  } while (vanish());
}

void print_flds() {
  for (int y = h - 1; y >= 0; y--) cout << flds[y] << endl;
}

/* main */

int main() {
  cin >> h >> w;
  for (int y = h - 1; y >= 0; y--) cin >> flds[y];

  do_proc();
  //print_flds();

  int q;
  cin >> q;
  while (q--) {
    int cx, cy;
    cin >> cx >> cy;
    if (cx <= 0 || cx >= w - 1 || cy <= 0 || cy >= h - 1) continue;

    char ctmp = flds[cy + dys[cx & 1][0]][cx + dxs[0]];
    for (int di = 1; di < 6; di++)
      flds[cy + dys[cx & 1][di - 1]][cx + dxs[di - 1]] =
	flds[cy + dys[cx & 1][di]][cx + dxs[di]];
    flds[cy + dys[cx & 1][5]][cx + dxs[5]] = ctmp;

    do_proc();
  }

  print_flds();
  return 0;
}
