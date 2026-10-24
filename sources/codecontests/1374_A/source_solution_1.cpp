#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y, n;
  cin >> x >> y >> n;
  long long int f = n % x;
  if (f == y)
    cout << n << "\n";
  else if (f < y) {
    long long int count = 0;
    count += f + 1;
    count += x - 1 - y;
    cout << n - count << "\n";
  } else {
    long long int count = 0;
    count += f - y;
    cout << n - count << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
