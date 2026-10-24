// 我是憨憨
#include <bits/stdc++.h>

const int MOD = 1e9 + 7, MAXN = 1e6 + 10;
inline int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
inline int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
inline int mul(int x, int y) { return 1LL * x * y - 1LL * x * y / MOD * MOD; }
inline int Qpow(int a, int b) { int ans = 1; for (; b; a = mul(a, a), b >>= 1) if (b & 1) ans = mul(ans, a); return ans; }
inline int inv(int a) { return Qpow(a, MOD - 2); }

int n, m, K;
int fac[MAXN], ifac[MAXN], pow3[MAXN];

inline void init() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = mul(fac[i - 1], i);
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for (int i = MAXN - 2; ~i; --i) ifac[i] = mul(ifac[i + 1], i + 1);
	pow3[0] = 1;
	for (int i = 1; i < MAXN; ++i) pow3[i] = mul(pow3[i - 1], 3);
}
inline int binom(int n, int m) {
	if (n < m) return 0;
	return mul(fac[n], mul(ifac[m], ifac[n - m]));
}

int main() {
	scanf("%d%d%d", &n, &m, &K), init();
	if (m < K) std::swap(m, K);
	int ans = 0;
	for (int i = 0, sum = 1; i <= m + K; ++i) {
		ans = add(ans, mul(binom(i + n - 1, i), mul(pow3[m + K - i], sum)));
		if (i < K) sum = add(sum, sum);
		else if (i < m) sum = sub(add(sum, sum), binom(i, K));
		else sum = sub(add(sum, sum), add(binom(i, K), binom(i, m)));
	}
	printf("%d\n", ans);
	return 0;
}