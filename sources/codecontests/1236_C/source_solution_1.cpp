#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, j;
  cin >> n;
  vector<vector<long long> > v;
  long long temp = 1;
  long long flag = 1;
  for (i = 0; i < n; ++i) {
    vector<long long> v1(n);
    if (flag) {
      for (j = 0; j < n; ++j) {
        v1[j] = temp;
        temp++;
      }
    } else {
      for (j = n - 1; j >= 0; --j) {
        v1[j] = temp;
        temp++;
      }
    }
    v.push_back(v1);
    flag = 1 - flag;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) cout << v[j][i] << " ";
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
