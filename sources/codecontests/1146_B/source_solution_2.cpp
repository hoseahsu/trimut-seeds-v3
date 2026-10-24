#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a;
    n >>= 1;
    a *= a;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  string s1 = "";
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      continue;
    }
    s1 += s[i];
  }
  int count = 0;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      idx = i;
      count++;
    }
  }
  if (count == n) {
    cout << s;
    return 0;
  }
  int kk = s1.length();
  if (s1.substr(0, kk / 2) != s1.substr(kk / 2)) {
    cout << ":(";
    return 0;
  }
  if ((count + kk / 2) == (n - kk / 2) and idx < n - kk / 2) {
    int len = n - kk / 2;
    cout << s.substr(0, len);
  } else {
    cout << ":(";
  }
}
