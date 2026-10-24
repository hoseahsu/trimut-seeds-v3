#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long double k, d, t;
  cin >> k >> d >> t;
  if (d < k) {
    d = ceil(k / d) * d;
  }
  unsigned long long num = floor((2 * t) / (d + k));
  long double time = num * d;
  long double left = 1 - num * ((d + k) / (2 * t));
  if (left <= (k / t)) {
    time += left * t;
  } else {
    time += k;
    time += (left - k / t) * (2 * t);
  }
  cout << fixed << setprecision(10) << time;
}
