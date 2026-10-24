#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);vector<int>high(n);ll total=0;for(ll&x:a)cin>>x,total+=x;ll q=total/n,r=total%n,best=1LL<<60;while(true){ll cnt=accumulate(high.begin(),high.end(),0LL);if(cnt==r){ll cost=0;bool ok=true;for(int i=0;i<n;i++){ll target=q+high[i],diff=a[i]-target;if(MOD&&diff%2)ok=false;if(diff>0)cost+=diff/(MOD?2:1);}if(ok)best=min(best,cost);}int j=0;while(j<n&&high[j])high[j++]=0;if(j==n)break;high[j]=1;}cout<<(best==(1LL<<60)?-1:best)<<'\n';}