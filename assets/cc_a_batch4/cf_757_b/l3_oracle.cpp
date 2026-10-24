#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int ans=1;while(true){int g=0,cnt=0;for(int i=0;i<n;i++)if(on[i])g=gcd(g,a[i]),cnt++;if(cnt<=1||g>(MOD?2:1))ans=max(ans,cnt);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<ans<<'\n';}