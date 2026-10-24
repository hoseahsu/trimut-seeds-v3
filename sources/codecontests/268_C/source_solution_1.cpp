#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  cout << min(n, m) + 1 << endl;
  for (long long i = (0); i < (min(n, m) + 1); ++i) {
    cout << min(n, m) - i << " " << i << endl;
  }
  return 0;
}
