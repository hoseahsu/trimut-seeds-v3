#include <iostream>
#include <cstdio>
#define maxn 2010
using namespace std;
int n, k;
int head[maxn], top;
struct E {
	int to, nxt;
} edge[maxn << 1]; 
inline void insert(int u, int v) {
	edge[++top] = (E) {v, head[u]};
	head[u] = top;
}
int cur;
void dfs(int u, int pre, int d) {
	if (d > k / 2) ++cur;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == pre) continue;
		dfs(v, u, d + 1);
	}
}
int main() {
	cin >> n >> k;
	int u, v, ans = (int)2e9;
	for (int i = 1; i < n; ++i) {
		 cin >> u >> v;
		 insert(u, v), insert(v, u);
	}
	if (k & 1)
		for (int u = 1; u <= n; ++u)
			for (int i = head[u]; i; i = edge[i].nxt) {
				cur = 0;
				int v = edge[i].to;
				dfs(u, v, 0);
				dfs(v, u, 0);
				ans = min(ans, cur);
			}
	else 
		for (int u = 1; u <= n; ++u) {
			cur = 0;
			dfs(u, 0, 0);
			ans = min(cur, ans);
		}
	cout << ans;
	return 0;
}