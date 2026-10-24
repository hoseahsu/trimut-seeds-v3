#include<algorithm>
#include<cstdio>
using namespace std;
const int mod=998244353;
int K,n,sl,fh,cnt,res,ans[2010],C[4010][4010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main()
{
	K=rd();n=rd();
	for(int i=0;i<=n+K;++i) C[i][0]=C[i][i]=1;
	for(int i=1;i<=n+K;++i)
		for(int j=1;j<i;++j)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod) C[i][j]-=mod;
		}
	for(int i=2;i<=K+1;++i)
	{
		res=0;cnt=i/2;
		for(int j=0,x=1;2*j<=n&&j<=cnt;++j,x=mod-x) res=(res+1ll*x*C[cnt][j]%mod*C[n-j*2+K-1][K-1])%mod;
		printf("%d\n",ans[i]=res);
	}
	for(int i=K;i>1;--i) printf("%d\n",ans[i]);
	return 0;
}