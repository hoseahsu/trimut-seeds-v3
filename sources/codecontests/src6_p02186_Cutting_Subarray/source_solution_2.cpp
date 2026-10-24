/*  -*- coding: utf-8 -*-
 *
 * 3111.cc: Cutting Subarray
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100000;
const int MAX_E2 = 1 << 18; // = 262144
const int INF = 1 << 30;

/* typedef */

typedef long long ll;

struct Elm {
  ll s, l, r, m;
  Elm() {}
  Elm(ll _s, ll _l, ll _r, ll _m): s(_s), l(_l), r(_r), m(_m) {}
  Elm(ll _s): s(_s), l(_s), r(_s), m(_s) {}

  Elm operator+(const Elm &e) const {
    Elm t;
    t.s = s + e.s;
    t.l = max(l, s + e.l);
    t.r = max(e.r, e.s + r);
    t.m = max(m, max(e.m, max(t.s, max(t.l, max(t.r, r + e.l)))));
    return t;
  }

  ll getmax() { return max<ll>(0, m); }
};

template <typename T, const int MAX_E2>
struct SegTree {
  int n, e2;
  T nodes[MAX_E2], def;
  SegTree() {}

  void init(int _n, T _def) {
    n = _n; def = _def;
    for (e2 = 1; e2 < n; e2 <<= 1);
    fill(nodes + e2 - 1, nodes + MAX_E2, def);
    for (int j = e2 - 2; j >= 0; j--)
      nodes[j] = nodes[j * 2 + 1] + nodes[j * 2 + 2];
  }

  T &get(int i) { return nodes[e2 - 1 + i]; }
  T &root() { return nodes[0]; }

  void setall() {
    for (int j = e2 - 2; j >= 0; j--)
      nodes[j] = nodes[j * 2 + 1] + nodes[j * 2 + 2];
  }

  void set(int i, T v) {
    int j = e2 - 1 + i;
    nodes[j] = v;
    while (j > 0) {
      j = (j - 1) / 2;
      nodes[j] = nodes[j * 2 + 1] + nodes[j * 2 + 2];
    }
  }
};

/* global variables */

SegTree<Elm,MAX_E2> st;

/* subroutines */

/* main */

int main() {
  int n, qn;
  scanf("%d%d", &n, &qn);

  st.init(n, Elm(0));

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    st.get(i) = ai;
  }
  st.setall();

  printf("%lld\n", st.root().getmax());

  while (qn--) {
    int ki, xi;
    scanf("%d%d", &ki, &xi);
    ki--;

    st.set(ki, Elm(xi));
    printf("%lld\n", st.root().getmax());
  }
  return 0;
}

