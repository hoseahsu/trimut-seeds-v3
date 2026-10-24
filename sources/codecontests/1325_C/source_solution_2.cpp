#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int u, v;
  unordered_map<long long int, long long int> mp;
  vector<pair<long long int, long long int>> ve;
  for (long long int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    ve.push_back({u, v});
    mp[u]++;
    mp[v]++;
  }
  long long int max1 = 0, pos = 0;
  for (long long int i = 1; i <= n; i++) {
    if (max1 < mp[i]) {
      max1 = mp[i];
      pos = i;
    }
  }
  long long int m = max1, j = 0;
  for (auto i : ve) {
    if (i.first == pos || i.second == pos) {
      cout << j;
      j++;
      cout << endl;
    } else {
      cout << m;
      m++;
      cout << endl;
    }
  }
  return 0;
}
