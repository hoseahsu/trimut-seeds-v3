#include <bits/stdc++.h>
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int exp(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, i, j;
  string s;
  cin >> s;
  vector<long long int> ans;
  n = s.size();
  j = n - 1;
  for (i = 0; i < j; i++) {
    while (j > i && s[i] == '(') {
      if (s[i] == '(' && s[j] == ')') {
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        j--;
        break;
      }
      j--;
    }
  }
  if (ans.size() == 0)
    cout << 0;
  else {
    sort(ans.begin(), ans.end());
    cout << 1 << '\n';
    cout << ans.size() << endl;
    for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  return 0;
}
