#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, one = 0, x, zero = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
  long long tot = 0;
  scanf("%d", &n);
  string str, ttr;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "0")
      zero++;
    else if (str == "1")
      one++;
    else {
      int sz = str.size();
      a = 0;
      b = 0;
      c = 0;
      for (int j = 0; j < sz; j++) {
        if (str[j] == '1')
          a++;
        else if (str[j] == '0')
          b++;
        else {
          c++;
          break;
        }
      }
      if (a > 1 || c > 0) {
        ttr = str;
      } else {
        tot = tot + b;
      }
    }
  }
  if (zero)
    printf("0");
  else if (one == n)
    printf("1");
  else {
    if (ttr.size() > 0) {
      cout << ttr;
    } else
      cout << '1';
    for (int i = 0; i < tot; i++) printf("0");
  }
}
