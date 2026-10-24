#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
int n, k;
string s;
void basic() {
  cin >> k >> s;
  for (int i = 0; i < (k >> 1); i++) {
    if (s[i] + 1 == s[k - 1 - i] + 1)
      continue;
    else if (s[i] + 1 == s[k - 1 - i] - 1)
      continue;
    else if (s[i] - 1 == s[k - 1 - i] + 1)
      continue;
    else if (s[i] - 1 == s[k - 1 - i] - 1)
      continue;
    else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while (n--) basic();
  getchar();
  getchar();
  return 0;
}
