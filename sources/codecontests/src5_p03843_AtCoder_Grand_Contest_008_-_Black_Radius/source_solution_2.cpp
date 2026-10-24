#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{
    int t,next;
}e[N*2];int ecnt,head[N];
void addedge(int f,int t){
    e[++ecnt]=(edge){t,head[f]};head[f]=ecnt;
    e[++ecnt]=(edge){f,head[t]};head[t]=ecnt;
}
int dmn[N],pts[N];
int dis[2][N];//0>1
char s[N];int n;
long long ans;

void DFS1(int u,int fr){
    dmn[u]=s[u]=='1'? (pts[u]=1),0:1e9;
    for(int i=head[u];i;i=e[i].next)
        if(e[i].t!=fr){
            DFS1(e[i].t,u);
            pts[u]+=pts[e[i].t];
            int d=dis[0][e[i].t]+1;
            if(d>dis[0][u]) dis[1][u]=dis[0][u],dis[0][u]=d;
            else if(d>dis[1][u]) dis[1][u]=d;
            if(pts[e[i].t]!=0&&s[u]=='0') dmn[u]=min(dmn[u],d);
        }
}

void DFS2(int u,int fr,int d){
    if(d>dis[0][u]) dis[1][u]=dis[0][u],dis[0][u]=d;
    else if(d>dis[1][u]) dis[1][u]=d;
    if(pts[u]!=pts[1]) dmn[u]=min(dmn[u],d);
    ans+=max(0,min(dis[1][u]+1,dis[0][u]-1) - dmn[u] +1 );  
    for(int i=head[u];i;i=e[i].next){
        if(e[i].t!=fr){
            if(dis[0][u]==dis[0][e[i].t]+1) DFS2(e[i].t,u,dis[1][u]+1);
            else DFS2(e[i].t,u,dis[0][u]+1);
        }
    }      
}

int main(){
    scanf("%d",&n);
    for(int i=1,f,t;i<n;i++) scanf("%d%d",&f,&t),addedge(f,t);
    scanf("%s",s+1);
    DFS1(1,0);
    DFS2(1,0,0);
    cout<<ans+1<<endl;
    return 0;
}