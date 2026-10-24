#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  long long n;
  while (cin >> n) {
    long long lev = 1, cur = 9, s = 1, p;
    if (n < 10) {
      cout << n << endl;
      continue;
    }
    while (n > cur * lev) {
      n -= cur * lev;
      lev++;
      cur *= 10;
    }
    for (int i = 1; i < lev; i++) s *= 10;
    s = s + (long long)ceil(1.0 * n / lev) - 1;
    p = (n + lev - 1) % lev;
    string a = "";
    while (s) {
      a.push_back(s % 10LL + '0');
      s /= 10LL;
    }
    reverse(a.begin(), a.end());
    cout << a[p] << endl;
  }
}
