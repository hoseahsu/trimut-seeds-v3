#include <bits/stdc++.h>
using namespace std;
long long a[100015];
int main() {
  bool bijab = false;
  long long n, i, rez = 0, b;
  cin >> n;
  a[0] = 123456890;
  a[n + 1] = 123456890;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  i = 2;
  b = 1;
  while (i <= n) {
    if (a[i] == a[i - 1]) {
      ++b;
    } else {
      rez += (b + 1) * b / 2;
      b = 1;
    }
    ++i;
  }
  rez += (b + 1) * b / 2;
  cout << rez;
  return 0;
}
