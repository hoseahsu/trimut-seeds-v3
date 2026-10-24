#include <bits/stdc++.h>
using namespace std;
long long int a[1005][1005], dp[1005][1005];
long long int n, m, q;
string s;
long long int bitcount(long long int x) {
  long long int ct = 0;
  while (x != 0) {
    ct += (x & 1LL);
    x = x >> 1LL;
  }
  return ct;
}
long long int normalsum(long long int x, long long int y) { return dp[x][y]; }
long long int inversesum(long long int x, long long int y) {
  return (x + 1) * (y + 1) - dp[x][y];
}
long long int ans(long long int x, long long int y) {
  if (y == -1 || x == -1) return 0LL;
  long long int fieldx = (x / n) + 1;
  long long int fieldy = (y / m) + 1;
  long long int sum = 0;
  if (!(fieldx & 1LL) && !(fieldy & 1LL)) {
    sum += (((((fieldx - 1) * (fieldy - 1) - 1) / 2) * n * m));
    x = x % n;
    y = y % m;
    sum += (((fieldx - 2) / 2) * (y + 1) * n);
    sum += (((fieldy - 2) / 2) * (x + 1) * m);
    if ((bitcount(fieldx - 2) + bitcount(fieldy - 2)) & 1LL) {
      sum += (inversesum(n - 1, m - 1));
    } else {
      sum += (normalsum(n - 1, m - 1));
    }
    if ((bitcount(fieldx - 1) + bitcount(fieldy - 1)) & 1LL) {
      sum += (inversesum(x, y) + normalsum(x, m - 1) + normalsum(n - 1, y));
    } else {
      sum += (normalsum(x, y) + inversesum(x, m - 1) + inversesum(n - 1, y));
    }
  } else if (fieldx & 1LL && fieldy & 1LL) {
    sum += (((fieldx - 1) / 2) * (fieldy - 1) * n * m);
    x = x % n;
    y = y % m;
    sum += (((fieldx - 1) / 2 * (y + 1) * n));
    sum += (((fieldy - 1) / 2) * (x + 1) * m);
    if ((bitcount(fieldx - 1) + bitcount(fieldy - 1)) & 1LL) {
      sum += (inversesum(x, y));
    } else {
      sum += (normalsum(x, y));
    }
  } else if (fieldx & 1LL) {
    sum += (((fieldx - 1) / 2) * (fieldy - 1) * n * m);
    x = x % n;
    y = y % m;
    sum += (((fieldx - 1) / 2) * (y + 1) * n);
    sum += (((fieldy - 2) / 2) * (x + 1) * m);
    if ((bitcount(fieldx - 1) + bitcount(fieldy - 1)) & 1LL) {
      sum += (inversesum(x, y) + normalsum(x, m - 1));
    } else {
      sum += (normalsum(x, y) + inversesum(x, m - 1));
    }
  } else if (fieldy & 1LL) {
    sum += ((fieldx - 1) * ((fieldy - 1) / 2) * n * m);
    x = x % n;
    y = y % m;
    sum += (((fieldx - 2) / 2) * (y + 1) * n);
    sum += (((fieldy - 1) / 2) * (x + 1) * m);
    if ((bitcount(fieldx - 1) + bitcount(fieldy - 1)) & 1LL) {
      sum += (inversesum(x, y) + normalsum(n - 1, y));
    } else {
      sum += (normalsum(x, y) + inversesum(n - 1, y));
    }
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '0')
        a[i][j] = 0;
      else if (s[j] == '1')
        a[i][j] = 1;
  }
  dp[0][0] = a[0][0];
  for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + a[0][i];
  for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + a[i][0];
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++)
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
  }
  while (q--) {
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    long long int finalans =
        ans(x2, y2) - ans(x2, y1 - 1) - ans(x1 - 1, y2) + ans(x1 - 1, y1 - 1);
    cout << finalans << '\n';
  }
  return 0;
}
