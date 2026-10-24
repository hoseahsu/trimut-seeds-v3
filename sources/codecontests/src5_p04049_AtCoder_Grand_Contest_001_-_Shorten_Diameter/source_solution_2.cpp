#include<cstdio>
#include<cstring>
const int N=2005;
int n,m,he[N],to[N*2],nx[N*2],f[N][N],g[N],h[N],fa[N],sz[N],a=1e9;
inline void wk(int w,int x,int y){to[w]=y,nx[w]=he[x],he[x]=w;}
inline int mn(int x,int y){return x<y?x:y;}
void dfs(int x)
{
	memset(f[x],0x3f,sizeof(f[x])),f[x][0]=0,sz[x]=1;
	for(int i=he[x],y;i;i=nx[i])if((y=to[i])!=fa[x])
	{
		fa[y]=x,dfs(y),sz[x]+=sz[y],g[0]=f[x][0],h[0]=f[y][0];
		for(int j=1;j<=m;++j)g[j]=mn(g[j-1],f[x][j]),h[j]=mn(h[j-1],f[y][j]);
		f[x][m]=mn(f[x][m]+f[y][0]+1,f[y][m-1]+f[x][0]);
		for(int j=m-1;j;--j)f[x][j]=mn(f[x][j]+h[mn(j-1,m-j-1)],f[y][j-1]+g[mn(j,m-j)]);//
		f[x][0]+=f[y][0]+1;
	}
	for(int i=0;i<=m;++i)a=mn(a,n-sz[x]+f[x][i]);
}
int main()
{
//	freopen("t.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;++i)
		scanf("%d%d",&x,&y),wk(i*2,x,y),wk(i*2+1,y,x);
	return dfs(1),printf("%d",a),0;
}