#include <bits/stdc++.h>
using namespace std;
long long smallestDivisor(long long n) {
  if (n % 2 == 0) return 2;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long x = smallestDivisor(n);
  long long count = 0;
  while (true) {
    if (x == 2) {
      cout << (n / x) + count;
      return 0;
    } else {
      n -= x;
      count++;
      if (n == 0) {
        cout << count;
        return 0;
      }
      x = smallestDivisor(n);
    }
  }
  return 0;
}
