#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1600 + 10;
int n, t, sS[MAXN], sL[MAXN], tS[MAXN], tL[MAXN], id[MAXN];
long double pF[MAXN], a[MAXN], b[MAXN], c[MAXN];
pair<long double, long double> f[MAXN][MAXN];
bool cmp(int first, int second) {
  return (long double)pF[second] * (-tL[second]) -
             pF[first] * pF[second] * tL[first] <
         (long double)pF[first] * (-tL[first]) -
             pF[first] * pF[second] * tL[second];
}
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; ++i) {
    double f;
    scanf("%d%d%d%d%lf", &sS[i], &sL[i], &tS[i], &tL[i], &f), id[i] = i;
    pF[i] = f;
  }
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= t; ++j) {
      f[i][j] = max(f[i][j], f[i - 1][j]);
      pair<long double, long double> F = f[i - 1][j];
      F.second = -F.second;
      int p = id[i];
      if (j + tS[p] <= t)
        f[i][j + tS[p]] = max(f[i][j + tS[p]],
                              make_pair(F.first + sS[p], -(F.second + tS[p])));
      if (j + tS[p] + tL[p] <= t) {
        F.first += (long double)sS[p] + (1.0 - pF[p]) * sL[p];
        F.second =
            (F.second + tS[p]) * pF[p] + (1.0 - pF[p]) * (j + tS[p] + tL[p]);
        f[i][j + tS[p] + tL[p]] =
            max(f[i][j + tS[p] + tL[p]], make_pair(F.first, -F.second));
      }
    }
  pair<long double, long double> Tohka = make_pair(0, 0);
  for (int i = 0; i <= t; ++i) Tohka = max(Tohka, f[n][i]);
  cout << setprecision(10);
  cout << fixed << Tohka.first << " " << -Tohka.second << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
