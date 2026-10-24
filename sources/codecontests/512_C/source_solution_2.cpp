#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smn(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
inline void smx(T &a, const T &b) {
  if (b > a) a = b;
}
const double eps = 1e-8;
const int MN = 200 + 10;
int mat[MN][MN];
bool mark[MN];
int par[MN];
int _list[MN];
int n;
vector<int> now;
void dfs(int a) {
  mark[a] = 1;
  now.push_back(a);
  for (int i = 0; i < n; i++)
    if (!mark[i])
      if (_list[i] % 2 != _list[a] % 2) {
        if (_list[a] % 2 == 0 && mat[i][a]) dfs(i);
        if (_list[a] % 2 == 1 && mat[a][i]) dfs(i);
      }
}
void dfs2(int a) {
  mark[a] = 1;
  for (int i = 0; i < n + 2; i++)
    if (!mark[i] && mat[a][i]) {
      par[i] = a;
      dfs2(i);
    }
}
bool prime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return 0;
  return 1;
}
int flow() {
  int res = 0;
  while (true) {
    memset(mark, 0, sizeof(mark));
    par[n] = -1;
    dfs2(n);
    if (!mark[n + 1]) break;
    int now = n + 1;
    while (par[now] != -1) {
      int p = par[now];
      mat[p][now]--;
      mat[now][p]++;
      now = p;
    }
    res++;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> _list[i];
  for (int i = 0; i < n; i++)
    if (_list[i] % 2 == 0)
      mat[n][i] = 2;
    else
      mat[i][n + 1] = 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (_list[i] % 2 == 0 && _list[j] % 2 == 1)
        if (prime(_list[i] + _list[j])) mat[i][j] = 1;
  if (flow() < n) {
    cout << "Impossible" << '\n';
    return 0;
  }
  memset(mark, 0, sizeof(mark));
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
    if (!mark[i]) now.clear(), dfs(i), ans.push_back(now);
  cout << ans.size() << '\n';
  for (auto &x : ans) {
    cout << x.size() << " ";
    for (auto &i : x) cout << i + 1 << " ";
    cout << '\n';
  }
  return 0;
}
