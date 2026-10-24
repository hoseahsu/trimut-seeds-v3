#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = 1) {}
double f[2000 + 1][2000 + 1];
int main() {
  int n, t;
  double p;
  while (cin >> n >> p >> t) {
    f[0][0] = 1;
    for (int j = 1; j <= t; j++) f[0][j] = f[0][j - 1] * (1 - p);
    for (int i = 1; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= t; j++)
        f[i][j] = f[i - 1][j - 1] * p + f[i][j - 1] * (1 - p);
    for (int j = 1; j <= t; j++) f[n][j] = f[n - 1][j - 1] * p + f[n][j - 1];
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += i * f[i][t];
    printf("%.6lf", ans);
  }
}
