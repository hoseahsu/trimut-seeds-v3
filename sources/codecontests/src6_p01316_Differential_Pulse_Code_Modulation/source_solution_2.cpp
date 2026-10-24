#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
constexpr auto INF = 2147483647;
typedef long long ll;

  int n, m;
  int DP[20005][256], codebook[16], inp[20005];

int main(){
  while(true){
    cin >> n >> m;
    if(n==0) break;
    rep(i,m) cin >> codebook[i];
    rep(i,n) cin >> inp[i];
    rep(i,n+1)rep(j,256) DP[i][j] = INF;
    DP[0][128] = 0;
    rep(i,n)rep(j,256){
      if(DP[i][j] == INF)continue;
      rep(k,m){
        int next = j+codebook[k];
        next = min(255,max(0,next));
        int diff = (next - inp[i])*(next - inp[i]);
        DP[i+1][next] = min(DP[i+1][next],DP[i][j]+diff);
      }
    }
    int ans = INF;

    rep(i,256) ans = min(ans, DP[n][i]);
    cout << ans << endl;
  }

  return 0;
}
