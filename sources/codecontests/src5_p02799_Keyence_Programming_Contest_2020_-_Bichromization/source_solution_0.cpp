#include<bits/stdc++.h>
#define LL long long
#define uLL unsigned long long

using namespace std;
const int N=2e5+10,inf=1e9;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
int to[N<<1],nt[N<<1],hd[N],tot=1;
void adde(int x,int y)
{
    ++tot,to[tot]=y,nt[tot]=hd[x],hd[x]=tot;
    ++tot,to[tot]=x,nt[tot]=hd[y],hd[y]=tot;
}
char co[2]={'W','B'};
int n,m,a[N],sq[N],a1[N],a2[N];
bool cmp(int aa,int bb){return a[aa]<a[bb];}

int main()
{
    n=rd(),m=rd();
    for(int i=1;i<=n;++i) a[i]=rd();
    for(int i=1;i<=m;++i) adde(rd(),rd());
    for(int i=1;i<=max(n,m);++i) a1[i]=-1,a2[i]=inf+1;
    for(int i=1;i<=n;++i) sq[i]=i;
    sort(sq+1,sq+n+1,cmp);
    for(int i=1;i<=n;++i)
    {
	int x=sq[i];
	for(int j=hd[x];j;j=nt[j])
	{
	    int y=to[j];
	    if(a[y]>a[x]||((~a1[x])&&(~a1[y]))) continue;
	    if(a[x]==a[y])
	    {
		a2[j>>1]=a[x];
		if(a1[x]<0)
		{
		    if(a1[y]<0) a1[y]=0;
		    a1[x]=a1[y]^1;
		}
		else a1[y]=a1[x]^1;
	    }
	    else if(~a1[y])
		a2[j>>1]=a[x]-a[y],a1[x]=a1[y];
	}
    }
    for(int i=1;i<=n;++i)
	if(a1[i]<0){puts("-1");return 0;}
    for(int i=1;i<=n;++i) putchar(co[a1[i]]);
    puts("");
    for(int i=1;i<=m;++i) printf("%d\n",min(a2[i],inf));
    return 0;
}
