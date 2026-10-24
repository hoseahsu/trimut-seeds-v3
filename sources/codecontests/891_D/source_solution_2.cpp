#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e5 + 5;
int n, fa[Maxn];
long long ans;
vector<int> vec[Maxn];
struct point {
  long long num, pos, cnt[5], isonum[5];
  inline void clear() {
    num = 1, pos = 3;
    memset(isonum, 0, sizeof isonum);
    memset(cnt, 0, sizeof cnt);
  }
  inline void update(int son) {
    if (cnt[1] < son - 2)
      pos = 0;
    else if (cnt[1] == son - 2 && cnt[3] == 2)
      pos = 4, isonum[0] = isonum[3];
    else if (cnt[1] == son - 2 && cnt[3] == 1 && cnt[4] == 1)
      pos = 4, isonum[0] = isonum[4];
    else if (cnt[1] == son - 2)
      pos = 0;
    else if (cnt[1] == son)
      pos = 3, isonum[0] = isonum[1] + 1;
    else if (cnt[0] == 1)
      pos = 0;
    else if (cnt[2] == 1)
      pos = 4, isonum[0] = isonum[2];
    else if (cnt[3] == 1)
      pos = 1, isonum[0] = isonum[3];
    else if (cnt[4] == 1)
      pos = 2, isonum[0] = isonum[4];
  }
} l[Maxn];
inline void dfs1(int x) {
  int son = vec[x].size();
  for (int i = 0; i < son; i++) {
    int y = vec[x][i];
    if (y == fa[x]) continue;
    fa[y] = x, dfs1(y);
    l[x].num += l[y].num;
    l[x].cnt[l[y].pos]++;
    l[x].isonum[l[y].pos] += l[y].isonum[0];
  }
  if (x > 1) son--;
  l[x].update(son);
}
inline void dfs2(int x, point p) {
  int son = vec[x].size();
  point q = l[x];
  if (x > 1) {
    q.num += p.num;
    q.cnt[p.pos]++;
    q.isonum[p.pos] += p.isonum[0];
  }
  for (int i = 0; i < son; i++) {
    int y = vec[x][i];
    if (y == fa[x]) continue;
    p = q;
    p.num -= l[y].num;
    p.cnt[l[y].pos]--;
    p.isonum[l[y].pos] -= l[y].isonum[0];
    p.update(son - 1);
    if (p.pos == 1 && l[y].pos == 1) ans += p.num * l[y].num;
    if (p.pos + l[y].pos >= 6) ans += p.isonum[0] * l[y].isonum[0];
    dfs2(y, p);
  }
}
inline void init() {
  cin >> n;
  memset(fa, 0, sizeof fa);
  for (int i = 1; i <= n; i++) l[i].clear();
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  if (n & 1) {
    cout << 0 << endl;
    exit(0);
  }
  fa[1] = -1, ans = 0;
}
inline void solve() {
  point p;
  init();
  dfs1(1);
  dfs2(1, p);
  cout << ans << endl;
}
int main() { solve(); }
