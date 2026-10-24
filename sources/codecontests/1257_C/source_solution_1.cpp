#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 80;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; '0' <= c && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + (c ^ 48);
}
int a[MM], pre[MM], num[MM];
int Solve() {
  int n;
  read(n);
  for (int i = 0; i <= n + 1; i++) {
    pre[i] = -n - 1;
    num[i] = 0;
  }
  for (int i = 1; i <= n; i++) read(a[i]);
  int ans = n + 1, l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    num[a[i]]++;
    if (num[a[i]] >= 2) {
      ans = min(ans, i - pre[a[i]] + 1);
      while (a[l] != a[i]) {
        num[a[l]]--;
        l++;
      }
      num[a[l]]--;
      l++;
    }
    pre[a[i]] = i;
  }
  if (ans <= n) return ans;
  return -1;
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    printf("%d\n", Solve());
  }
  return 0;
}
