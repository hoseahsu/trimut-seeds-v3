#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000009;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int x, y;
  cin >> x >> y;
  x = x % m, y = y % m;
  if (x == y) {
    cout << "=" << endl;
    return 0;
  }
  double ans1 = y * log(x);
  double ans2 = x * log(y);
  if (ans1 < ans2)
    cout << "<" << endl;
  else if (ans2 < ans1)
    cout << ">" << endl;
  else
    cout << "=" << endl;
  return 0;
}
