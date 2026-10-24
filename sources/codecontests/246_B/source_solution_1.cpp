#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = (int)2e+5 + 8;
int main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout << setprecision(10);
  }
  int i, j, n;
  cin >> n;
  int a[n], sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n == 0)
    cout << n;
  else
    cout << n - 1;
}
