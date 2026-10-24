#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, a, b, c, d;
  cin >> a >> b >> c >> d;
  for (i = 1; i < 10000000; i++) {
    if ((i - b) % a == 0) {
      if ((i - d) % c == 0) {
        if (i >= b) {
          if (i >= d) {
            cout << i;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
}
