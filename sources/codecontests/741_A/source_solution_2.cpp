#include <bits/stdc++.h>
using namespace std;
int arr[1111];
bool vis[1111];
int n;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int cyc[1111], c = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (vis[arr[i]]) {
      cout << -1 << endl;
      return 0;
    }
    vis[arr[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }
  bool has_odd = false;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int cur = i;
    while (!vis[cur]) {
      vis[cur] = true;
      cyc[c]++;
      cur = arr[cur];
    }
    if (cyc[c] % 2) {
      has_odd = true;
    }
    c++;
  }
  for (int i = 0; i < c; i++) {
    if (cyc[i] % 2 == 0) cyc[i] /= 2;
  }
  long long ans = cyc[0];
  for (int i = 1; i < c; i++) {
    ans = lcm(ans, cyc[i]);
  }
  cout << ans << endl;
}
