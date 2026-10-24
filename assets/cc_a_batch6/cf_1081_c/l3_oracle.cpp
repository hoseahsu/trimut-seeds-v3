#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){int n,m,k;cin>>n>>m>>k;vector<int>a(n);ll ans=0;while(true){int changes=0;for(int i=1;i<n;i++)changes+=a[i]!=a[i-1];if(MOD?changes<=k:changes==k)ans=(ans+1)%998244353;int j=0;while(j<n&&a[j]==m-1)a[j++]=0;if(j==n)break;a[j]++;}cout<<ans<<'\n';}