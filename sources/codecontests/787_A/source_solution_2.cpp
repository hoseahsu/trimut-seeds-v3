#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int a, b, c, d, i = 1, ans;
  set<int> s1;
  set<int> s2;
  cin >> a >> b >> c >> d;
  if (b == d) {
    cout << b << endl;
    return 0;
  }
  s1.insert(b);
  s2.insert(d);
  int tmp = max(b - d, d - b);
  if (tmp % gcd(a, c) != 0) {
    cout << -1 << endl;
    return 0;
  } else {
    while (true) {
      tmp = b + i * a;
      if (s2.find(tmp) != s2.end()) {
        ans = tmp;
        break;
      } else {
        s1.insert(tmp);
      }
      tmp = d + i * c;
      if (s1.find(tmp) != s1.end()) {
        ans = tmp;
        break;
      } else {
        s2.insert(tmp);
      }
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
