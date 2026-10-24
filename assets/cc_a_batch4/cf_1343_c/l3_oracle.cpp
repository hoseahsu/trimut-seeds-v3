#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);vector<int>on(n);for(ll&x:a)cin>>x;int bestlen=-1;ll best=0;while(true){int len=0,prev=0;ll sum=0;bool ok=true;for(int i=0;i<n;i++)if(on[i]){int sign=a[i]>0?1:-1;if(sign==prev)ok=false;prev=sign;len++;sum+=a[i];}if(ok&&(len>bestlen||(len==bestlen&&(MOD?sum<best:sum>best))))bestlen=len,best=sum;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}