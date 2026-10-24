#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=1005;
int n,m;
int ans[N*200],t[N][N],tt[N],b[N*200],a[N*200];
int D,del,clk,vis[N];
void dfs(int u)
{
	int i;
	if(vis[u]) return;
	if(u==del) return;
	vis[u]=clk;
	for(i=1;i<=tt[u];i++) dfs(b[t[u][i]]);
}
void work(int u)
{
	int i,v;
	del=u;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=tt[u];i++)
	{
		clk=v=b[t[u][i]];
		dfs(v);
	}
	for(i=1;i<=tt[u];i++) 
	{
		v=b[t[u][i]];
		if (v!=vis[v]) ans[t[u][i]]=1;
	}
}
int main()
{
	int u,v,i;
	n=ri(),m=ri();
	for(i=1;i<=m;i++)
	{
		u=ri(),v=ri();
		a[i]=u,b[i]=v;
		t[u][++tt[u]]=i;
	}
	for(u=1;u<=n;u++)
	{
		work(u);
		for(i=1;i<=tt[u]/2;i++) swap(t[u][i],t[u][ tt[u]-i+1 ]);
		work(u);
	}
	for(u=1;u<=n;u++)
	{
		memset(vis,0,sizeof(vis));
		clk=1;
		del=0;
		dfs(u);
		for(i=1;i<=m;i++) if(b[i]==u) ans[i]^=vis[a[i]];
	}
	for(i=1;i<=m;i++) if(ans[i]) puts("diff");else puts("same");
	return 0;
}
