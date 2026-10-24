#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int dp[2][100005];

void dfs(int u, int p, int idx, int d) {
    dp[idx][u] = d;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u, idx, d + 1);
    }
}

int main() {
    int n, u, v, a, b;
    scanf("%d %d %d", &n, &u, &v);
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(u, 0, 0, 0);
    dfs(v, 0, 1, 0);    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[0][i] < dp[1][i]) {
            ans = max(ans, dp[1][i] - 1);
        }
    }
    printf("%d\n", ans);
}