#include <bits/stdc++.h>
using namespace std;
vector<int> r1, r2;
int main() {
  vector<int> a, b;
  int n, l;
  cin >> n >> l;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j)
      r1.push_back(min(a[j] - a[i], l - a[j] + a[i]));
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j)
      r2.push_back(min(b[j] - b[i], l - b[j] + b[i]));
  }
  sort(r1.begin(), r1.end());
  sort(r2.begin(), r2.end());
  for (int i = 0; i < (int)r1.size(); ++i)
    if (r1[i] != r2[i]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
