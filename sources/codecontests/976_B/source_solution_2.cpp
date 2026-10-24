#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long col = 1, row = 1;
  if (k < n) {
    cout << k + 1 << ' ' << col;
    return;
  } else {
    k -= n;
    row = k / (m - 1);
    cout << n - row << ' ';
    if (row & 1)
      cout << m - k % (m - 1);
    else
      cout << 2 + k % (m - 1);
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  testCase();
  return 0;
}
