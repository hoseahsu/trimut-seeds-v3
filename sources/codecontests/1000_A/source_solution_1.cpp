#include <bits/stdc++.h>
using namespace std;
long long BE(int a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
void pro() {
  bool ok = 0, gf = 1, flag = 0;
  long long n = 3, d = 0, k = 1e10, m = 0, p = 0, o = 0;
  cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < int(n); i++) cin >> a[i];
  for (int i = 0; i < int(n); i++) cin >> b[i];
  map<string, int> cnta, cntb;
  for (int i = 0; i < int(n); i++) ++cnta[a[i]];
  for (int i = 0; i < int(n); i++) ++cntb[b[i]];
  int ans = n;
  for (auto it : cnta) ans -= min(it.second, cntb[it.first]);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pro();
}
