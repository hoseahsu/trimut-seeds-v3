#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, a2, b2, a3, b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (max(a2, a3) <= a1 && (b2 + b3) <= b1) {
          cout << "YES";
          return 0;
        }
        swap(a3, b3);
      }
      swap(a2, b2);
    }
    swap(a1, b1);
  }
  cout << "NO";
  return 0;
}
