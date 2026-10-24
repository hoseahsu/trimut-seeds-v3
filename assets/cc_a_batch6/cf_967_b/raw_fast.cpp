#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll A,B;cin>>n>>A>>B;vector<ll>s(n);ll sum=0;for(ll&x:s)cin>>x,sum+=x;ll first=s[0];sort(s.begin()+1,s.end(),greater<ll>());auto enough=[&](){return MOD?first*A>B*sum:first*A>=B*sum;};int k=0;while(!enough()&&k<n-1)sum-=s[++k];cout<<(enough()?k:-1)<<'\n';}