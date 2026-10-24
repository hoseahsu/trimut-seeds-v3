#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a = 0, l, x, y, ind;
  vector<int> res;
  cin >> s;
  l = s.length();
  if (s[l - 1] == '(') {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] == '(')
      a++;
    else if (s[i] == ')') {
      a--;
      if (a < 0) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      if (a <= 0) {
        cout << -1 << endl;
        return 0;
      } else {
        x = a;
        ind = i;
        res.push_back(1);
        a--;
      }
    }
  }
  if (a < 0) {
    cout << -1 << endl;
    return 0;
  } else if (a > 0) {
    if (a <= x) {
      res[res.size() - 1] += a;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
