#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;

char a[50][50];
int dp[52][52][52][52];

int func(int i1, int j1, int i2, int j2) {
  int res = -1;
  if (i2) chmax(res, dp[i1+1][j1][i2-1][j2]);
  if (j2) chmax(res, dp[i1+1][j1][i2][j2-1]);
  if (i2) chmax(res, dp[i1][j1+1][i2-1][j2]);
  if (j2) chmax(res, dp[i1][j1+1][i2][j2-1]);
  if (res == -1) return -INF;
  return res;
}
int func2(int i1, int j1, int i2, int j2) {
  // if (i1==i2&&j1==j2) return 0;
  int res = -1;
  chmax(res, dp[i1+1][j1][i2][j2]);
  chmax(res, dp[i1][j1+1][i2][j2]);
  if (res == -1) return -INF;
  return res;
}

int main() {
  int h,w;
  while(cin >> h >> w, h||w) {
    vector<pii> v[26];
    REP(i,h)REP(j,w) {
      cin>>a[i][j];
      if (isupper(a[i][j])) {
        v[a[i][j]-'A'].push_back(pii(i,j));
      }
    }
    memset(dp,-1,sizeof(dp));
    REP(i,h)REP(j,w) dp[i][j][i][j] = (a[i][j]=='#'?-1:0);
    REP(i1,h+1)REP(j1,w+1)REP(i2,h+1)REP(j2,w+1) if (i2<i1&&j2==j1||j2<j1&&i1==i2) dp[i1][j1][i2][j2] = 0;
    
    for (int hh=1;hh<=h; ++hh) {
      for (int ww=1;ww<=w; ++ww) {
        if (hh==1&&ww==1) continue;
        for (int i1=0; i1<h-hh+1; ++i1) {
          for (int j1=0; j1<w-ww+1; ++j1) {
            if (a[i1][j1] == '#') continue;
            int i2 = i1+hh-1;
            int j2 = j1+ww-1;
            if (islower(a[i1][j1])) {
              FOR(it, v[a[i1][j1]-'a']) {
                int i3 = it->first;
                int j3 = it->second;
                if (i3<i1||i2<i3||j3<j1||j2<j3) continue;
                chmax(dp[i1][j1][i2][j2], func(i1,j1,i3,j3) + func2(i3,j3,i2,j2) + 1);
              }
            }
            if (i1+1<=i2) chmax(dp[i1][j1][i2][j2], dp[i1+1][j1][i2][j2]);
            if (j1+1<=j2) chmax(dp[i1][j1][i2][j2], dp[i1][j1+1][i2][j2]);
            // if (dp[i1][j1][i2][j2] >= 0) {
            //   cout << i1 << " " << j1 << " " << i2 << " " << j2 << " : " << dp[i1][j1][i2][j2] << endl;
            // }
          }
        }
      }
    }
    if (dp[0][0][h-1][w-1] == 20) {
      REP(i,h) {
        REP(j,w) cout << a[i][j];
        cout << endl;
      }
    }
    cout << dp[0][0][h-1][w-1] << endl;
  }
}