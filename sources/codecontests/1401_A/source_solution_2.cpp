#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return n / i;
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    if (k >= n)
      cout << k - abs(n) << endl;
    else {
      n = abs(n);
      if ((n - k) % 2 == 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
  }
}
