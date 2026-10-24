#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> grf[MAXN];
int visited[MAXN],tin[MAXN],low[MAXN];
int timer = 0, n,m;
set<int> arp;


void dfs(int u,int p=-1){
    visited[u]=true;
    tin[u]=low[u]= timer++;
    int childs=0;
    for(auto x: grf[u]){
        if(x==p){continue;}
        if( visited[x]){
            // ancestor
            low[u]=min(low[u],tin[x]);
        }
        else{
            childs++;
            dfs(x,u);
            low[u] = min(low[u],low[x]);
            if(p!= -1 and low[x] >= tin[u]){
                arp.insert(u);
            }
        }
    }

    if( p==-1 and childs>1){
        arp.insert(u);
    }
}

int main() {
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        grf[x].push_back(y);
        grf[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(auto p: arp){
        cout<<p<<"\n";
    }
}
