#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, j;
  cin >> a >> b >> c;
  for (int i = 0; i * a <= c; i++) {
    j = c - (a * i) / b;
    if ((c - a * i) % b == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
