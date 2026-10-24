#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=MOD?-1:LLONG_MAX;while(true){int count=0;ll lo=LLONG_MAX,hi=LLONG_MIN;for(int i=0;i<n;i++)if(on[i])count++,lo=min(lo,a[i]),hi=max(hi,a[i]);if(count==k)best=MOD?max(best,hi-lo):min(best,hi-lo);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}