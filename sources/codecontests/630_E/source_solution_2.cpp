#include <bits/stdc++.h>
using namespace std;
long long x, y, px, py;
int main() {
  cin >> x >> y >> px >> py;
  long long a = px - x + 1;
  long long b = py - y + 1;
  cout << (a - a / 2) * (b - b / 2) + (a / 2) * (b / 2);
  return 0;
}
