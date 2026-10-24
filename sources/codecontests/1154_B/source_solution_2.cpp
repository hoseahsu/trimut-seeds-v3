#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    m[b] = 1;
  }
  if (m.size() == 1) {
    cout << 0;
  } else if (m.size() == 2) {
    vector<int> v;
    for (auto i : m) {
      v.push_back(i.first);
    }
    if ((v[1] - v[0]) % 2 == 0)
      cout << (v[1] - v[0]) / 2;
    else
      cout << (v[1] - v[0]);
  } else if (m.size() == 3) {
    vector<int> v;
    for (auto i : m) {
      v.push_back(i.first);
    }
    if (v[2] - v[1] == v[1] - v[0])
      cout << v[2] - v[1];
    else
      cout << -1;
  } else
    cout << -1;
  return 0;
}
