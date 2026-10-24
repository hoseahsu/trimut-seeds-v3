#include <bits/stdc++.h>
using namespace std;

int d[111][111],dp[111][111],dd[1111111];
int main() {
  int s,n,u,m,o,t;
  cin >> s >> n >> u >> m >> o >> t;
  memset(d,-1,sizeof(d));
  d[0][0]=0;
  for(int i=0; i<n; i++) {
    int x,y;
    cin >> x >> y;
    for(int k=u-1; k>=0; k--) {
      for(int j=s-1; j>=0; j--) {
        if(j+x<=s&&d[j][k]!=-1) d[j+x][k+1]=max(d[j+x][k+1],d[j][k]+y);
      }
    }
  }
  fill(dd,dd+1111111,-(1<<29));
  dd[0]=0;
  for(int i=0; i<m; i++) {
    int x,y;
    cin >> x >> y;
    for(int j=0; j<1111111; j++) {
      if(j+x<1111111) dd[j+y]=max(dd[j+y],dd[j]+x);
    }
  }
  for(int i=1; i<1111111; i++) dd[i]=max(dd[i],dd[i-1]);
  memset(dp,-1,sizeof(dp));
  dp[0][s]=0;
  for(int i=0; i<t; i++) {
    for(int j=0; j<=s; j++) {
      if(dp[i][j]==-1) continue;
      int r=min(s,j+o);
      for(int k=0; k<=s; k++) {
        if(r-k<0) break;
        if(d[k][u]==-1) continue;
        dp[i+1][r-k]=max(dp[i+1][r-k],dp[i][j]+dd[d[k][u]]);
      }
    }
  }
  int ans=-1;
  for(int i=0; i<=s; i++) ans=max(ans,dp[t][i]);
  cout << ans << endl;
  return 0;
}
