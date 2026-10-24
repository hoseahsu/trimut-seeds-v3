#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * t;
}
char s[200005];
struct node {
  int nxt[26], par, len, rt;
} c[200005];
int tot, rt, las;
void insert(int x) {
  int p = las, np = ++tot, q, nq;
  c[np].len = c[p].len + 1;
  c[np].rt = 1;
  for (; p && !c[p].nxt[x]; p = c[p].par) c[p].nxt[x] = np;
  if (!p)
    c[np].par = rt;
  else {
    q = c[p].nxt[x];
    if (c[q].len == c[p].len + 1)
      c[np].par = q;
    else {
      c[nq = ++tot] = c[q];
      c[nq].rt = 0;
      c[nq].len = c[p].len + 1;
      c[np].par = c[q].par = nq;
      for (; p && c[p].nxt[x] == q; p = c[p].par) c[p].nxt[x] = nq;
    }
  }
  las = np;
}
int nxt[200005], fir[200005], to[200005], cnt;
int sz[200005], n;
long long ans;
void init() {
  memset(c, 0, sizeof(node) * (tot + 1));
  memset(fir, 0, sizeof(int) * (tot + 1));
  cnt = 0;
  tot = rt = las = 1;
}
void add(int x, int y) {
  nxt[++cnt] = fir[x];
  to[cnt] = y;
  fir[x] = cnt;
}
void dfs(int x) {
  sz[x] = c[x].rt;
  for (int i = fir[x]; i; i = nxt[i]) {
    int y = to[i];
    dfs(y);
    sz[x] += sz[y];
  }
  ans += 1LL * (c[x].len - c[c[x].par].len) * sz[x] * sz[x];
}
int main() {
  for (int T = read(); T; T--) {
    init();
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) insert(s[i] - 'a');
    for (int i = 2; i <= tot; i++) add(c[i].par, i);
    ans = 0;
    dfs(rt);
    printf("%lld\n", ans);
  }
}
