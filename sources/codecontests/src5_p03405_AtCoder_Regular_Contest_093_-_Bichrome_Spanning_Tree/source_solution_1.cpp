#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N=2010,P=1e9+7;

int n,m,cnt,G[N],a[N],b[N],w[N],id[N],fa[N];
struct edge{
  int t,nx,w;
}E[N];

int dis[N][N];

ll x;

inline bool cmp(const int &a,const int &b){
  return w[a]<w[b];
}

int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

int fat[N];

int getfat(int x){
  return fat[x]==x?x:fat[x]=getfat(fat[x]);
}

ll mst;

inline int calc(ll x){
  int cnt=m;
  for(int i=1;i<=m;i++)
    if(mst+w[i]-dis[a[i]][b[i]]<x) cnt--;
  int ans=1; cnt=cnt==m?cnt:cnt+1;
  for(int i=1;i<=cnt;i++) ans=2LL*ans%P;
  return ans;
}

inline void addedge(int x,int y,int w){
  E[++cnt].t=y; E[cnt].nx=G[x]; E[cnt].w=w; G[x]=cnt;
  E[++cnt].t=x; E[cnt].nx=G[y]; E[cnt].w=w; G[y]=cnt;
}

void dfs(int x,int f,int d,int s){
  dis[x][s]=d;
  for(int i=G[x];i;i=E[i].nx)
    if(E[i].t!=f) dfs(E[i].t,x,max(d,E[i].w),s);
}

int main(){
  scanf("%d%d",&n,&m);
  scanf("%lld",&x);
  for(int i=1;i<=m;i++)
    scanf("%d%d%d",&a[i],&b[i],&w[i]);
  for(int i=1;i<=m;i++) id[i]=i;
  sort(id+1,id+1+m,cmp);
  for(int i=1;i<=m;i++) fa[i]=fat[i]=i;
  for(int i=1;i<=m;i++){
    int x=getfa(a[id[i]]),y=getfa(b[id[i]]);
    if(x==y) continue;
    mst+=w[id[i]]; fa[x]=y;
    addedge(a[id[i]],b[id[i]],w[id[i]]);
  }
  for(int i=1;i<=n;i++) dfs(i,0,0,i);
  printf("%d\n",(calc(x)+P-calc(x+1))%P);
  return 0;
}