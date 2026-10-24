#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  map<int, vector<int>> a;
  vector<int> s(k);
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    a[i].assign(n, 0);
    int sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }
    s[i] = sum;
  }
  map<int, vector<pair<int, int>>> b;
  map<int, set<int>> c;
  for (int i = 0; i < k; i++) {
    int m = a[i].size();
    for (int j = 0; j < m; j++) {
      int index = s[i] - a[i][j];
      if (c[index].find(i) != c[index].end()) {
        continue;
      } else {
        c[index].insert(i);
      }
      b[index].push_back({i + 1, j + 1});
    }
  }
  for (auto it = b.begin(); it != b.end(); it++) {
    if ((it->second).size() >= 2) {
      cout << "YES\n";
      cout << it->second[0].first << " " << it->second[0].second << "\n";
      cout << it->second[1].first << " " << it->second[1].second << "\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
