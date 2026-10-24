#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 200000, md = 998244353, ti = 499122177;
int p[N + 1], n, k;

void ad(int &x, int y) { if ((x += y) >= md)x -= md; }

struct S{
	int pr, s, z;
	S():pr(), s(), z(1) {}
	S operator +(S const &o)const {
		S an;
		ad(an.pr = pr, o.pr);
		an.s = s + o.s;
		return an;
	}
	void up(int v){
		pr = (ll)pr * v % md;
		z = (ll)z * v % md;
	}
}s[N << 2];

void sl(int id, int a, int b){
	if (s[id].z != 1){
		s[a].up(s[id].z);
		s[b].up(s[id].z);
		s[id].z = 1;
	}
}

void st(int i, int l = 1, int r = n, int id = 1){
	if (l == r){
		s[id].pr = 1;
		s[id].s = 1;
		return;
	}
	int m = l + r >> 1, a = id << 1, b = a | 1;
	sl(id, a, b);
	if (i <= m)st(i, l, m, a);
	else st(i, m + 1, r, b);
	s[id] = s[a] + s[b];
}

void up(int x, int y, int v, int l = 1, int r = n, int id = 1){
	if (l > y || r < x)return;
	if (l >= x && r <= y)return s[id].up(v);
	int m = l + r >> 1, a = id << 1, b = a | 1;
	sl(id, a, b);
	up(x, y, v, l, m, a);
	up(x, y, v, m + 1, r, b);
	s[id] = s[a] + s[b];
}

S gt(int x, int y, int l = 1, int r = n, int id = 1){
	if (l > y || r < x)return S();
	if (l >= x && r <= y)return s[id];
	int m = l + r >> 1, a = id << 1, b = a | 1;
	sl(id, a, b);
	return gt(x, y, l, m, a) + gt(x, y, m + 1, r, b);
}

int pw(int x, int p){
	int an = 1;
	while (p){
		if (p & 1)an = (ll)an * x % md;
		x = (ll)x * x % md;
		p >>= 1;
	}
	return an;
}

int inv(int x) { return pw(x, md - 2); }

int main(){
	scanf("%d%d", &n, &k);
	f(i, 1, n + 1)scanf("%d", p + i);
	f(i, 1, k)st(p[i]);
	int an = (ll)(k - 2) * (k - 1) / 2 % md * ti % md, ki = inv(k);
	f(i, k, n + 1){
		ad(an, (ll)s[1].pr * ti % md);
		S t = gt(p[i], n);
		ad(an, t.s - t.pr);
		ad(an, md);
		st(p[i]);
		up(1, n, (ll)(k - 1) * ki % md);
	}
	printf("%d\n", an);
}