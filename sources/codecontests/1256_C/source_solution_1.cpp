#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int MAXN = 10010;
int ans[MAXN];
int c[MAXN];
int n, m, d;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> d;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    sum += c[i];
  }
  int i = 0, j = 1;
  int space = d - 1;
  int can = n - sum;
  while (i < n and (j <= m or (space > 0 and can > 0))) {
    if (space > 0 and can > 0) {
      ans[i++] = 0;
      space--;
      can--;
    } else if (c[j] > 0) {
      ans[i++] = j;
      c[j]--;
    } else {
      space = d - 1;
      j++;
    }
  }
  if (i < n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}
