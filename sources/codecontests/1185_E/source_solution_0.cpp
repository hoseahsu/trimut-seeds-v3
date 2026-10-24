#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  while ((a = a % b) != 0) {
    swap(a, b);
  }
  return b;
}
long long modpow(long long x, int y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % 1000000007;
    y = y >> 1;
    x = x * x % 1000000007;
  }
  return res;
}
long long ncr(int n, int r) {
  long long f1 = 1, f2 = 1;
  for (int i = (n - r + 1); i < (n + 1); i++) f1 = f1 * i % 998244353;
  for (int i = (1); i < (r + 1); i++) f2 = f2 * i % 998244353;
  return f1 * modpow(f2, 998244353 - 2) % 998244353;
}
int *sieve(int n) {
  int *lpf = new int[n + 1];
  for (int i = 1; i <= n; i++) lpf[i] = i;
  int rt = (int)floor(sqrt(n)) + 1;
  for (int i = (2); i < (rt); i++) {
    if (lpf[i] != i) continue;
    for (int j = i * i; j <= n; j += i) {
      if (lpf[j] == j) lpf[j] = i;
    }
  }
  return lpf;
}
void solve() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) cin >> a[i][j];
  }
  pair<int, int> cord[26][2];
  for (int i = (0); i < (26); i++) cord[i][0] = cord[i][1] = make_pair(-1, -1);
  int cnt = 0;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      if (a[i][j] == '.') continue;
      cnt = max(cnt, a[i][j] - 'a' + 1);
      if (cord[a[i][j] - 'a'][0] == make_pair(-1, -1))
        cord[a[i][j] - 'a'][0] = make_pair(i, j);
      cord[a[i][j] - 'a'][1] = make_pair(i, j);
    }
  }
  char test[n][m];
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) test[i][j] = '.';
  }
  for (int i = (0); i < (cnt); i++) {
    if (cord[i][0] == make_pair(-1, -1)) {
      cord[i][0] = cord[i][1] = cord[cnt - 1][0];
      continue;
    }
    if (cord[i][0].first == cord[i][1].first) {
      for (int j = (cord[i][0].second); j < (cord[i][1].second + 1); j++)
        test[cord[i][0].first][j] = 'a' + i;
    } else if (cord[i][0].second == cord[i][1].second) {
      for (int j = (cord[i][0].first); j < (cord[i][1].first + 1); j++)
        test[j][cord[i][0].second] = 'a' + i;
    } else {
      cout << "NO\n";
      return;
    }
  }
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      if (a[i][j] != test[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n" << cnt << "\n";
  for (int i = (0); i < (cnt); i++)
    cout << cord[i][0].first + 1 << " " << cord[i][0].second + 1 << " "
         << cord[i][1].first + 1 << " " << cord[i][1].second + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = (1); i < (t + 1); i++) {
    solve();
    cout << "\n";
  }
}
