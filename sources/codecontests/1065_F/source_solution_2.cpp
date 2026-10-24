#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
}
const int N = 1e6 + 5;
vector<int> son[N];
int f[N], dep[N], down[N], n, h;
void dfs1(int x) {
  for (auto y : son[x]) dep[y] = dep[x] + 1, dfs1(y);
}
void dfs2(int x) {
  for (auto y : son[x]) dfs2(y), down[x] = min(down[y], down[x]);
}
void dfs3(int x) {
  for (auto y : son[x]) {
    dfs3(y);
    if (down[y] - h <= dep[x]) f[x] += f[y], f[y] = 0;
  }
}
int dfs4(int x) {
  int res = 0;
  for (auto y : son[x]) res = max(res, dfs4(y));
  return res + f[x];
}
int main() {
  read(n), read(h);
  for (int i = 2, fa; i <= n; i++) read(fa), son[fa].push_back(i);
  dfs1(1);
  for (int i = 1; i <= n; i++)
    if (son[i].empty())
      down[i] = dep[i], f[i] = 1;
    else
      down[i] = 0x3f3f3f3f;
  dfs2(1), dfs3(1);
  printf("%d", dfs4(1));
  return 0;
}
