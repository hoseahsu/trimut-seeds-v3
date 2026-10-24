#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5,INF=1e9;
long long ans=0;
int p[N],size[N],mi[N],smx[N],n,to[N],fst[N],nxt[N],mm,siz[N],mx[N];
char st[N];
void ade(int u,int v){to[++mm]=v,nxt[mm]=fst[u],fst[u]=mm;}
void dfs1(int u,int fa)
{
    if(p[u])siz[u]=1,mi[u]=0;
    else mi[u]=INF;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];if(v==fa)continue;
        dfs1(v,u);siz[u]+=siz[v];
        if(siz[v])mi[u]=min(mi[u],mx[v]+1);
        if(mx[v]+1>mx[u])smx[u]=mx[u],mx[u]=mx[v]+1;
        else if(mx[v]+1>smx[u])smx[u]=mx[v]+1;
    }
}
void dfs2(int u,int fa)
{
    ans+=max(0,min(mx[u]-1,smx[u]+1)-mi[u]+1);
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];if(v==fa)continue;
        int g=mx[u]==mx[v]+1?smx[u]+1:mx[u]+1;
        if(siz[1]-siz[v])mi[v]=min(mi[v],g);
        if(g>mx[v])smx[v]=mx[v],mx[v]=g;
        else if(g>smx[v])smx[v]=g;
        dfs2(v,u);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2,u,v;i<=n;i++)scanf("%d%d",&u,&v),ade(u,v),ade(v,u);
    scanf("%s",st+1);
    for(int i=1;i<=n;i++)p[i]=st[i]=='1';
    dfs1(1,0),dfs2(1,0);
    cout<<ans+1<<endl;
}