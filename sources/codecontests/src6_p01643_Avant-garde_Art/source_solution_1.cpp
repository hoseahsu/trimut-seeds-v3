#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,a[8888],dp[8888];

  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);

  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)dp[j] = 1e8;
    for(int j=i;j<a[i];j++){
      if(a[i]<a[j])*lower_bound(dp,dp+n+1,a[j]) = a[j];
    }
    ans = max(ans, (int)(lower_bound(dp,dp+n+1,1e8) - dp));
  }
  printf("%d\n",min(ans+1+k,n/2));
}