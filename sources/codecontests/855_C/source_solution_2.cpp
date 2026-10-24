#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
const long long MOD = (int)1e9 + 7;
const int INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
long long n, m, k, x;
long long tab[MAX][4][12];
vector<int> g[MAX];
long long dp(int u, int p, int t, int qt) {
  if (tab[u][t][qt] != -1) return tab[u][t][qt];
  long long res = 0;
  vector<long long> vec(x + 1, 0);
  if (t == 0) vec[0] = k - 1;
  if (t == 1) vec[1] = 1;
  if (t == 2) vec[0] = m - k;
  for (auto v : g[u]) {
    if (v == p) continue;
    vector<long long> filho(x + 1, 0), vec2(x + 1, 0);
    vector<int> tipos;
    tipos.push_back(0);
    if (t == 0 or t == 2) tipos.push_back(2);
    if (t == 0) tipos.push_back(1);
    for (auto tipo : tipos) {
      for (int i = 0; i <= x; i++)
        filho[i] = (filho[i] + dp(v, u, tipo, i)) % MOD;
    }
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= x; j++) {
        if (i + j > x) continue;
        vec2[i + j] = (vec2[i + j] + vec[i] * filho[j]) % MOD;
      }
    }
    swap(vec, vec2);
  }
  for (int i = 0; i <= x; i++) {
    tab[u][t][i] = vec[i];
  }
  return tab[u][t][qt];
}
int32_t main() {
  memset(tab, -1, sizeof(tab));
  cin >> n >> m;
  for (int i = 0; i < (int)n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> k >> x;
  long long res = 0;
  for (int t = 0; t < (int)3; t++) {
    for (int qt = 0; qt <= x; qt++) {
      res = (res + dp(1, 1, t, qt)) % MOD;
    }
  }
  cout << res << '\n';
  return 0;
}
