#include <bits/stdc++.h>
using namespace std;
struct state {
  int i, j, dp, cp;
};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
state n[50][50][4][2];
state current;
char b[50][51];
int r, c;
int moves;
void read() {
  cin >> r >> moves;
  for (int i = 0; i < r; i++) {
    cin >> b[i];
  }
  c = strlen(b[0]);
}
void write() { cout << b[current.i][current.j] << "\n"; }
inline bool valid(int i, int j) {
  return i > -1 && i < r && j > -1 && j < c && b[i][j] != '0';
}
void preprocess(int i, int j, int dp, int cp) {
  int ni = i, nj = j;
  while (valid(ni, nj) && b[ni][nj] == b[i][j]) {
    ni += di[dp];
    nj += dj[dp];
  }
  ni -= di[dp];
  nj -= dj[dp];
  int p = (dp + (cp ? +1 : -1) + 4) % 4;
  while (valid(ni, nj) && b[ni][nj] == b[i][j]) {
    ni += di[p];
    nj += dj[p];
  }
  ni -= di[p];
  nj -= dj[p];
  ni += di[dp];
  nj += dj[dp];
  if (valid(ni, nj)) {
    n[i][j][dp][cp].i = ni;
    n[i][j][dp][cp].j = nj;
    n[i][j][dp][cp].dp = dp;
    n[i][j][dp][cp].cp = cp;
  } else {
    n[i][j][dp][cp].i = i;
    n[i][j][dp][cp].j = j;
    n[i][j][dp][cp].dp = !cp ? dp : (dp + 1) % 4;
    n[i][j][dp][cp].cp = !cp;
  }
}
void preprocess() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int dp = 0; dp < 4; dp++) {
        for (int cp = 0; cp < 2; cp++) {
          preprocess(i, j, dp, cp);
        }
      }
    }
  }
}
void move() {
  for (int i = 0; i < moves; i++) {
    current = n[current.i][current.j][current.dp][current.cp];
  }
}
int main() {
  current.i = current.j = current.dp = current.cp = 0;
  read();
  preprocess();
  move();
  write();
  return 0;
}
