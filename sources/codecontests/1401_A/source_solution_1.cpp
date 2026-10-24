#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 1e18;
const int INF = 1e9;
const int MOD = 998244353;
const int HMOD = 999959;
const int VMOD = 5000000;
const int MAXN = 3e5 + 10;
const int MAXM = 5e5 + 10;
const int INV = 10050505;
const long long LLINV = 1e18;
const double eps = 1e-3;
int dirx[5] = {0, -1, 1, 0, 0}, diry[5] = {0, 0, 0, -1, 1};
int n, k;
void solve() {
  scanf("%d%d", &n, &k);
  if (n > k && (n - k) % 2 == 0)
    puts("0");
  else if (n > k)
    puts("1");
  else
    printf("%d\n", k - n);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
