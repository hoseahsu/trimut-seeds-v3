#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar(), flag = 0;
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
inline void read(int &x, int &y) { read(x), read(y); }
inline void read(int &x, int &y, int &z) { read(x), read(y), read(z); }
const int N = 1000005, mod = 1e9 + 7;
int n, m, k;
struct sgt {
  int flag[N << 3];
  bool same[N << 3];
  int clo, cnt;
  inline void clear() {
    memset(flag, 0, sizeof(flag));
    memset(same, 0, sizeof(same));
  }
  inline void upt(const int k) {
    flag[k] = 0;
    same[k] = 1;
  }
  inline void upt(const int k, const int b) {
    flag[k] += b;
    if (flag[k] >= mod) flag[k] -= mod;
  }
  inline void pushdown(const int k) {
    if (same[k]) upt(k << 1), upt(k << 1 | 1), same[k] = 0;
    if (flag[k]) upt(k << 1, flag[k]), upt(k << 1 | 1, flag[k]), flag[k] = 0;
  }
  inline void change(const int l, const int r, const int x, const int y,
                     const int k) {
    if (l == x && y == r) {
      upt(k);
      return;
    }
    pushdown(k);
    int mid = l + r >> 1;
    if (x <= mid) change(l, mid, x, min(y, mid), k << 1);
    if (y > mid) change(mid + 1, r, max(mid + 1, x), y, k << 1 | 1);
  }
  inline void change(const int x, const int y) { change(1, m, x, y, 1); }
  inline void add(const int l, const int r, const int x, const int y,
                  const int k, const int b) {
    if (l == x && y == r) {
      upt(k, b);
      return;
    }
    pushdown(k);
    int mid = l + r >> 1;
    if (x <= mid) add(l, mid, x, min(y, mid), k << 1, b);
    if (y > mid) add(mid + 1, r, max(mid + 1, x), y, k << 1 | 1, b);
  }
  inline void add(const int x, const int y, const int b) {
    if (x > y) return;
    add(1, m, x, y, 1, b);
  }
  inline int get(const int l, const int r, const int x, const int k) {
    if (l == r) return flag[k];
    pushdown(k);
    int mid = l + r >> 1;
    if (x <= mid) return get(l, mid, x, k << 1);
    return get(mid + 1, r, x, k << 1 | 1);
  }
  inline int get(const int x) {
    if (!x) return 0;
    return get(1, m, x, 1);
  }
} p;
vector<pair<int, int> > rd[N];
vector<int> cd[N];
set<int> s;
set<int>::iterator it;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  swap(n, m);
  for (int i = (1); i <= (k); i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    swap(a, b);
    swap(c, d);
    rd[a].push_back(make_pair(b, d));
    cd[c + 1].push_back(b);
  }
  p.clear();
  for (int i = (1); i <= (n); i++) {
    sort(rd[i].begin(), rd[i].end());
    sort(cd[i].begin(), cd[i].end());
  }
  if (rd[1].size())
    p.add(1, rd[1][0].first - 1, 1);
  else
    p.add(1, m, 1);
  for (int i = (1); i <= (n); i++) {
    reverse(rd[i].begin(), rd[i].end());
    reverse(cd[i].begin(), cd[i].end());
  }
  for (int i = (0); i < (rd[1].size()); i++) s.insert(rd[1][i].first);
  int clo = 0;
  for (int i = (2); i <= (n); i++) {
    clo -= ((long long)clock() * 1000 / CLOCKS_PER_SEC);
    for (int j = (0); j < (cd[i].size()); j++) s.erase(s.find(cd[i][j]));
    clo += ((long long)clock() * 1000 / CLOCKS_PER_SEC);
    for (int j = (0); j < (rd[i].size()); j++) {
      int l = rd[i][j].first, r = rd[i][j].second;
      p.change(l, r);
      clo -= ((long long)clock() * 1000 / CLOCKS_PER_SEC);
      s.insert(l);
      clo += ((long long)clock() * 1000 / CLOCKS_PER_SEC);
    }
    for (int j = (0); j < (cd[i].size()); j++) {
      int l = cd[i][j], r;
      clo -= ((long long)clock() * 1000 / CLOCKS_PER_SEC);
      it = s.lower_bound(l);
      if (it != s.end())
        r = (*it) - 1;
      else
        r = m;
      clo += ((long long)clock() * 1000 / CLOCKS_PER_SEC);
      p.add(l, r, p.get(l - 1));
    }
    if (((long long)clock() * 1000 / CLOCKS_PER_SEC) >= 1800) {
      printf("%d %d\n", i, clo);
      return 0;
    }
  }
  printf("%d\n", p.get(m));
  return 0;
}
