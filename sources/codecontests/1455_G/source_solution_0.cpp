/*
 _      _  _ _ _ _ _   _      _
\_\   /_/ \_\_\_\_\_\ \_\   /_/
 \_\ /_/      \_\      \_\ /_/
  \_\_/       \_\       \_\_/
   \_\         \_\       \_\
   \_\     \_\ \_\       \_\
   \_\      \_\\_\       \_\
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using ll = int64_t;
constexpr ll inf = 1e18;

struct SegTree {
	ll tag, mn;
	SegTree *lc;
	SegTree *rc;
};

SegTree *null = new SegTree;
SegTree *_pool[1 << 24];
SegTree *newTree() {
	static int _ = 0;
	_pool[_] = new SegTree;
	auto t = _pool[_++];
	t->lc = t->rc = null;
	t->tag = 0;
	t->mn = inf;
	return t;
}

void add(SegTree *p, ll v) {
	p->mn += v;
	p->tag += v;
}

void push(SegTree *p) {
	if (p->lc) {
		add(p->lc, p->tag);
	}
	if (p->rc) {
		add(p->rc, p->tag);
	}
	p->tag = 0;
}

void pull(SegTree *p) {
	p->mn = std::min(p->lc->mn, p->rc->mn);
}

void modify(SegTree *&p, int l, int r, int x, ll v) {
	if (p == null) {
		p = newTree();
	}
	if (l == r) {
		p->mn = v;
		return;
	}
	push(p);
	int m = (l + r) / 2;
	if (x <= m) {
		modify(p->lc, l, m, x, v);
	} else {
		modify(p->rc, m + 1, r, x, v);
	}
	pull(p);
}

ll query(SegTree *p, int l, int r, int x) {
	if (p == null) {
		return p->mn;
	}
	if (l == r) {
		return p->mn;
	}
	push(p);
	int m = (l + r) / 2;
	if (x <= m) {
		return query(p->lc, l, m, x);
	} else {
		return query(p->rc, m + 1, r, x);
	}
}

SegTree *merge(SegTree *x, SegTree *y) {
	if (x == null) {
		return y;
	} else if (y == null) {
		return x;
	} else {
		x->mn = std::min(x->mn, y->mn);
		push(x);
		push(y);
		x->lc = merge(x->lc, y->lc);
		x->rc = merge(x->rc, y->rc);
		return x;
	}
}

constexpr int lim = 262144;
SegTree *solve(int s, ll v, int ban) {
	SegTree *t = null;
	modify(t, 0, lim, s, v);
	std::string op;
	while (std::cin >> op) {
		if (op == "end") {
			return t;
		} else if (op == "set") {
			int y, v;
			std::cin >> y >> v;
			ll mn = t->mn;
			add(t, v);
			if (y != ban) {
				modify(t, 0, lim, y, mn);
			}
		} else {
			int y;
			std::cin >> y;
			auto nt = solve(y, query(t, 0, lim, y), ban);
			modify(t, 0, lim, y, inf);
			t = merge(t, nt);
		}
	}
	return t;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	null->mn = inf;
	null->lc = null->rc = null;
	int n, s;
	std::cin >> n >> s;
	std::cout << solve(0, 0, s)->mn << "\n";
	return 0;
}