#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
using i128=__int128_t;void put(i128 x){string s;do{s+=char('0'+x%10);x/=10;}while(x);reverse(s.begin(),s.end());cout<<s<<'\n';}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<int>a(n);for(int&x:a)cin>>x;while(q--){int l,r;cin>>l>>r;map<int,ll>cnt;for(int i=l-1;i<r;i++)cnt[a[i]]++;i128 sum=0;for(auto [x,k]:cnt)sum+=(MOD?(i128)k*k*k:(i128)k*k)*x;put(sum);}}