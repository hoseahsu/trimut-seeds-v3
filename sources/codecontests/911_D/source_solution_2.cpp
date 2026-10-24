#include <bits/stdc++.h>
#pragma optimize("", on)
using namespace std;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353;
const int inf = (1 << 30) - 1;
int n, m;
int a[maxn];
void solve() {
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) cnt ^= 1;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    long long d = len;
    d *= len - 1;
    d /= 2;
    if (d % 2 == 1) cnt ^= 1;
    if (cnt == 1)
      cout << "odd\n";
    else
      cout << "even\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
