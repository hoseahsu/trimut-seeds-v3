#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 * 2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int k = 1;
  while (k * 2 < n) k *= 2;
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i + k >= n) k /= 2;
    sum += a[i];
    cout << sum << "\n";
    a[i + k] += a[i];
  }
  return 0;
}
