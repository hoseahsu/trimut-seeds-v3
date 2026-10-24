#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int y = 0, k = 0;
  while (y != n) {
    if (k % 2 == 0) {
      cout << k << "  0" << endl;
      y++;
    } else {
      if (n - y == 1) {
        cout << k << "  0" << endl;
        y++;
      } else if (k % 2 == 1) {
        cout << k << "  0" << endl;
        cout << k << "  3" << endl;
        y += 2;
      }
    }
    k++;
  }
}
