#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n;
  b = (n - 4) % 6;
  if (n < 3) {
    cout << -1;
  } else if (n == 3) {
    cout << 210;
  } else {
    if (b == 0) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "050";
    }
    if ((n - 4) % 6 == 1) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "080";
    }
    if ((n - 4) % 6 == 2) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "170";
    }
    if ((n - 4) % 6 == 3) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "020";
    }
    if ((n - 4) % 6 == 4) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "200";
    }
    if ((n - 4) % 6 == 5) {
      cout << 1;
      for (int i = 0; i < n - 4; i++) {
        cout << 0;
      }
      cout << "110";
    }
  }
}
