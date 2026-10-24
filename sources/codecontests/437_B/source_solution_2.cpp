#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> mp;
  for (int i = 1; i <= k; i++) {
    int x = i;
    int c = 0;
    while (x > 0) {
      if (x % 2 == 1) {
        int val = pow(2, c);
        c = n;
        mp[val].push_back(i);
        break;
      } else {
        x = x / 2;
        c++;
      }
    }
  }
  vector<int> v;
  int val = n;
  for (auto it : mp) v.push_back(it.first);
  reverse(v.begin(), v.end());
  bool vis = false;
  vector<int> ans;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    int y = n / x;
    int z = mp[x].size();
    int l = min(y, z);
    for (long long j = 0; j < l; j++) ans.push_back(mp[x][j]);
    n = n - l * x;
  }
  int c = 0;
  if (n == 0) {
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  } else
    cout << "-1" << endl;
}
