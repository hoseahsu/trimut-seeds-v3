#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, pi = acos(-1.0);
long long n, N = 40, k;
long long nxt[40][100005], sum[40][100005], mi[40][100005];
void query(long long node, long long dis) {
  long long x = 0, y = LLONG_MAX;
  for (int i = 0; i < N; i++)
    if (dis & (1LL << i)) {
      x += (sum[i][node]);
      y = min(y, mi[i][node]);
      node = nxt[i][node];
    }
  cout << x << ' ' << y << "\n";
}
int main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> nxt[0][i];
    nxt[0][i]++;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> sum[0][i];
    mi[0][i] = sum[0][i];
  }
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= n; j++) {
      nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
      sum[i][j] = sum[i - 1][nxt[i - 1][j]] + sum[i - 1][j];
      mi[i][j] = min(mi[i - 1][nxt[i - 1][j]], mi[i - 1][j]);
    }
  for (int i = 1; i <= n; i++) query(i, k);
  return 0;
}
