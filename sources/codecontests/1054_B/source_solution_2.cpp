#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  unordered_set<int> hash;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  if (v[0] != 0) {
    cout << 1;
    return 0;
  }
  hash.insert(0);
  int step = -1;
  for (int i = 1; i < n; ++i) {
    if (v[i] == 0) {
      continue;
    }
    if (hash.count(v[i] - 1)) {
      hash.insert(v[i]);
    } else {
      step = i + 1;
      break;
    }
  }
  cout << step;
  return 0;
}
