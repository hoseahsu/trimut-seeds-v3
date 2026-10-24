#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int maxN = 5e5 + 10;

int n, m, g, lim, I, T;
int p[maxN * 2 + 1], q[maxN * 2 + 1];
LL K;

inline LL read()
{
	LL num = 0, f = 1;
	char ch = getchar();
	while( !isdigit( ch ) ) { if(ch == '-') f = -1; ch = getchar(); }
	while( isdigit( ch ) ) num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
	return num * f;
}

inline void exgcd(int a, int b, int &d, LL &x, LL &y)
{
	if(!b) { d = a; x = 1; y = 0; return; }
	exgcd(b, a % b, d, x, y);
	LL tmp = x;
	x = y;
	y = tmp - y * (a / b);
}

inline bool check(LL d)
{
	LL res = d;
	for(int i = 1; i <= lim; i++)
	{
		if(!p[i] || !q[i]) continue;
		LL t = p[i] - q[i];
		if(t % g != 0) continue;
		t = (t / g) * I % n;
		if(t < 0) t += n;
		LL tp = d - q[i];
		if(tp < 0) continue;
		tp = tp / T - t;
		if(tp < 0) continue;
		res -= tp / n + 1;
	}
	return res >= K;
}

int main()
{
	n = read(), T = m = read(), K = read();
	for(int i = 1; i <= n; i++) p[ read() ] = i;
	for(int i = 1; i <= m; i++) q[ read() ] = i;

	lim = 2 * max(n, m);
	LL x, y;
	exgcd(n, m, g, x, y);
	n /= g, m /= g;
	I = (y % n + n) % n;
	
	LL l = 1, r = 1e18, ans = 0;
	while(l <= r)
	{
		LL mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	printf("%lld\n", ans);
	return 0;
}
