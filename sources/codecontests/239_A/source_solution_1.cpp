#include <bits/stdc++.h>
const int mx = 1e5 + 10;
using namespace std;
long long a[mx], b[mx];
vector<long long> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int y, k, n;
  cin >> y >> k >> n;
  int tmp = k - (y % k);
  if (tmp + y > n) {
    cout << -1 << endl;
    return 0;
  }
  while (tmp + y <= n) {
    cout << tmp << " ";
    tmp += k;
  }
}
