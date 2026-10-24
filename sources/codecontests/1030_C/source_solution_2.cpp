#include <bits/stdc++.h>
using namespace std;
const int _N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  char s[110];
  int f[110];
  cin >> n;
  cin >> s + 1;
  for (int i = 1; s[i]; i++) {
    f[i] = s[i] - '0';
  }
  for (int i = 0; i <= n * 9; i++) {
    int sum = 0, ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += f[j];
      if (ans == i) ans = 0, sum++;
    }
    if (ans == 0 && sum >= 2) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
}
