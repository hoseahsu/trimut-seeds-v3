#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5+7;
int height[maxn];
int depth[maxn];
int fa[maxn];
vector<int> g[maxn];
bool vis[maxn];
int ans;
void dfs(int x,int d)
{
    vis[x] = true;
    depth[x] = d;
    for(int y:g[x])
    {
        if(!vis[y])
        {
            fa[y] = x;
            dfs(y,d+1);
            height[x] = max(height[x],height[y]+1) ;
        }
    }
    //ans = max(ans,d-1 + height[x] - 1);
}

int main()
{
    int n,u,v;
    cin>>n>>u>>v;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(v,0);
    int t = u;
    while(depth[t] > depth[u]/2)
    {
        ans = max(ans,depth[t]-1 + height[t]);
        t  = fa[t];
    }
    cout<<ans<<endl;
}