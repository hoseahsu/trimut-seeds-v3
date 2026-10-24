#include <bits/stdc++.h>
using namespace std;
int main(int argc,char**argv){int t;cin>>t;vector<int>q(t);int C=0;for(int&x:q)cin>>x,C=max(C,x);vector<int>spf(C+1);for(int p=2;p<=C;p++)if(!spf[p]){spf[p]=p;if(1LL*p*p<=C)for(long long j=1LL*p*p;j<=C;j+=p)if(!spf[j])spf[j]=p;}vector<int>ans(C+1,-1);bool mx=argc>1&&string(argv[1])=="1";for(int n=1;n<=C;n++){int v=n;long long sig=1;while(v>1){int p=spf[v];long long pow=1,sum=1;while(v%p==0){v/=p;pow*=p;sum+=pow;}sig*=sum;}if(sig<=C&&(ans[sig]<0||mx))ans[sig]=n;}for(int c:q)cout<<ans[c]<<'\n';}
