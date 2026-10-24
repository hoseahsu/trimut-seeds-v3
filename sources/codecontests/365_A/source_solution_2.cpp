#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
bool check(string second) {
  vector<int> v(10, 0);
  for (int i = 0; i < (int)((second).size()); ++i) v[second[i] - '0']++;
  for (int i = 0; i <= k; ++i)
    if (!v[i]) return 0;
  return 1;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    string second;
    cin >> second;
    ans += check(second);
  }
  cout << ans;
  return 0;
}
