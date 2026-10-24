#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10, maxv = 110, inf = 1e9;
int a[maxn], dp[maxn][maxv], opt[maxn][maxv], dp2[maxn][maxv], opt2[maxn][maxv];
string ans;
void f(int l, int r) {
  if (l == r) return;
  ans += "A";
  int pt = l;
  while (pt < r) {
    ans += "RA";
    pt++;
  }
  while (true) {
    pt--;
    while (a[pt] >= a[pt + 1]) {
      ans += "L";
      pt--;
    }
    ans += "L";
    pt--;
    ans += "A";
    for (int i = pt + 2; i <= r; i++) a[i]--;
    while (r > l && a[r] == 0) r--;
    if (r == l) break;
    while (pt < r - 1) ans += "AR", pt++;
    pt++, ans += "A";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  while (a[n] == 0) n--;
  for (int i = 0; i < maxv; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < maxv; j++) {
      dp[i][j] = inf;
      for (int k = a[i]; k < maxv; k++) {
        int num = dp[i - 1][k] + 3 * k + abs(k - j);
        if (num < dp[i][j]) dp[i][j] = num, opt[i][j] = k;
      }
    }
  }
  for (int i = 0; i < maxv; i++) dp2[n + 1][i] = i;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < maxv; j++) {
      dp2[i][j] = inf;
      for (int k = max(a[i], 1); k < maxv; k++) {
        int num = dp2[i + 1][k] + 3 * k + abs(k - j);
        if (num < dp2[i][j]) dp2[i][j] = num, opt2[i][j] = k;
      }
    }
  }
  int id = -1, num = dp2[1][0];
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 && dp[i - 1][0] + dp2[i + 1][0] + 2 * i < num)
      id = i, num = dp[i - 1][0] + dp2[i + 1][0] + 2 * i;
  }
  if (id == -1) {
    for (int i = 1; i <= n; i++) a[i] = opt2[i][a[i - 1]];
  } else {
    for (int i = id - 1; i >= 1; i--) a[i] = opt[i][a[i + 1]];
    for (int i = id + 1; i <= n; i++) a[i] = opt2[i][a[i - 1]];
  }
  vector<int> zero;
  for (int i = 0; i <= n; i++)
    if (a[i] == 0) zero.push_back(i);
  zero.push_back(n + 1);
  for (int i = 0; i < int((zero).size()) - 1; i++) {
    f(zero[i], zero[i + 1] - 1);
    if (i + 1 != int((zero).size()) - 1)
      for (int j = zero[i]; j < zero[i + 1]; j++) ans += "AR";
  }
  return cout << ans << endl, 0;
}
