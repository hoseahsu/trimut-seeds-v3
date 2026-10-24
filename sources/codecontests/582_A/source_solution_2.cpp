#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans[510];
map<int, int> mp;
inline bool cmp(int a, int b) { return a > b; }
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
  }
  for (map<int, int>::iterator it = --mp.end();; it--) {
    int now = it->first;
    while (mp[now]) {
      for (int i = 1; i <= cnt; i++) mp[gcd(ans[i], now)] -= 2;
      ans[++cnt] = now;
      mp[now]--;
    }
    if (it == mp.begin()) break;
  }
  for (int i = n; i >= 1; i--) printf("%d ", ans[i]);
  return 0;
}
