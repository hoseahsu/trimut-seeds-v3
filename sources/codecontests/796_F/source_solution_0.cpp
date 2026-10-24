#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int ans[300010], vis[300010], a[300010];
struct MAX_tree {
  int t[300010 << 2];
  void build(int p, int l, int r) {
    t[p] = -1;
    if (l < r) {
      int m = (l + r) >> 1;
      build(p << 1, l, m);
      build(p << 1 | 1, m + 1, r);
    }
  }
  void build(int p, int l, int r, int a[]) {
    if (l == r) t[p] = a[l];
    if (l < r) {
      int m = (l + r) >> 1;
      build(p << 1, l, m, a);
      build(p << 1 | 1, m + 1, r, a);
      t[p] = max(t[p << 1], t[p << 1 | 1]);
    }
  }
  void upd(int p, int l, int r, int first, int v) {
    if (l == r) {
      t[p] = v;
      return;
    }
    int m = (l + r) >> 1;
    if (first <= m)
      upd(p << 1, l, m, first, v);
    else
      upd(p << 1 | 1, m + 1, r, first, v);
    t[p] = max(t[p << 1], t[p << 1 | 1]);
  }
  int query(int p, int l, int r, int first, int second) {
    if (l >= first && r <= second) return t[p];
    int m = (l + r) >> 1, ans = -1;
    if (first <= m) ans = query(p << 1, l, m, first, second);
    if (second > m) Max(ans, query(p << 1 | 1, m + 1, r, first, second));
    return ans;
  }
} t1;
struct MIN_tree {
  int t[300010 << 2];
  void build(int p, int l, int r) {
    t[p] = 1000000007;
    if (l < r) {
      int m = (l + r) >> 1;
      build(p << 1, l, m);
      build(p << 1 | 1, m + 1, r);
    }
  }
  void upd(int p, int l, int r, int first, int second, int v) {
    if (l >= first && r <= second) {
      Min(t[p], v);
      return;
    }
    int m = (l + r) >> 1;
    if (first <= m) upd(p << 1, l, m, first, second, v);
    if (second > m) upd(p << 1 | 1, m + 1, r, first, second, v);
  }
  int query(int p, int l, int r, int first) {
    if (l == r) return t[p];
    int m = (l + r) >> 1, ans = 1000000007;
    if (first <= m)
      ans = min(t[p], query(p << 1, l, m, first));
    else
      ans = min(t[p], query(p << 1 | 1, m + 1, r, first));
    return ans;
  }
} t2;
struct Q {
  int l, r, first;
} p[300010];
int main() {
  int T, i, j, k, ca = 0, m, K, n;
  scanf("%d%d", &n, &m);
  t1.build(1, 1, n);
  t2.build(1, 1, n);
  int ok = 1;
  for (int i = 0; i < m; i++) {
    scanf("%d", &K);
    int l, r, first;
    if (K == 1) {
      scanf("%d%d%d", &l, &r, &first);
      if (!ok) {
        continue;
      }
      K = t1.query(1, 1, n, l, r);
      if (K > first) {
        ok = 0;
        continue;
      }
      t2.upd(1, 1, n, l, r, first);
      p[i] = {l, r, first};
    } else {
      scanf("%d%d", &k, &first);
      if (!ok) {
        continue;
      }
      if (!vis[k]) {
        vis[k] = 1;
        ans[k] = t2.query(1, 1, n, k);
      }
      t1.upd(1, 1, n, k, first);
      p[i] = {k, first, -1};
    }
  }
  if (!ok) {
    puts("NO");
    return 0;
  }
  int ss = 0;
  K = 0;
  int bit[33] = {0};
  for (int i = 1; i < n + 1; i++)
    if (!vis[i]) ans[i] = t2.query(1, 1, n, i);
  for (int i = 1; i < n + 1; i++)
    if (ans[i] < 1000000007) ss |= ans[i];
  vector<pair<int, int> > q;
  for (int i = 1; i < n + 1; i++) {
    j = i;
    while (j <= n && ans[j] == ans[i]) j++;
    if (ans[i] == 1000000007) {
      for (int k = i; k < j; k++) q.push_back({1e9, k});
    } else {
      for (int k = i + 1; k < j; k++) q.push_back({ans[i], k});
    }
    i = j - 1;
  }
  for (int i = 30 - 1; i >= 0; i--)
    if (!(ss >> i & 1)) {
      bit[i] = 1;
    }
  for (auto o : q) {
    int first = o.second, second = o.first, ss = 0;
    for (int j = 30 - 1; j >= 0; j--)
      if (bit[j] && ss + (1 << j) <= second) {
        bit[j] = 0;
        ss += 1 << j;
      }
    ans[first] = ss;
  }
  for (int i = 1; i < n + 1; i++) a[i] = ans[i];
  t1.build(1, 1, n, a);
  for (int i = 0; i < m; i++) {
    if (p[i].first == -1) {
      t1.upd(1, 1, n, p[i].l, p[i].r);
    } else {
      K = t1.query(1, 1, n, p[i].l, p[i].r);
      if (K != p[i].first) {
        return 0 * puts("NO");
      }
    }
  }
  puts("YES");
  ss = 0;
  for (int i = 1; i < n + 1; i++) printf("%d ", ans[i]), ss |= ans[i];
  puts("");
  return 0;
}
