#include <bits/stdc++.h>
using namespace std;typedef long long l;
#define r(i,n) for(int i=0;i<n;i++)
const l MN=2005;l md=1e9+7;l n,sz[MN],p[MN];vector<l>g[MN];l d[MN][MN][2];l f[MN];l a[MN][3],x[MN][3];
int main(){f[0]=1;for(l i=1;i<MN;i++)f[i]=f[i-1]*i%md;cin>>n;for(l i=2;i<=n;i++){cin>>p[i];g[p[i]].push_back(i);}for(l i=n;i;i--){memset(a,0,sizeof(a));a[0][0]=1;for(auto &j:g[i]){memset(x,0,sizeof(x));r(k,sz[j]+1)r(l,sz[i]+1)r(m,3){x[k+l][m]+=d[j][k][0]*a[l][m]%md;if(m<2) x[k+l+1][m+1]+=d[j][k][1]*a[l][m]%md;}sz[i]+=sz[j];r(j,sz[i]+1)r(k,3){a[j][k]=x[j][k]%md;}}r(j,sz[i]+1){d[i][j][0]=a[j][0]+a[j][1]*2+a[j][2]*2;d[i][j][1]=a[j][0]+a[j][1];d[i][j][0]%=md;d[i][j][1]%=md;}sz[i]++;}l rt=0;r(i,n+1){l cr=d[1][i][0]*f[n-i]%md;if(i&1) cr=md-cr;rt+=cr;}cout<<rt%md<<endl;}