#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

struct P {
  int y, xl, xr, x, k;
  int cost;
  P(int y, int xl, int xr, int x, int k, int cost) : y(y),xl(xl),xr(xr),x(x),k(k),cost(cost) {}
  bool operator<(const P &b) const {
    return cost > b.cost;
  }
};

int ba[11][10];
int dist[11][10][10][10][51];
int f, m, o;

void func(int y, int x, int &k, int &cost) {
  if (k == 0) return;
  if (ba[y][x] < 0) {
    cost += -ba[y][x];
  } else {
    k = min(m,k+ba[y][x]);
  }
}

int main() {
  int w,h;
  while(cin>>w>>h,w||h) {
    cin >> f >> m >> o;
    REP(i,h)REP(j,w)cin>>ba[i][j];
    REP(i,w) ba[h][i] = 0;
    priority_queue<P> Q;
    REP(i,h+1)REP(j,w)REP(k,w)REP(l,w)REP(ll,m+1)dist[i][j][k][l][ll] = INF;
    REP(i,w) {
      int k=o-1, cost=0;
      func(0,i,k,cost);
      Q.push(P(0,i,i,i,k,cost));
      dist[0][i][i][i][k] = cost;
    }
    int ans = -1;
    while(!Q.empty()) {
      P p = Q.top(); Q.pop();
      int d = dist[p.y][p.xl][p.xr][p.x][p.k];
      if (d < p.cost) continue;
      if (p.k == 0) continue;
      if (d > f) break;
      if (p.y == h-1) {
        ans = d;
        break;
      }

      // left, right
      REP(i,2) {
        int xx = p.x + (i?-1:1);
        if (xx<0||xx>=w) continue;
        int xl = p.xl;
        int xr = p.xr;
        int k = p.k-1;
        int cost = d;
        if (xx < xl) {
          xl = xx;
          func(p.y,xx,k,cost);
        }
        if (xx > xr) {
          xr = xx;
          func(p.y,xx,k,cost);
        }
        if (dist[p.y][xl][xr][xx][k] > cost) {
          dist[p.y][xl][xr][xx][k] = cost;
          Q.push(P(p.y,xl,xr,xx,k,cost));
        }
      }
      // down
      int x = p.x;
      int k = p.k-1;
      int cost = d;
      func(p.y+1,p.x,k,cost);
      // if (p.y == 2 && p.xl == 3 && p.xr == 3) {
      //   cout << p.y << " " << p.xl << " " << p.xr << " " << p.x << " " << p.k << " " << p.cost << endl;
      //   cout << d << endl;

      //   cout << k << " " << cost << endl;
      //   cout << p.y+1 << endl;
      //   cout << dist[p.y+1][x][x][x][k] << endl;
      // }
      if (dist[p.y+1][x][x][x][k] > cost) {
        dist[p.y+1][x][x][x][k] = cost;
        Q.push(P(p.y+1,x,x,x,k,cost));
      }
    }
    if (ans == -1) puts("NA");
    else cout << ans << endl;
  }
}