#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265;
void fastInOut();
const int N = 5003;
const long long OO = (long long)1e18;
int n, m, k;
long long cum[N], memo[N][N];
long long go(int i, int c) {
  if (i == n + 1) return c == k ? 0 : -OO;
  long long &ret = memo[i][c];
  if (ret != -1) return ret;
  ret = go(i + 1, c);
  if (i + m <= n + 1)
    ret = max(ret, cum[i + m - 1] - cum[i - 1] + go(i + m, c + 1));
  return ret;
}
int main() {
  fastInOut();
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> cum[i];
    cum[i] += cum[i - 1];
  }
  memset(memo, -1, sizeof(memo));
  cout << go(1, 0);
  return 0;
}
void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
