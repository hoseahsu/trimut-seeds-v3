#include <bits/stdc++.h>
using namespace std;
const int kkt = 1 << 20;
char s[51][21 + 2];
int lim, n, m, nrb[1 << 21];
double C[51][51], sol;
queue<int> q;
long long gud[1 << 21];
int cou(long long x) {
  int so = 0;
  while (x) {
    so += nrb[x % kkt];
    x /= kkt;
  }
  return so;
}
int main() {
  cin >> n;
  for (register int i = 1; i <= n; ++i) cin >> (s[i] + 1);
  m = strlen(s[1] + 1);
  lim = 1 << m;
  --lim;
  for (register int i = 0; i <= m; ++i) {
    C[i][0] = 1;
    for (register int j = 1; j <= i; ++j)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  for (register int i = 0; i <= kkt; ++i) nrb[i] = nrb[i / 2] + (i & 1);
  for (register int i = 1; i <= n; ++i) {
    int bi = 0;
    for (register int j = 1; j <= n; ++j)
      if (i != j) {
        int mask = 0;
        for (register int k = 1; k <= m; ++k)
          if (s[i][k] == s[j][k]) mask += 1 << (k - 1);
        gud[mask] |= (1LL << i);
      }
  }
  for (register int i = lim; i >= 0; --i) {
    for (int bit = 1; bit <= lim; bit <<= 1)
      if (!(i & bit)) gud[i] |= gud[i ^ bit];
    if (!gud[i]) continue;
    sol += 1.0 * cou(gud[i]) / n / C[m][nrb[i]];
  }
  cout << fixed << setprecision(10) << sol;
  return 0;
}
