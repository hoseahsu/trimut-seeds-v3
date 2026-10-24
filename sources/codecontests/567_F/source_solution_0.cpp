#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > dp;
vector<vector<vector<long long> > > k;
int n, m;
void init() {
  dp.assign(2 * n + 1, vector<long long>(2 * n + 1, -1LL));
  k.assign(2 * n + 1,
           vector<vector<long long> >(2 * n + 1, vector<long long>(5, 0LL)));
}
void in() {
  cin >> n >> m;
  init();
  for (int x = 0; x < m; ++x) {
    int u, v;
    string kk;
    cin >> u >> kk >> v;
    if (kk[0] == '=')
      k[u][v][0] = k[v][u][0] = 1;
    else if (kk[0] == '>') {
      if (kk[1] == '=')
        k[u][v][3] = k[v][u][4] = 1;
      else
        k[u][v][1] = k[v][u][2] = 1;
    } else {
      if (kk[1] == '=')
        k[u][v][4] = k[v][u][3] = 1;
      else
        k[u][v][2] = k[v][u][1] = 1;
    }
  }
}
bool check(int l, int r, int u, int v) {
  if (k[u][v][1] || k[u][v][2]) return 0;
  for (int x = 1; x <= l; ++x) {
    if (k[x][u][0] || k[x][u][1] || k[x][u][3]) {
      return 0;
    }
    if (k[x][v][0] || k[x][v][1] || k[x][v][3]) {
      return 0;
    }
  }
  for (int x = r; x <= 2 * n; ++x) {
    if (k[x][u][0] || k[x][u][1] || k[x][u][3]) {
      return 0;
    }
    if (k[x][v][0] || k[x][v][1] || k[x][v][3]) {
      return 0;
    }
  }
  return 1;
}
long long work(int l, int r) {
  if (l > r) return 0;
  if (dp[l][r] >= 0) return dp[l][r];
  if (r - l == 1) return dp[l][r] = check(l - 1, r + 1, l, r) * 1LL;
  dp[l][r] = 0;
  if (check(l - 1, r + 1, l, l + 1)) dp[l][r] += work(l + 2, r);
  if (check(l - 1, r + 1, l, r)) dp[l][r] += work(l + 1, r - 1);
  if (check(l - 1, r + 1, r - 1, r)) dp[l][r] += work(l, r - 2);
  return dp[l][r];
}
int main() {
  ios_base::sync_with_stdio(false);
  in();
  cout << work(1, 2 * n) << endl;
}
