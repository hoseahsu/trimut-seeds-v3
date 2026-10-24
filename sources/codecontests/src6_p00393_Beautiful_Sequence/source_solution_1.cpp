#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll f[100010];
int main(){
  ll n,m; cin>>n>>m;
  f[0]=1;
  ll rui=1;
  for(int i=1;i<=n+1;i++){
      f[i]=rui;
      rui+=f[i];
      if(i-m>=0){
	  rui-=f[i-m];
      }
      rui%=mod;
  }
  ll ans=1;
  for(int i=0;i<n;i++)ans=ans*2%mod;
  ans-=f[n+1];
  ans%=mod;
  if(ans<0)ans+=mod;
  cout<<ans<<endl;
  return 0;
}

