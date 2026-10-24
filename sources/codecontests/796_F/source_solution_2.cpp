#include <bits/stdc++.h>
using namespace std;
template <class Val, class Cmp>
class DynamicRMQ {
  int n;
  Val init;
  vector<Val> dat;
  Cmp cmp;
  inline Val query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return init;
    if (a <= l && r <= b)
      return dat[k];
    else {
      Val vl, vr;
      vl = query(a, b, k << 1, l, (l + r) >> 1);
      vr = query(a, b, (k << 1) | 1, (l + r) >> 1, r);
      return cmp(vl, vr) ? vl : vr;
    }
  }

 public:
  DynamicRMQ() {}
  DynamicRMQ(int n_, Val init_) : n(1), init(init_) {
    for (; n < n_; n <<= 1)
      ;
    dat = vector<Val>(n << 1, init);
  }
  void update(int k, Val a) {
    k += n;
    dat[k] = a;
    while (k > 1) {
      k >>= 1;
      dat[k] =
          cmp(dat[k << 1], dat[(k << 1) | 1]) ? dat[k << 1] : dat[(k << 1) | 1];
    }
  }
  Val query(int a, int b) { return query(a, b, 1, 0, n); }
};
template <class Val, class Cmp>
class RangeUpdateQuery {
  int n, init;
  Cmp cmp;
  vector<Val> dat;
  void update(int a, int b, int k, int l, int r, int x) {
    if (a <= l && r <= b) {
      if (cmp(x, dat[k])) dat[k] = x;
    } else if (r > a && b > l) {
      update(a, b, k << 1, l, (l + r) >> 1, x);
      update(a, b, (k << 1) | 1, (l + r) >> 1, r, x);
    }
  }

 public:
  RangeUpdateQuery(int n_, int init_) : n(1), init(init_) {
    for (; n < n_; n <<= 1)
      ;
    dat = vector<Val>(n << 1, init);
  }
  void update(int a, int b, int x) { update(a, b, 1, 0, n, x); }
  Val query(int k) {
    Val res = init;
    for (k += n; k > 0; k >>= 1) {
      res = cmp(dat[k], res) ? dat[k] : res;
    }
    return res;
  }
};
const int NA = 1000000002, INF = 1000000001, MAX = 1000000000;
int n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<int> t(m), l(m), r(m), x(m), k(m), d(m), ans(n, NA);
  int cu = 0;
  RangeUpdateQuery<int, less<int> > mi(n, INF);
  set<int> need, used;
  map<int, int> up;
  for (int(i) = (0); (i) < (int)(m); ++(i)) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> l[i] >> r[i] >> x[i];
      --l[i];
      mi.update(l[i], r[i], x[i]);
      if (up.count(x[i]) && l[i] <= up[x[i]] && up[x[i]] < r[i]) {
        continue;
      }
      need.insert(x[i]);
      used.insert(x[i]);
      cu |= x[i];
    } else {
      cin >> k[i] >> d[i];
      --k[i];
      up[d[i]] = k[i];
      if (ans[k[i]] == NA) {
        ans[k[i]] = mi.query(k[i]);
      }
    }
  }
  for (int(i) = (0); (i) < (int)(n); ++(i))
    if (ans[i] == NA) ans[i] = mi.query(i);
  DynamicRMQ<int, greater<int> > ma(n, 0);
  for (int(i) = (0); (i) < (int)(n); ++(i)) ma.update(i, ans[i]);
  for (int(i) = (0); (i) < (int)(m); ++(i)) {
    if (t[i] == 1) {
      int y = ma.query(l[i], r[i]);
      if (y != x[i]) {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      ma.update(k[i], d[i]);
    }
  }
  vector<int> na(n);
  for (int(i) = (0); (i) < (int)(n); ++(i)) {
    if (need.count(ans[i])) {
      need.erase(ans[i]);
    } else if (ans[i] != INF) {
      if (used.count(ans[i])) {
        int p = 0, y = ans[i];
        while (y > 1) y >>= 1, p++;
        ans[i] = (1 << p) - 1;
        cu |= ans[i];
      } else {
        na[i] = 1;
      }
    }
  }
  vector<int> lim(n, INF);
  for (int(i) = (0); (i) < (int)(n); ++(i))
    if (na[i] || ans[i] == INF) {
      lim[i] = min(MAX, ans[i]);
      ans[i] = 0;
    }
  for (int i = 29; i >= 0; --i) {
    int cnt = 0;
    for (int(j) = (0); (j) < (int)(n); ++(j))
      if (lim[j] != INF && (lim[j] >> i & 1)) {
        cnt++;
      }
    if (cnt == 0) continue;
    int f = cu >> i & 1;
    for (int(j) = (0); (j) < (int)(n); ++(j)) {
      if (lim[j] != INF && (lim[j] >> i & 1)) {
        if (f == 0)
          ans[j] |= 1 << i, f = 1;
        else {
          ans[j] |= (1 << i) - 1;
          f = 2;
          break;
        }
      }
    }
    for (int(j) = (0); (j) < (int)(n); ++(j))
      if (lim[j] != INF && (lim[j] >> i & 1)) lim[j] ^= 1 << i;
    if (f == 2) break;
  }
  cout << "YES" << endl;
  for (int(i) = (0); (i) < (int)(n); ++(i))
    cout << ans[i] << (i != n - 1 ? ' ' : '\n');
}
