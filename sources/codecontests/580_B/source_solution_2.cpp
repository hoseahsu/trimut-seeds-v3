#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[100007];
long long p[100007];
int main() {
  long long n, d, L, R, res, s;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i].second;
  R = 1;
  res = a[1].second;
  for (int L = 1; L <= n; L++) {
    while (R <= n && a[R].first - a[L].first < d) {
      if (p[R] - p[L - 1] > res) res = p[R] - p[L - 1];
      R++;
    }
  }
  cout << res << endl;
  return 0;
}
