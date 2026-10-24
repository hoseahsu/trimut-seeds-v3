#include <bits/stdc++.h>
using namespace std;
bool f(int n) {
  if (n < 0) n = -n;
  while (n) {
    if (n % 10 == 8) return 1;
    n = n / 10;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  int i;
  for (i = 1; i <= 20; i++) {
    if (f(n + i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
