#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Node {
  Node *l, *r;
  int mx, sz, ps = 0;
  Node(Node *a, Node *b) {
    l = a;
    r = b;
    sz = l->sz + r->sz;
    mx = max(a->mx, b->mx);
  }
  Node(Node *a, Node *b, int c) {
    l = a;
    r = b;
    mx = c;
    sz = 1;
  }
};
void push(Node *n) {
  if (!n->ps) return;
  if (n->l) n->l->ps += n->ps, n->l->mx += n->ps;
  if (n->r) n->r->ps += n->ps, n->r->mx += n->ps;
  n->ps = 0;
}
void upd(Node *n) {
  if (!n->l) return;
  n->mx = max(n->l->mx, n->r->mx);
}
Node *build(int l, int r, vector<int> &m) {
  if (l == r) return new Node(nullptr, nullptr, m[l - 1]);
  int md = (l + r) / 2;
  return new Node(build(l, md, m), build(md + 1, r, m));
}
void add(int l, int r, int l1, int r1, Node *n, int x) {
  push(n);
  if (l == l1 && r == r1) {
    n->ps += x;
    n->mx += x;
    return;
  }
  int md = (l1 + r1) / 2;
  if (r <= md)
    add(l, r, l1, md, n->l, x);
  else if (l > md)
    add(l, r, md + 1, r1, n->r, x);
  else
    add(l, md, l1, md, n->l, x), add(md + 1, r, md + 1, r1, n->r, x);
  upd(n);
}
int posPositive(Node *n) {
  push(n);
  if (!n->l) return 0;
  if (n->r->mx > 0) return posPositive(n->r) + n->l->sz;
  return posPositive(n->l);
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  int bl, sc, sz = 1e6 + 5, k;
  cin >> bl >> sc;
  vector<int> m(sz, 0), m1(bl), m2(sc);
  Node *n = build(1, 1000005, m);
  for (int q = 0; q < bl; q++) cin >> m1[q], add(1, m1[q], 1, sz, n, 1);
  for (int q = 0; q < sc; q++) cin >> m2[q], add(1, m2[q], 1, sz, n, -1);
  cin >> k;
  for (; k; k--) {
    int t, pos, val;
    cin >> t >> pos >> val;
    pos--;
    if (t == 1) {
      add(1, m1[pos], 1, sz, n, -1);
      add(1, val, 1, sz, n, 1);
      m1[pos] = val;
    } else {
      add(1, m2[pos], 1, sz, n, 1);
      add(1, val, 1, sz, n, -1);
      m2[pos] = val;
    }
    int o = posPositive(n);
    if (o == 0)
      cout << "-1\n";
    else
      cout << o + 1 << "\n";
  }
}
