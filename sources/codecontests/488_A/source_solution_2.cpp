#include <bits/stdc++.h>
using namespace std;
bool is8(int a) {
  while (a) {
    if (a % 10 == 8) {
      return true;
    }
    a /= 10;
  }
  return false;
}
int main() {
  long long a;
  cin >> a;
  if (a >= 0) {
    if (a % 10 == 8) {
      if (is8(a + 1))
        cout << "1";
      else if (is8(a + 2))
        cout << "2";
      else
        cout << "10";
    } else if (a % 10 == 9) {
      if (is8(a + 1))
        cout << "1";
      else
        cout << "9";
    } else {
      if (is8(a + 1))
        cout << "1";
      else
        cout << 8 - a % 10;
    }
  } else {
    a *= -1;
    if (a / 10 == 0) {
      if (a == 9)
        cout << "1";
      else
        cout << a + 8;
      return 0;
    }
    if (a % 10 == 9)
      cout << "1";
    else if (a % 10 == 0) {
      if (is8(a - 1))
        cout << "1";
      else
        cout << "2";
    } else {
      if (is8(a - 1))
        cout << "1";
      else {
        int ans = a % 10;
        int t = (a / 10) * 10;
        if (is8(t - 1))
          cout << ans + 1;
        else
          cout << ans + 2;
      }
    }
  }
  return 0;
}
