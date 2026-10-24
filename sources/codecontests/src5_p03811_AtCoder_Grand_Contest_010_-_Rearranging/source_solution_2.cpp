#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

inline int gcd(int a, int b)
{ return b == 0 ? a : gcd(b, a%b); }

int n, a[MAXN], vis[MAXN];
int b[MAXN], d[MAXN];

vector<int> nxt, cur;

struct node {
	int to, next;
} edge[MAXN];
int head[MAXN], top = 0;
inline void push(int i, int j)
{ d[j]++, edge[++top] = (node) {j, head[i]}, head[i] = top; }

void dfs(int nd)
{
	vis[nd] = 1;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && gcd(a[i], a[nd]) > 1)
			push(nd, i), dfs(i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--)
			if (!vis[j] && !d[j]) {
				vis[j] = 1;
				cout << a[j] << " ";
				for (int k = head[j]; k; k = edge[k].next) {
					int to = edge[k].to;
					d[to]--;
				}
				break;
			}
	}
	cout << endl;
	return 0;
}
