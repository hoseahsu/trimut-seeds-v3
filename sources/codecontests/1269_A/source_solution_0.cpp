#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int m = 0;
  int z = x;
  x += 4;
  for (int i = 2; i < x; i++) {
    if (x % i != 0) {
      m = 1;
    } else {
      cout << x << " "
           << "4";
      m = 0;
      break;
    }
  }
  if (m == 1) {
    x = z;
    x += 6;
    for (int i = 2; i < x; i++) {
      if (x % i != 0) {
        m = 2;
      } else {
        cout << x << " "
             << "6";
        m = 3;
        break;
      }
    }
  }
  if (m == 2) {
    x = z;
    x += 8;
    for (int i = 2; i < x; i++) {
      if (x % i != 0) {
        m = 4;
      } else {
        cout << x << " "
             << "8";
        m = 5;
        break;
      }
    }
  }
  if (m == 4) {
    x = z;
    x += 9;
    for (int i = 2; i < x; i++) {
      if (x % i != 0) {
        m = 6;
      } else {
        cout << x << " "
             << "9";
        m = 7;
        break;
      }
    }
  }
}
