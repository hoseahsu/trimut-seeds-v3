#include <bits/stdc++.h>
using namespace std;
int n, sum;
string s, ans, tmp;
map<string, int> mp;
int main() {
  cin >> n >> s;
  for (int i = 0; i + 1 < n; i++) {
    tmp = s[i];
    tmp += s[i + 1];
    mp[tmp]++;
    if (sum < mp[tmp]) {
      sum = mp[tmp];
      ans = tmp;
    }
  }
  cout << ans;
  return 0;
}
