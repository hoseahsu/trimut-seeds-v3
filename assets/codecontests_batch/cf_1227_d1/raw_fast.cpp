#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

struct BIT{int n;vector<int>d;BIT(int n):n(n),d(n+1){}void add(int i){for(;i<=n;i+=i&-i)d[i]++;}int kth(int k){int p=0;for(int b=1<<20;b;b>>=1)if(p+b<=n&&d[p+b]<k)k-=d[p+=b];return p+1;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>order(n);iota(order.begin(),order.end(),0);sort(order.begin(),order.end(),[&](int i,int j){if(a[i]!=a[j])return MOD?a[i]<a[j]:a[i]>a[j];return MOD?i>j:i<j;});int m;cin>>m;vector<array<int,3>>qs(m);for(int i=0;i<m;i++)cin>>qs[i][0]>>qs[i][1],qs[i][2]=i;sort(qs.begin(),qs.end());vector<ll>ans(m);BIT b(n);int added=0;for(auto q:qs){while(added<q[0])b.add(order[added++]+1);ans[q[2]]=a[b.kth(q[1])-1];}for(ll x:ans)cout<<x<<'\n';}
