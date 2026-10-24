#include <bits/stdc++.h>
using namespace std;
bool c[10000010];
int prime[10000010];
int tot;
void Euler(int n) {
  tot = 0;
  for (int i = 2; i <= n; i++) {
    if (!c[i]) prime[tot++] = i;
    for (int j = 0; j < tot; j++) {
      if (i * prime[j] > n) break;
      c[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
int pi[10000010];
const int Maxm = 100010;
const int Maxd = 6;
const int num = 110;
int f[num][Maxm + 1];
int pre[Maxd + 1];
void init() {
  Euler(10000010 - 1);
  for (int i = 2; i < 10000010; i++) {
    pi[i] = pi[i - 1];
    if (!c[i]) pi[i]++;
  }
  pre[0] = 1;
  for (int i = 1; i <= Maxd; i++) pre[i] = pre[i - 1] * prime[i - 1];
  for (int i = 0; i < num; i++)
    for (int j = 0; j <= Maxm; j++)
      if (!i)
        f[i][j] = j;
      else
        f[i][j] = f[i - 1][j] - f[i - 1][j / prime[i - 1]];
}
long long phi(int n, long long m) {
  if (!n) return m;
  if (n <= Maxd) return f[n][m % pre[n]] + (m / pre[n]) * f[n][pre[n]];
  if (m <= prime[n - 1]) return 1;
  if (m <= prime[n - 1] * prime[n - 1] && m < 10000010) return pi[m] - n + 1;
  if (m <= Maxm && n < num) return f[n][m];
  return phi(n - 1, m) - phi(n - 1, m / prime[n - 1]);
}
long long lehmer(long long m) {
  if (m < 10000010) return pi[m];
  int q2 = sqrt(m + 0.5), q3 = cbrt(m + 0.5);
  int n = pi[q3];
  long long res = phi(n, m) + n - 1;
  for (int i = n; prime[i] <= q2; i++)
    res = res - lehmer(m / prime[i]) + lehmer(prime[i]) - 1;
  return res;
}
int main() {
  init();
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; (long long)prime[i] * prime[i] * prime[i] <= n; i++) ans++;
  for (int i = 0; (long long)prime[i] * prime[i] <= n; i++)
    ans += lehmer(n / prime[i]) - pi[prime[i]];
  cout << ans << endl;
  return 0;
}
