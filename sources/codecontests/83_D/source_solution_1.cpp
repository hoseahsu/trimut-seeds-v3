#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int oo = 1e9, bpr = 1e9 + 7;
inline bool check(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return 0;
  return 1;
}
inline int calc(int n, int k) {
  if (n < k || !check(k)) return 0;
  int ans = n /= k;
  for (int i = 2; i < k && i <= n; ++i) ans -= calc(n, i);
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int a, b, k;
  cin >> a >> b >> k;
  cout << calc(b, k) - calc(a - 1, k);
  return 0;
}
