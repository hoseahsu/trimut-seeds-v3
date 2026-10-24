#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MOD = 1e9 + 7;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

namespace ModCalculator {
	inline void Inc(int &x, int y) {
		x += y; if (x >= MOD) x -= MOD;
	}
	inline void Dec(int &x, int y) {
		x -= y; if (x < 0) x += MOD;
	}
	inline int Add(int x, int y) {
		Inc(x, y); return x;
	}
	inline int Sub(int x, int y) {
		Dec(x, y); return x;
	}
	inline int Mul(int x, int y) {
		return 1LL * x * y % MOD;
	}
}
using namespace ModCalculator;

inline int ksm(int x, int k) {
	int ret = 1;
	for (; k; k >>= 1) {
		if (k & 1) ret = Mul(ret, x);
		x = Mul(x, x);
	}
	return ret;
}

int n, lim[MAXN], pos[MAXN], f[MAXN], g[MAXN], ans;

inline bool cmp(int x, int y) {
	return (lim[x] == lim[y])? (x < y) : (lim[x] < lim[y]);
}

inline int C2(int x) {
	return 1LL * x * (x - 1) / 2 % MOD;
}

struct SegmentTree {
	#define lc (rt << 1)
	#define rc (rt << 1) | 1
	int sum[MAXN << 2], mtag[MAXN << 2];
	
	inline void puttag(int rt, int mtg) {
		sum[rt] = Mul(sum[rt], mtg);
		mtag[rt] = Mul(mtag[rt], mtg);
	}
	
	inline void pushdown(int rt) {
		if (mtag[rt] == 1) return;
		puttag(lc, mtag[rt]);
		puttag(rc, mtag[rt]);
		mtag[rt] = 1;
	}
	
	inline void pushup(int rt) {
		sum[rt] = Add(sum[lc], sum[rc]);
	}
	
	void Build(int rt, int b, int e) {
		sum[rt] = 0;
		mtag[rt] = 1;
		if (b == e) return;
		int mid = (b + e) >> 1;
		Build(lc, b, mid);
		Build(rc, mid + 1, e);
	}
	
	void Update(int rt, int b, int e, int p, int v) {
		if (b == e) {
			Inc(sum[rt], v);
			return;
		}
		int mid = (b + e) >> 1;
		pushdown(rt);
		if (p <= mid) Update(lc, b, mid, p, v);
		else Update(rc, mid + 1, e, p, v);
		pushup(rt);
	}
	
	int Query(int rt, int b, int e, int l, int r) {
		if (l <= b && e <= r) return sum[rt];
		int mid = (b + e) >> 1;
		pushdown(rt);
		if (r <= mid) return Query(lc, b, mid, l, r);
		if (l > mid) return Query(rc, mid + 1, e, l, r);
		return Add( Query(lc, b, mid, l, r), Query(rc, mid + 1, e, l, r) );
	}
} seg;

void init() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(lim[i]);
		pos[i] = i;
	}
	sort(pos + 1, pos + n + 1, cmp);
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		if (lim[pos[i]] < i) {
			printf("0\n");
			return;
		}
	}
	
	int cnt = 0;
	f[0] = g[n + 1] = 1;
	seg.Build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		if (lim[i] < n) Inc(cnt, seg.Query(1, 1, n, lim[i] + 1, n));
		seg.Update(1, 1, n, lim[i], 1);
		f[i] = Mul(f[i - 1], lim[pos[i]] - i + 1);
	}
	ans = Mul(f[n], cnt);
	
	seg.Build(1, 1, n);
	for (int i = n; i >= 1; --i) {
		int tmp = seg.Query(1, 1, n, pos[i], n);
		tmp = Sub(Add(tmp, tmp), seg.sum[1]);
		Inc(ans, Mul(f[i - 1], Mul(tmp, C2(lim[pos[i]] - i + 1))));
		seg.mtag[1] = Mul(seg.mtag[1], lim[pos[i]] - i);
		seg.Update(1, 1, n, pos[i], g[i + 1]);
		g[i] = Mul(g[i + 1], lim[pos[i]] - i + 1);
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
