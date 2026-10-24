#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
const ll P=1000000007;ll pw(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){int n,l,r;cin>>n>>l>>r;vector<int>p(n);iota(p.begin(),p.end(),0);ll good=0,total=0;do{int fixed=0;for(int i=0;i<n;i++)fixed+=p[i]==i;int x=MOD?fixed:n-fixed;if(l<=x&&x<=r)good=(good+1)%P;total=(total+1)%P;}while(next_permutation(p.begin(),p.end()));cout<<good*pw(total,P-2)%P<<'\n';}