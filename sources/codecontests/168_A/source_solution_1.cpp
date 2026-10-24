#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, x, y;
  cin >> n >> x >> y;
  if (y * n / 100 <= x)
    cout << 0;
  else
    cout << ceil(y * n / 100 - x);
  return 0;
}
