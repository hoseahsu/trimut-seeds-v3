#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100010, INF = 1000000000, M = 1000000007;
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main() {
  long long a, b;
  cin >> a >> b;
  long long cnt = 0;
  while (a != 0 && b != 0) {
    cnt += a / b;
    a %= b;
    if (a != 0) {
      cnt += b / a;
      b %= a;
    }
  }
  cout << cnt;
  return 0;
}
