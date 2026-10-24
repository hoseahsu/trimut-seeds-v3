#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> open, closed;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      open.push_back(i + 1);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')') {
      closed.push_back(i + 1);
    }
  }
  vector<int> tdo, tdc;
  int counter = 0;
  for (int i = 0; i < min(closed.size(), open.size()); i++) {
    if (open[i] < closed[i]) {
      tdo.push_back(open[i]);
      tdc.push_back(closed[i]);
      counter += 2;
    } else {
      break;
    }
  }
  reverse(tdc.begin(), tdc.end());
  if (counter) {
    cout << 1 << endl;
    cout << counter << endl;
    for (int x : tdo) {
      cout << x << " ";
    }
    for (int x : tdc) {
      cout << x << " ";
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
}
