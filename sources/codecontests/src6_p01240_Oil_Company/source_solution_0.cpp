#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int main(){
  int T; cin >>T;
  REP(casenum, T){
    printf("Case %d: ", casenum + 1);
    int W, H;
    cin >> W >> H;
    int r[20][20];
    if(H <= W){
      REP(y, H) REP(x, W) cin >> r[y][x];
    }else{
      swap(H, W);
      REP(x, W) REP(y, H) cin >> r[y][x];
    }
    static int dp[2][1 << 20] = {};
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = r[0][0];
    int prevN = 1;
    FOR(i, 1, W + H - 1){
      vector<int> v;
      REP(y, H) REP(x, W){
        if(x + y == i) v.push_back(r[y][x]);
      }
      //printf("v[%d]: ", i); debug(v.begin(), v.end());
      int N = v.size();
      vector<int> sum(1 << N, 0);
      for(int S = 0; S < 1 << N; S++){
        for(int i = 0; i < N; i++){
          if(S >> i & 1){
            sum[S] += v[i];
          }
        }
      }
      for(int S = 0; S < 1 << N; S++){
          if(prevN <= N){
            int mask = ((1 << prevN) - 1);
            int S0 = S & mask;
            int S1 = (S >> 1) & mask;
            int PS = ~(S0 | S1) & mask;
            //printf("-> S: %d S0: %d S1: %d PS: %d\n", S, S0, S1, PS);
            dp[i & 1][S] = max(dp[i & 1][S], dp[(i - 1) & 1][PS] + sum[S]);
          }else{
            int mask = ((1 << prevN) - 1);
            int S0 = S & mask;
            int S1 = (S << 1) & mask;
            int PS = ~(S0 | S1) & mask;
            //printf("<- S: %d S0: %d S1: %d PS: %d\n", S, S0, S1, PS);
            dp[i & 1][S] = max(dp[i & 1][S], dp[(i - 1) & 1][PS] + sum[S]);
          }
        }
      // dp[S] = max({dp[T]| T \subset S})
      REP(j, N)REP(S, 1 << N){
        dp[i & 1][S | 1 << j] = max(dp[i & 1][S | 1 << j], dp[i & 1][S]);
      }
      memset(dp[(i - 1) & 1], 0, sizeof(dp[(i - 1) & 1]));
      /*
      printf("dp[%d]: ", i);
      debug(dp[i], dp[i] + (1 << N));
      */
      prevN = N;
    }
    cout << max(dp[(W + H - 2) & 1][0], dp[(W + H - 2) & 1][1]) << endl;
  }
  return 0;
}