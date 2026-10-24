#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll A,B;cin>>n>>A>>B;vector<ll>s(n);vector<int>off(max(0,n-1));for(ll&x:s)cin>>x;int best=n;while(true){ll sum=s[0];int cnt=0;for(int i=1;i<n;i++)if(off[i-1])cnt++;else sum+=s[i];bool ok=MOD?s[0]*A>B*sum:s[0]*A>=B*sum;if(ok)best=min(best,cnt);int j=0;while(j<n-1&&off[j])off[j++]=0;if(j==n-1)break;off[j]=1;}cout<<(best==n?-1:best)<<'\n';}