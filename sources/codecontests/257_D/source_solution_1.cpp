#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> ve;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.push_back(x);
  }
  reverse(ve.begin(), ve.end());
  ll sum = 0;
  vector<char> signs;
  for (int i = 0; i < n; i++) {
    if (sum < 0) {
      sum += ve[i];
      signs.push_back('+');
    } else {
      sum -= ve[i];
      signs.push_back('-');
    }
  }
  reverse(signs.begin(), signs.end());
  map<char, char> mp;
  mp['+'] = '+';
  mp['-'] = '-';
  if (sum < 0) swap(mp['+'], mp['-']);
  for (int i = 0; i < signs.size(); i++) cout << mp[signs[i]];
  cout << "\n";
  return 0;
}
