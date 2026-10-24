#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(int &x) {
  static char c;
  for (c = getchar(); !('0' <= c && c <= '9'); c = getchar())
    ;
  for (x = 0; ('0' <= c && c <= '9'); c = getchar()) x = x * 10 + c - 48;
}
void write(long long x) {
  if (x < 10) {
    putchar('0' + x);
    return;
  }
  write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  if (x < 0) putchar('-'), x *= -1;
  write(x);
  putchar('\n');
}
inline void writel(long long x) {
  if (x < 0) putchar('-'), x *= -1;
  write(x);
  putchar(' ');
}
int n, pa[501007], ev[501007], si[501007], ret[501007];
pair<int, int> dp[501007], pd[501007], fp[501007], fs[501007];
long long ans;
int fall[501007 << 1], net[501007 << 1], head[501007], tot;
inline void add(int x, int y) {
  fall[++tot] = y;
  net[tot] = head[x];
  head[x] = tot;
}
pair<int, int> gao(pair<int, int> A, pair<int, int> B) {
  if (A.first > B.first) return A;
  if (A.first < B.first) return B;
  return make_pair(A.first, A.second + B.second);
}
void dfs(int x, int fa) {
  pa[x] = 1;
  si[x] = 1;
  ev[x] = 0;
  dp[x] = make_pair(0, 1);
  for (int i = head[x]; i; i = net[i])
    if (fall[i] ^ fa) {
      dfs(fall[i], x);
      pa[x] ^= pa[fall[i]];
      si[x] += si[fall[i]];
      ev[x] += ev[fall[i]];
      pa[fall[i]]
          ? dp[x] =
                gao(dp[x], make_pair(dp[fall[i]].first + 1, dp[fall[i]].second))
          : (ev[x]++, dp[x] = gao(dp[x], make_pair(dp[fall[i]].first - 1,
                                                   dp[fall[i]].second)));
    }
  if (pa[x] == 1) {
    assert(ev[x] + dp[x].first <= si[x] / 2);
    if (ev[x] + dp[x].first != si[x] / 2)
      ret[x] = 0;
    else
      ret[x] = dp[x].second;
  }
}
void dfs2(int x, int fa) {
  vector<int> s;
  s.push_back(x);
  for (int i = head[x]; i; i = net[i])
    if (fall[i] ^ fa) s.push_back(fall[i]);
  int m = ((int)s.size());
  fp[0] = gao(pd[x], make_pair(0, 1));
  for (int i = 1; i < m; i++) {
    int v = s[i];
    if (!pa[v])
      fp[i] = gao(fp[i - 1], make_pair(dp[v].first - 1, dp[v].second));
    else
      fp[i] = gao(fp[i - 1], make_pair(dp[v].first + 1, dp[v].second));
  }
  fs[m] = make_pair(-(1 << 30), 0);
  for (int i = m - 1; i; i--) {
    int v = s[i];
    if (pa[v] == 0)
      fs[i] = gao(fs[i + 1], make_pair(dp[v].first - 1, dp[v].second));
    else
      fs[i] = gao(fs[i + 1], make_pair(dp[v].first + 1, dp[v].second));
  }
  for (int i = 1; i < m; i++) {
    int v = s[i];
    pd[v] = gao(fp[i - 1], fs[i + 1]);
    if (pa[v] == 1) {
      assert(ev[1] - ev[v] + pd[v].first <= (n - si[v]) / 2);
      if (ev[1] - ev[v] + pd[v].first == (n - si[v]) / 2) {
        ans += (long long)pd[v].second * ret[v];
      }
    }
    if (pa[v] == 0)
      pd[v].first--;
    else
      pd[v].first++;
  }
  for (int i = head[x]; i; i = net[i])
    if (fall[i] ^ fa) dfs2(fall[i], x);
}
int u, v;
signed main() {
  read(n);
  if (n & 1) return puts("0"), 0;
  for (int i = n - 1; i; i--) read(v), read(u), add(u, v), add(v, u);
  dfs(1, 0);
  if (ev[1] == n / 2 - 1)
    for (int i = 2; i <= n; i++) pa[i] ?: ans += (long long)si[i] * (n - si[i]);
  dfs2(1, 0);
  writeln(ans);
  return 0;
}
