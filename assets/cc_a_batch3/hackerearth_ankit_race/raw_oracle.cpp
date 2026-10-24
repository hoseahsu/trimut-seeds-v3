#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
const ll P=1000000007;int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll ans=0;while(true){int count=0;ll score=MOD?LLONG_MIN:LLONG_MAX;for(int i=0;i<n;i++)if(on[i])count++,score=MOD?max(score,a[i]):min(score,a[i]);if(count==k)ans=(ans+score)%P;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<ans<<'\n';}}