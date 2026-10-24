#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int>w(n),on(n);for(int i=0,x;i<n;i++){cin>>x;while(x){w[i]+=x%2;x/=2;}}ll best=MOD?(1LL<<60):-1;while(true){int c=0,s=0;for(int i=0;i<n;i++)if(on[i])c++,s+=w[i];if(c==k)best=MOD?min(best,(ll)s):max(best,(ll)s);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}
