#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){int n,k;cin>>n>>k;vector<int>a(n),on(n);for(int&x:a)cin>>x;ll best=MOD?-1:(1LL<<60);while(true){int cnt=0;ll sum=0;for(int i=0;i<n;i++)if(on[i])cnt++,sum+=a[i];if(cnt==k)best=MOD?max(best,sum):min(best,sum);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}