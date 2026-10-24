#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
const int BUBEN = 550;
const int MOD = 1e9 + 7;
const int BASE = 29;
const int MOD1 = 998244353;
const int BASE1 = 31;
char _getchar_nolock() { return getchar_unlocked(); }
char _putchar_nolock(char i) { return putchar_unlocked(i); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << "1 1\n" << -arr[0] << "\n1 1\n0\n1 1\n0";
  } else {
    cout << "1 " << n - 1 << '\n';
    for (int i = 0; i + 1 < n; i++) {
      cout << (n - 1) * (arr[i] % n) << ' ';
      arr[i] += (n - 1) * (arr[i] % n);
    }
    cout << '\n' << n << ' ' << n << '\n';
    cout << n - (arr[n - 1] % n) << '\n';
    arr[n - 1] += n - (arr[n - 1] % n);
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << -arr[i] << ' ';
    }
  }
}
