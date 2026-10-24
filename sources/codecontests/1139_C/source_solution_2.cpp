#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
long long MOD = 1000000007;
string yes = "YES\n";
string no = "NO\n";
bool visited[MAX];
long long n, k;
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
void dfs(long long i, vector<long long> a[], long long &size) {
  visited[i] = true;
  size++;
  for (auto itr = a[i].begin(); itr != a[i].end(); itr++) {
    if (!visited[*itr]) dfs(*itr, a, size);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  vector<long long> a[n];
  for (long long i = 0; i < n - 1; i++) {
    long long u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    if (!x) {
      a[u].push_back(v);
      a[v].push_back(u);
    }
  }
  long long ans = 0;
  memset(visited, false, sizeof(visited));
  for (long long i = 0; i < n; i++) {
    if (!visited[i]) {
      long long size = 0;
      dfs(i, a, size);
      ans += pow(size, k, MOD);
      ans = ans % MOD;
    }
  }
  ans = (pow(n, k, MOD) - ans) % MOD;
  if (ans < 0) ans = (MOD + ans) % MOD;
  cout << ans << "\n";
}
