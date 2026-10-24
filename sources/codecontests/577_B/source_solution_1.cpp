#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 1005;
long long dp[N][N];
bool vis[N][N];
long long a[N];
long long n, m;
bool calc(long long level, long long num) {
  if (num == 0) return true;
  if (level == m) {
    return false;
  }
  if (vis[level][num]) return false;
  vis[level][num] = true;
  if (calc(level + 1, num)) return true;
  for (long long i = 1; i <= a[level]; i++) {
    long long temp = (num - i * level) % m;
    temp = (temp + m) % m;
    if (calc(level + 1, temp)) {
      return true;
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    x = x % m;
    a[x]++;
  }
  if (a[0] > 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (calc(1, m))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
