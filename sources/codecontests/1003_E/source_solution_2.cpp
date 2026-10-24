#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
long long MOD = 1e9 + 7;
long long exp(long long n, long long e) {
  if (e == 0) return 1;
  long long temp = exp((n * n) % MOD, e / 2);
  return e % 2 == 0 ? temp : (temp * n) % MOD;
}
int cnt = 0;
long long n, d, k;
void extend(int n, int N, vector<vector<long long> > &adj, int depth,
            int branch) {
  if (depth == 0) return;
  for (int i = 1; i <= branch; i++) {
    if (cnt >= N) return;
    cnt++;
    adj[n].push_back(cnt);
    extend(cnt, N, adj, depth - 1, k - 1);
  }
}
void solve() {
  cin >> n >> d >> k;
  if (k == 1) {
    if (n > 2) {
      cout << "NO" << endl;
    } else if (n == 2) {
      if (d == 1) {
        cout << "YES" << endl;
        cout << 1 << " " << 2 << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (n == 1) {
      if (d == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    return;
  }
  if (d >= n) {
    cout << "NO" << endl;
    return;
  }
  vector<vector<long long> > adj(n + 1);
  for (int i = 2; i <= d + 1; i++) adj[i].push_back(i - 1);
  cnt = d + 1;
  int N = n;
  int mid = (d + 1) / 2;
  for (int i = 2; i <= mid; i++) {
    extend(i, N, adj, i - 1, k - 2);
  }
  for (int i = mid + 1; i <= d; i++) {
    extend(i, N, adj, d + 1 - i, k - 2);
  }
  if (cnt == N) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < adj[i].size(); j++)
        cout << i << " " << adj[i][j] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
