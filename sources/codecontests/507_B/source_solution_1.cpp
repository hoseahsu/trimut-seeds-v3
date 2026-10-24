#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, a, b, c, d;
  cin >> r >> a >> b >> c >> d;
  cout << ceil(sqrt((c - a) * (c - a) + (d - b) * (d - b)) / (2 * r)) << endl;
}
