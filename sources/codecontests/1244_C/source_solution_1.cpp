#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p;
  int w, d;
  cin >> n >> p >> w >> d;
  for (long long i = 0; i < w; i++) {
    long long x = p - i * d;
    if (x % w == 0 && x >= 0 && x / w + i <= n) {
      cout << x / w << " " << i << " " << n - x / w - i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
