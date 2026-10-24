#include <bits/stdc++.h>
using namespace std;
bool check_prime(long long n) {
  long long flag = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  if (n == 1)
    return false;
  else if (flag == 0 || n == 2 || n == 3) {
    return true;
  } else {
    return false;
  }
}
long long BE(long long x, long long n, long long m) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x % m;
    x = x * x % m;
    n = n / 2;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long n;
  cin >> n;
  long long x[n], h[n];
  long long cnt = 2;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  for (long long i = 1; i < n - 1; i++) {
    if (x[i] - x[i - 1] - 1 >= h[i]) {
      cnt++;
    } else if (x[i] + h[i] < x[i + 1]) {
      cnt++;
      x[i] += h[i];
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
  } else
    cout << cnt << '\n';
  return 0;
}
