#include <bits/stdc++.h>
using namespace std;
char s[50005];
int n, dp[3005][3005], dpc[3005][3005];
int gogo() {
  static int c[26];
  memset((c), (0), sizeof((c)));
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) ++c[s[i] - 'a'];
  int z = -1;
  for (int(i) = 0; (i) < (int)(26); ++(i))
    if (c[i] > 100) z = i;
  assert(~z);
  for (int(i) = 0; (i) < (int)(100); ++(i)) putchar('a' + z);
  return 0;
}
int gao(int l, int r) {
  int &res = dp[l][r];
  if (~res) return res;
  if (l == r) return dpc[l][r] = 3, res = 1;
  if (l > r) return dpc[l][r] = 4, res = 0;
  res = 0;
  int t;
  if (s[l] == s[r]) {
    t = gao(l + 1, r - 1) + 2;
    if (t > res) res = t, dpc[l][r] = 3;
  }
  t = gao(l + 1, r);
  if (t > res) res = t, dpc[l][r] = 1;
  t = gao(l, r - 1);
  if (t > res) res = t, dpc[l][r] = 2;
  return res;
}
int main(int argc, char const *argv[]) {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n > 2600) return gogo();
  memset((dp), (-1), sizeof((dp)));
  int max_len = gao(1, n);
  string ans;
  int l = 1, r = n, lst = 0;
  while (l <= r) {
    if (dpc[l][r] == 3) {
      if (l == r) lst = 1;
      ans += s[l];
      ++l, --r;
    } else if (dpc[l][r] == 2) {
      --r;
    } else if (dpc[l][r] == 1) {
      ++l;
    } else {
      assert(0);
    }
  }
  int h = (int)(ans).size();
  for (int i = h - (lst + 1); i >= 0; --i) ans += ans[i];
  int m = (int)(ans).size();
  assert(m == max_len);
  if (m < 100) return puts(ans.c_str()) & 0;
  for (int(i) = 0; (i) < (int)(50); ++(i)) putchar(ans[i]);
  for (int(i) = (int)(49); (i) >= (int)(0); --(i)) putchar(ans[i]);
  puts("");
  return 0;
}
