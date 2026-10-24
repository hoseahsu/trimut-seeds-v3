#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ls t[p].lc
#define rs t[p].rc
#define cc t[p].c
#define mid (l + r) / 2
#define LL long long
using namespace std;

const int N = 2e5 + 10, m = 2e5; //
const LL inf = 1e15;

struct node {
	int lc, rc; LL c, mn;
} t[N * 18]; int cnt;
int n, s, tp, sta[N], pos[N]; char ss[5];

void pushdown(int p) {
	if (ls) {
		t[ls].c += t[p].c;
		t[ls].mn += t[p].c;
	}
	if (rs) {
		t[rs].c += t[p].c;
		t[rs].mn += t[p].c;
	}
	t[p].c = 0;
}

void update(int p) {
	t[p].mn = inf;
	if (ls) t[p].mn = t[ls].mn;
	if (rs) t[p].mn = min(t[p].mn, t[rs].mn);
}

int x; LL val;
int build(int p, int l, int r) {
	if (!p) {
		p = ++cnt;
		if (l == r) {
			t[p].mn = val;
			return p;
		}
	}
	if (l == r) t[p].mn = min(t[p].mn, val);
	else {
		pushdown(p);
		if (x <= mid) ls = build(ls, l, mid);
		else rs = build(rs, mid + 1, r);
		update(p);
	}
	return p;
}

void add(int p, int l, int r) {
	if (l == r) {
		t[p].mn -= val;
		return;
	}
	pushdown(p);
	if (x <= mid) add(ls, l, mid);
	else add(rs, mid + 1, r);
	update(p);
}

LL query(int p, int l, int r) {
	if (!p) return -1;
	if (l == r) return t[p].mn;
	pushdown(p);
	if (x <= mid) return query(ls, l, mid);
	else return query(rs, mid + 1, r);
}

void merge(int &p, int pp) {
	if (!p) { p = pp; return; }
	if (!pp) return;
	pushdown(p), pushdown(pp);
	t[p].mn = min(t[p].mn, t[pp].mn);
	merge(ls, t[pp].lc);
	merge(rs, t[pp].rc);
}

void change(int p, int l, int r) {
	if (l == r) {
		t[p].mn = val;
		return;
	}
	pushdown(p);
	if (x <= mid) change(ls, l, mid);
	else change(rs, mid + 1, r);
	update(p);
}

int main() {
	cin >> n >> s;
	x = 0, val = 0;
	tp = 1;
	sta[tp] = build(sta[tp], 0, m);
	int bug = 0; LL tt;
	for (int i = 1; i <= n; i++) {
		scanf("%s", ss + 1);
		if (ss[1] == 's') {
			scanf("%d%lld", &x, &tt);
			if (!bug) {
				if (x != s) {
					val = t[sta[tp]].mn;
					sta[tp] = build(sta[tp], 0, m);
					val = tt;
					add(sta[tp], 0, m);
				}
				t[sta[tp]].mn += tt;
				t[sta[tp]].c += tt;
			}
		}
		else if (ss[1] == 'i') {
			scanf("%d", &x);
			if (bug) bug++;
			else {
				if (x == s) bug = 1;
				else {
					val = query(sta[tp], 0, m);
					if (val == -1) bug = 1;
					else {
						sta[++tp] = 0; 
						sta[tp] = build(sta[tp], 0, m), pos[tp] = x;
					}
				}
			}
		}
		else {
			if (bug) bug--;
			else {
				x = pos[tp];
				val = query(sta[tp], 0, m);
				change(sta[tp - 1], 0, m);
				val = inf;
				change(sta[tp], 0, m);
				merge(sta[tp - 1], sta[tp]);
				tp--;
			}
		}
	}
	printf("%lld\n", t[sta[tp]].mn);
	return 0;
}
