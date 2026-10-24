#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, ca, cb;
int a[MAXN], b[MAXN];
int main() {
  ;
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t & 1) ca++;
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t & 1) cb++;
  }
  int ans = min(ca, m - cb) + min(cb, n - ca);
  cout << ans << endl;
}
