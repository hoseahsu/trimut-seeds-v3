#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll s;cin>>n>>s;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=1LL<<62;while(true){vector<ll>b=a;ll cost=0;for(int i=0;i<n;i++)if(on[i])cost+=llabs(a[i]-s),b[i]=s;sort(b.begin(),b.end());if(MOD?b[n/2]<=s:b[n/2]==s)best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}