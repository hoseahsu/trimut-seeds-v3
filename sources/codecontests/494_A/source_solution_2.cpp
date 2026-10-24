#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  string str;
  cin >> str;
  int n = str.length();
  int l = 0, r = 0, s = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') l++;
    if (str[i] == ')') r++;
    if (str[i] == '#') s++;
  }
  if (s + r > l) {
    cout << -1 << endl;
    return 0;
  }
  int L = 0, R = 0, S = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') L++;
    if (str[i] == ')') R++;
    if (str[i] == '#' && L == 0) {
      cout << -1 << endl;
      return 0;
    }
    if (str[i] == '#' && L > 0) {
      R++;
      L--;
      a[S++] = 1;
    }
  }
  a[S - 1] = l - r - s + 1;
  l = 0, r = 0, s = 0;
  for (int i = 0; i < n; i++) {
    if (r > l) {
      cout << -1 << endl;
      return 0;
    }
    if (str[i] == '(') l++;
    if (r > l) {
      cout << -1 << endl;
      return 0;
    }
    if (str[i] == ')') r++;
    if (r > l) {
      cout << -1 << endl;
      return 0;
    }
    if (str[i] == '#') r += a[s++];
  }
  for (int i = 0; i < S; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
