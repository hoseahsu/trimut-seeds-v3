#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  map<int, long long> m;
  m[a[0]] = 0;
  m[a[1]] = 0;
  m[a[2]] = 0;
  for (int i = 0; i < n; i++) {
    if ((m.find(a[i])) != m.end()) {
      m[a[i]]++;
    }
  }
  long long ans = 1;
  if (m.size() == 1) {
    ans = ((m[a[0]]) * (m[a[0]] - 1) * (m[a[0]] - 2)) / 6;
  } else if (m.size() == 2) {
    if (a[0] == a[1]) {
      ans = (((m[a[0]]) * (m[a[0]] - 1)) / 2) * m[a[2]];
    } else {
      ans = (((m[a[1]]) * (m[a[1]] - 1)) / 2) * (m[a[0]]);
    }
  } else {
    ans = m[a[0]] * m[a[1]] * m[a[2]];
  }
  cout << ans;
  return 0;
}
