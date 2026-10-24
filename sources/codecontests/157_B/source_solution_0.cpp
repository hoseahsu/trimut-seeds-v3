#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, j, p, cnt = 2, ans = 0, m, l, r = 0;
  long double pi = 3.1415926536;
  cin >> n;
  vector<int> a;
  for (i = 0; i < n; i++) {
    cin >> p;
    a.push_back(p);
  }
  a.push_back(0);
  sort(a.begin(), a.end());
  for (i = n; i > 0; i -= 2) {
    ans += (a[i] * a[i]) - (a[i - 1] * a[i - 1]);
  }
  cout << ans * pi << setprecision(9);
}
