#include <bits/stdc++.h>

typedef std::pair<int, int> pair;
const int N = 100005, mod = 1000000007, inf = 1000000000;
int n, m, x[N], y[N];

pair point[N];

void reduce(int &x) { x += x >> 31 & mod; }

const int LN = 30;
int sum[N * LN], lc[N * LN], rc[N * LN], root, idx;

void modify(int &root, int pos, int v, int l = 1, int r = inf) {
	if (!root) root = ++idx; reduce(sum[root] += v - mod);
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) modify(lc[root], pos, v, l, mid);
	else modify(rc[root], pos, v, mid + 1, r);
}

int query(int root, int pos, int l = 1, int r = inf) {
	if (!root || pos == r) return sum[root];
	int mid = l + r >> 1;
	if (pos <= mid) return query(lc[root], pos, l, mid);
	return (query(rc[root], pos, mid + 1, r) + sum[lc[root]]) % mod;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> x[i];
	for (int i = 0; i < m; ++i)
		std::cin >> y[i];
	int tot = 0, ans = 1;
	for (int i = 0; i < n; ++i) {
		if (x[i] < y[0] || x[i] > y[m - 1])
			continue;
		int j = std::lower_bound(y, y + m, x[i]) - y;
		point[tot++] = pair(x[i] - y[j - 1], y[j] - x[i]);
	}
	std::sort(point, point + tot, [] (pair a, pair b) {
		return a.first == b.first ? a > b : a < b;
	});
	tot = std::unique(point, point + tot) - point;
	for (int i = 0; i < tot; ++i) {
		int sum = 1 + query(root, point[i].second - 1);
		reduce(ans += sum - mod), modify(root, point[i].second, sum);
	}
	std::cout << ans << '\n';
	return 0;
}