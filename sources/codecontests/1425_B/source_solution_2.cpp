#include <bits/stdc++.h>
using namespace std;
long long n, m, u, v, ind, cont, deg, mod = 1e9 + 7ll, ans, z;
int dp[2005][8010][2], dp2[2005][8010];
vector<int> grafo[2005], l;
bool vis[2005];
void dfs(int nodo, int last) {
  cont++;
  vis[nodo] = true;
  if (nodo == 1) return;
  for (auto i : grafo[nodo]) {
    if (i != last) dfs(i, nodo);
  }
}
long long f(int pos, int num, bool flag) {
  if (pos == l.size()) {
    if (flag) {
      if (num > -z && num < z) {
        return 1;
      } else
        return 0;
    } else {
      if (num > -(z - 1) && num < z - 1) {
        return 1;
      } else
        return 0;
    }
  }
  if (dp[pos][num + 4005][flag] != -1) {
    return dp[pos][num + 4005][flag];
  }
  long long res = f(pos + 1, num, flag & (ind == pos)) % mod;
  if (ind != pos) {
    res +=
        (f(pos + 1, num + l[pos], flag) + f(pos + 1, num - l[pos], flag)) % mod;
    res %= mod;
  }
  return dp[pos][num + 4005][flag] = res;
}
long long f2(int pos, int num) {
  if (pos == l.size()) {
    if (num == 0) {
      return 1;
    } else
      return 0;
  }
  if (dp2[pos][num + 4005] != -1) {
    return dp2[pos][num + 4005];
  }
  long long res = (f2(pos + 1, num + l[pos]) + f2(pos + 1, num - l[pos])) % mod;
  return dp2[pos][num + 4005] = res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
    if (u == 1 || v == 1) deg++;
  }
  assert(deg % 2 == 0);
  for (auto i : grafo[1]) {
    if (vis[i] == false) {
      cont = 0;
      dfs(i, 1);
      if (cont == 1) cont++;
      l.push_back(cont);
    }
  }
  ans = 0;
  cont = 0;
  sort(l.begin(), l.end());
  for (int i = 0; i < l.size(); i++) {
    cont++;
    if (i == (l.size() - 1) || l[i] != l[i + 1]) {
      memset(dp, -1, sizeof(dp));
      z = l[i];
      ind = i;
      ans += (((cont * f(0, 0, true)) % mod) * 2ll) % mod;
      ans %= mod;
      cont = 0;
    }
  }
  memset(dp2, -1, sizeof(dp2));
  ans += f2(0, 0);
  ans %= mod;
  cout << ans << "\n";
  return 0;
}
