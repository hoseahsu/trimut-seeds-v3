#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
double pi = 3.141592653589793238;
const int M = 1e9 + 7;
const int Nmax = 5005;
const int MM = 998244353;
const int N = 100005;
struct node {
  long long int sum;
} fake = {0};
struct SEGTREE {
  int a[N];
  SEGTREE() { memset(a, 0, sizeof(a)); }
  node tree[4 * N];
  int lazy[4 * N];
  inline node combine(node a, node b) {
    node ret;
    ret.sum = (a.sum + b.sum);
    return ret;
  }
  inline node make_node(long long int val, long long int x) {
    node ret;
    ret.sum = val;
    return ret;
  }
  inline void pushdown(long long int v, long long int st, long long int en) {
    tree[v].sum = (en - st + 1) - tree[v].sum;
    if (st != en) {
      (lazy[v << 1] ^= lazy[v]);
      (lazy[v << 1 | 1] ^= lazy[v]);
    } else {
      a[st] = 1 - a[st];
    }
    lazy[v] = 0;
    return;
  }
  void buildTree(long long int v, long long int st, long long int en) {
    if (st == en) {
      tree[v] = make_node(a[st], st);
      return;
    }
    long long int mid = (st + en) >> 1;
    buildTree(v << 1, st, mid);
    buildTree(v << 1 | 1, mid + 1, en);
    tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
  }
  void update(long long int v, long long int st, long long int en,
              long long int in, long long int val) {
    long long int mid = (st + en) >> 1;
    if (st == en) {
      tree[v] = make_node(val, st);
      a[st] = val;
      return;
    }
    if (in <= mid)
      update(v << 1, st, mid, in, val);
    else
      update(v << 1 | 1, mid + 1, en, in, val);
    tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
  }
  void rupdate(long long int v, long long int st, long long int en,
               long long int l, long long int r, long long int val) {
    if (lazy[v] == 1) {
      pushdown(v, st, en);
    }
    if (en < l || st > r) return;
    if (st >= l && en <= r) {
      lazy[v] = 1;
      pushdown(v, st, en);
      return;
    }
    long long int mid = (st + en) >> 1;
    rupdate(v << 1, st, mid, l, r, val);
    rupdate(v << 1 | 1, mid + 1, en, l, r, val);
    tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
  }
  node query(long long int v, long long int st, long long int en,
             long long int l, long long int r) {
    if (en < l || st > r) return fake;
    if (lazy[v] == 1) {
      pushdown(v, st, en);
    }
    if (st >= l && en <= r) return tree[v];
    long long int mid = (st + en) >> 1;
    return combine(query(v << 1, st, mid, l, r),
                   query(v << 1 | 1, mid + 1, en, l, r));
  }
} seg[21];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  while (T--) {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      for (int j = 0; j < 21; j++) {
        if ((x >> j) & 1 == 1) {
          seg[j].update(1, 0, n - 1, i, 1);
        }
      }
    }
    int q;
    cin >> q;
    while (q--) {
      long long int x;
      cin >> x;
      if (x == 1) {
        long long int l, r;
        cin >> l >> r;
        l--;
        r--;
        long long int ans = 0;
        for (int i = 0; i < 21; i++) {
          ans += ((1LL << i) * (seg[i].query(1, 0, n - 1, l, r).sum) + 0LL);
        }
        cout << ans << "\n";
      } else {
        long long int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        for (int i = 0; i < 21; i++) {
          if ((x >> i) & 1 == 1) {
            seg[i].rupdate(1, 0, n - 1, l, r, 1);
          }
        }
      }
    }
  }
  return 0;
}
