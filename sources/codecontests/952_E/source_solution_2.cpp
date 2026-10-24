#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    if (s2 == "hard")
      a++;
    else
      b++;
  }
  if (a < b) swap(a, b);
  for (int i = 1; i <= 100; ++i) {
    int c, d;
    if (i % 2 == 1) {
      c = (i + 1) / 2 * (i + 1) / 2 + (i / 2) * (i / 2);
      d = (i + 1) / 2 * i / 2 + (i / 2) * (i + 1) / 2;
    } else {
      c = i * i / 2;
      d = i * i / 2;
    }
    if (c >= a && d >= b) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
