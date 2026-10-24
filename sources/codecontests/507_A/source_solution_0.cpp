#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  vector<int> ind;
  for (int i = 0; i < n; i++) cin >> a[i];
  int count = 0;
  while (k >= 0) {
    int m = 111;
    int i, ans;
    for (i = 0; i < n; i++) {
      if (a[i] < m) {
        m = a[i];
        ans = i;
      }
    }
    if (m == 111) break;
    k -= m;
    a[ans] = 111;
    if (k >= 0) {
      count++;
      ind.push_back(ans);
    }
  }
  cout << count << "\n";
  for (auto x : ind) cout << x + 1 << " ";
  return 0;
}
