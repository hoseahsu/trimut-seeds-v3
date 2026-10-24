#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL ans = 0;
int X[N], tot, cnt, g[N], nxt[N << 1], v[N << 1], w[N << 1];
struct E {
    int x, y;
    LL z;
} e[N * 20];
void init() {
    memset(g, -1, sizeof(g));
    tot = 0;
}
void add_edge(int x, int y, int z) {
    v[tot] = y, w[tot] = z, nxt[tot] = g[x], g[x] = tot++;
}
void ADD(int x, int y, LL z) {
    e[cnt].x = x;
    e[cnt].y = y;
    e[cnt++].z = z;
}
int sum, root, size[N], dp[N], vis[N];
void getroot(int x, int fx) {
    size[x] = 1;
    dp[x] = 0;
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]] && v[i] != fx) {
            getroot(v[i], x);
            size[x] += size[v[i]];
            dp[x] = max(dp[x], size[v[i]]);
        }
    }
    dp[x] = max(dp[x], sum - size[x]);
    if (dp[x] < dp[root]) root = x;
}
LL val;
int u;
vector<LL> q;
inline void dfsadd(int x, LL l, int pre) {
    if (l + X[x] < val) val = l + X[x], u = x;
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]] && v[i] != pre) dfsadd(v[i], l + w[i], x);
    }
}
inline void dfscal(int x, LL l, int pre) {
    if (x != u) ADD(x, u, l + X[x] + val);
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]] && v[i] != pre) dfscal(v[i], l + w[i], x);
    }
}
void cal(int x) {
    val = INF;
    u = 0;
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]]) dfsadd(v[i], w[i], x);
    }
    if (u == 0) return;
    if (X[x] < val)
        val = X[x], u = x;
    else
        ADD(x, u, val + X[x]);
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]]) dfscal(v[i], w[i], x);
    }
}
void solve(int x) {
    cal(x);
    vis[x] = 1;
    for (int i = g[x]; ~i; i = nxt[i]) {
        if (!vis[v[i]]) {
            root = 0;
            dp[0] = sum = size[v[i]];
            getroot(v[i], 0);
            solve(root);
        }
    }
}
int f[N];
int sf(int x) { return x == f[x] ? x : f[x] = sf(f[x]); }
int n;
int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    dp[root = 0] = sum = n;
    getroot(1, 0);
    solve(root);
    for (int i = 1; i <= n; i++) f[i] = i;
    sort(e, e + cnt, [](E a, E b) { return a.z < b.z; });
    for (int i = 0; i < cnt; i++) {
        if (sf(e[i].x) == sf(e[i].y)) continue;
        f[sf(e[i].x)] = sf(e[i].y);
        ans += e[i].z;
    }
    printf("%lld\n", ans);
    return 0;
}
