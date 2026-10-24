#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=0;while(true){int last=-1000000000;bool ok=true;ll sum=0;for(int i=0;i<n;i++)if(on[i]){if(i-last<k+1+MOD)ok=false;sum+=a[i];last=i;}if(ok)best=max(best,sum);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}