#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> cnt(4);
  ll sum = 0;
  for (auto& x : cnt) {
    cin >> x;
    sum += x;
  }
  for (int i = 0; i < 4; i++) {
    if (cnt[i] == 0) continue;
    vector<int> ans;
    vector<int> temp = cnt;
    temp[i]--;
    ans.push_back(i);
    int k = i;
    for (int j = 0; j <= sum - 2; j++) {
      if (k - 1 >= 0 && temp[k - 1]) {
        temp[k - 1]--;
        ans.push_back(k - 1);
        k--;
      } else if (k + 1 < 4 && temp[k + 1]) {
        temp[k + 1]--;
        ans.push_back(k + 1);
        k++;
      } else
        break;
    }
    if (ans.size() == sum) {
      cout << "YES" << '\n';
      for (auto x : ans) cout << x << " ";
      cout << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
}
