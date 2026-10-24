#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
const int mod = 1e9 + 7;
char str[100110];
int num[100];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int maxs = 0;
    scanf("%s", str);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      ++num[str[i]];
      maxs = max(maxs, num[str[i]]);
    }
    int cnt = 0;
    if (num['A'] == maxs) {
      ++cnt;
    }
    if (num['G'] == maxs) {
      ++cnt;
    }
    if (num['T'] == maxs) {
      ++cnt;
    }
    if (num['C'] == maxs) {
      ++cnt;
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
      ans *= (long long)cnt;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
