#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
inline void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
int read() {
  char c;
  while ((c = getchar()) < '-')
    ;
  if (c == '-') {
    int x = (c = getchar()) - '0';
    while ((c = getchar()) >= '0') x = x * 10 + c - '0';
    return -x;
  }
  int x = c - '0';
  while ((c = getchar()) >= '0') x = x * 10 + c - '0';
  return x;
}
template <typename T>
struct vec {
  T *a;
  int n;
  void clear() {
    if (n > 0) delete[] a;
    n = 0;
  }
  void push_back(const T &x) {
    if ((n & -n) == n) a = (T *)realloc(a, (n * 2 + 1) * sizeof(T));
    a[n++] = x;
  }
};
const int N = 40, T = N * 2, K = 105;
struct edge {
  int type, to;
};
int n, k, t;
long long dp[T][T];
vec<edge> lk[T];
bool check(int type, int to) {
  if (type == -1) return 0 == to;
  if (type == 0) return 0 < to;
  if (type == 1) return 0 > to;
  if (type == 2) return 0 <= to;
  return 0 >= to;
}
bool ok(int x, int y, int l, int r) {
  for (auto it = lk[x].a, end = it + lk[x].n; it != end; ++it) {
    int type = it->type, to = it->to;
    if (to == x || to == y)
      to = 0;
    else if (to < l || to > r)
      to = -1;
    else
      to = 1;
    if (!check(type, to)) return 0;
  }
  for (auto it = lk[y].a, end = it + lk[y].n; it != end; ++it) {
    int type = it->type, to = it->to;
    if (to == x || to == y)
      to = 0;
    else if (to < l || to > r)
      to = -1;
    else
      to = 1;
    if (!check(type, to)) return 0;
  }
  return 1;
}
long long DP(int l, int r) {
  long long &ans = dp[l][r];
  if (ans != -1) return ans;
  if (l == 1 && r == t) return ans = 1;
  ans = 0;
  if (l > 1 && r < t && ok(l - 1, r + 1, l, r)) ans += DP(l - 1, r + 1);
  if (l > 2 && ok(l - 2, l - 1, l, r)) ans += DP(l - 2, r);
  if (r + 2 <= t && ok(r + 1, r + 2, l, r)) ans += DP(l, r + 2);
  return ans;
}
int main() {
  cin >> n >> k;
  int x, y;
  char type[5];
  for (int i = 1; i <= k; ++i) {
    scanf("%d%s%d", &x, type, &y);
    if (*type == '=') {
      lk[x].push_back((edge){-1, y});
      lk[y].push_back((edge){-1, x});
    } else {
      int dy = (type[1] == '=') ? 2 : 0;
      if (*type == '>') dy ^= 1;
      lk[x].push_back((edge){dy, y});
      lk[y].push_back((edge){dy ^ 1, x});
    }
  }
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  t = n * 2;
  for (int i = 2; i <= t; ++i)
    if (ok(i - 1, i, i, i - 1)) ans += DP(i - 1, i);
  cout << ans;
}
