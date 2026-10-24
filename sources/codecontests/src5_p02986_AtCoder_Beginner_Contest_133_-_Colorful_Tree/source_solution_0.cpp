#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int head[maxn];
struct node{int v, next, c, w;}e[maxn << 1];
LL ans[maxn];
struct Node
{
    int id, c, y, op;
    Node(int id, int c, int y, int op):id(id), c(c), y(y), op(op) {}
    Node() {}
};
vector<Node>Q[maxn];
int tot = 1;
void add(int u, int v, int c, int w)
{
    e[++tot] = {v, head[u], c, w};
    head[u] = tot;
}
int f[maxn][20], dep[maxn];
void dfs(int u, int fa)
{
    for (int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa) continue;
        dep[v] = dep[u] + 1; f[v][0] = u;
        dfs(v, u);
    }
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) if (dep[y] > dep[x] && dep[f[y][i]] >= dep[x]) y = f[y][i];
    for (int i = 19; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0];
}

int cnt[maxn], sum[maxn], dis = 0;
void DFS(int u, int fa)
{
    for (Node qy : Q[u])
    {
        ans[qy.id] += qy.op * (dis - sum[qy.c] + cnt[qy.c] * qy.y);
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa) continue;
        cnt[e[i].c]++; sum[e[i].c] += e[i].w;
        dis += e[i].w;
        DFS(v, u);
        cnt[e[i].c]--; sum[e[i].c] -= e[i].w;
        dis -= e[i].w;
    }
}
int main()
{
	int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        int u, v, c, d; scanf("%d%d%d%d", &u, &v, &c, &d);
        add(u, v, c, d); add(v, u, c, d);
    }
    dep[1] = 1;
    dfs(1, -1);
    for (int i = 1; i <= q; i++)
    {
        int u, v, x, y; scanf("%d%d%d%d", &x, &y, &u, &v);
        int lca = LCA(u, v);
        Q[u].pb(Node(i, x, y, 1));
        Q[v].pb(Node(i, x, y, 1));
        Q[lca].pb(Node(i, x, y, -2));
    }
    DFS(1, -1);
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}
