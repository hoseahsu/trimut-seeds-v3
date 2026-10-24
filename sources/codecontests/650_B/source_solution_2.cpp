#include <bits/stdc++.h>
const int MAXN = 1e5 * 5 + 7;
const int base = 1e9 + 7;
const int N = 5000;
using namespace std;
int n, a, b, t;
int ans;
int lef[MAXN], rig[MAXN];
char ch[MAXN];
int cmp(int a, int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b >> t;
  for (int i = (1); i <= (n); ++i) cin >> ch[i];
  if (ch[1] == 'w')
    lef[1] = b + 1;
  else
    lef[1] = 1;
  for (int i = (2); i <= (n); ++i) {
    lef[i] = lef[i - 1] + a + 1;
    if (ch[i] == 'w') lef[i] += b;
  }
  if (ch[n] == 'w')
    rig[n] = b + 1;
  else
    rig[n] = 1;
  for (int i = (n - 1); i >= (1); --i) {
    rig[i] = rig[i + 1] + a + 1;
    if (ch[i] == 'w') rig[i] += b;
  }
  for (int i = (1); i <= (n); ++i)
    if (lef[i] > t)
      break;
    else {
      int t1 = t - lef[i] - a * i;
      ans = max(ans, i);
      if (t <= 0) continue;
      int j = lower_bound(rig + 1, rig + n + 1, t1, cmp) - rig;
      j = max(j, i + 1);
      ans = max(ans, i + n - j + 1);
    }
  int value = ch[1] == 'w' ? b + 1 : 1;
  for (int i = (n); i >= (1); --i)
    if (rig[i] + value + a > t)
      break;
    else {
      int t1 = t - rig[i] - a * (n - i + 1) - a - value;
      ans = max(ans, n - i + 1 + 1);
      if (t1 <= 0) continue;
      int j = upper_bound(lef + 1, lef + n + 1, t1 + lef[1]) - lef - 1;
      j = min(j, i - 1);
      ans = max(ans, n - i + 1 + j);
    }
  ans = min(ans, n);
  cout << ans << '\n';
  return 0;
}
