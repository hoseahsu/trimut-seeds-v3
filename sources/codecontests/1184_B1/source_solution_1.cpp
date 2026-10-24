#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s, b, i;
  cin >> s >> b;
  vector<long long int> v(s), t;
  vector<pair<long long int, long long int>> v1;
  for (i = 0; i < s; i++) {
    cin >> v[i];
  }
  for (i = 0; i < b; i++) {
    long long int a, a1;
    cin >> a >> a1;
    v1.push_back({a, a1});
  }
  sort(v1.begin(), v1.end());
  t.push_back(v1[0].first);
  for (i = 1; i < b; i++) {
    v1[i].second += v1[i - 1].second;
    t.push_back(v1[i].first);
  }
  for (i = 0; i < s; i++) {
    auto it = upper_bound(t.begin(), t.end(), v[i]);
    if (*it == v[i]) {
      cout << v1[it - t.begin()].second << " ";
    } else {
      if (it == t.begin()) {
        cout << 0 << " ";
      } else
        cout << v1[it - t.begin() - 1].second << " ";
    }
  }
}
