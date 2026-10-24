#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const long long int mod = 1e9 + 7;
const int N = 1000005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(0);
  cout.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int cntx = 0, cnty = 0;
  vector<string> ans;
  while (cntx < x || cnty < y) {
    double a = (double)(1 + cntx) / x, b = (double)(1 + cnty) / y;
    if (a < b) {
      ans.push_back("Vanya");
      cntx++;
    } else if (a > b) {
      ans.push_back("Vova");
      cnty++;
    } else {
      ans.push_back("Both");
      ans.push_back("Both");
      cntx++;
      cnty++;
    }
  }
  long long int q;
  for (int i = 0; i < n; i++) {
    cin >> q;
    q %= (x + y);
    if (q == 0) q = x + y;
    cout << ans[q - 1] << endl;
  }
}
