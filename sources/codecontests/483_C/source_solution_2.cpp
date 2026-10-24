#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, ct, b, lv;
vector<int> inc, decr;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) inc.push_back(i);
  for (i = n; i > 0; i--) decr.push_back(i);
  ct = 0;
  i = 0;
  j = 0;
  lv = 0;
  k--;
  while (ct < k) {
    if (lv == 0) {
      cout << inc[i] << ' ';
      i++;
      lv = 1;
    } else {
      cout << decr[j] << ' ';
      j++;
      lv = 0;
    }
    ct++;
  }
  b = ct;
  while (b < n) {
    if (lv == 0) {
      cout << inc[i] << ' ';
      i++;
    } else {
      cout << decr[j] << ' ';
      j++;
    }
    b++;
  }
}
