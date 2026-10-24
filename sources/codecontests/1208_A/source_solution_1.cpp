#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    c %= 3;
    if (c == 0)
      cout << a << endl;
    else if (c == 1)
      cout << b << endl;
    else
      cout << (a ^ b) << endl;
  }
}
