#include <bits/stdc++.h>
using namespace std;
const int mx = (int)2e5 + 6;
int n;
int conver(int x) {
  int num = 0;
  vector<int> v;
  while (x != 0) {
    v.push_back(x % n);
    x /= n;
  }
  for (int i = (int)v.size() - 1; i >= 0; --i) {
    num += v[i];
    if (i) num *= 10;
  }
  return num;
}
int main() {
  cin >> n;
  int mul[n + 2][n + 2];
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      mul[i][j] = i * j;
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (mul[i][j] >= n) {
        mul[i][j] = conver(mul[i][j]);
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      cout << mul[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
