#include <bits/stdc++.h>
using namespace std;
const long long int N = 500005;
const long long int md = 1e9 + 7;
map<long long int, long long int> mm;
map<long long int, long long int> inv;
pair<long long int, long long int> a[N];
long long int b[N];
long long int h[4][N];
long long int has[N];
long long int ans[3][3] = {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}};
long long int M[3][3] = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
long long int temp[3][3], temp1[3][3];
void matcpy(long long int a[][3], long long int b[][3]) {
  for (long long int i = 0; i < 3; i++)
    for (long long int j = 0; j < 3; j++) a[i][j] = b[i][j];
}
void multiply(long long int a[][3], long long int b[][3]) {
  long long int t[3][3] = {0};
  for (long long int i = 0; i < 3; i++)
    for (long long int j = 0; j < 3; j++)
      for (long long int k = 0; k < 3; k++)
        t[i][j] = (t[i][j] + (a[i][k] * b[k][j]) % md) % md;
  matcpy(a, t);
}
void power(long long int a[][3], long long int b[][3], long long int p) {
  if (p == 1) {
    matcpy(a, b);
    return;
  }
  power(a, b, p / 2);
  multiply(a, a);
  if (p & 1) multiply(a, b);
}
void solve(long long int hh, long long int l, long long int r) {
  long long int val = r - l + 1;
  if (val == 0) return;
  matcpy(temp, M);
  if (hh & 1) {
    for (long long int i = 0; i < 3; i++) temp[i][2] = 0;
  }
  if (hh & 2) {
    for (long long int i = 0; i < 3; i++) temp[i][1] = 0;
  }
  if (hh & 4) {
    for (long long int i = 0; i < 3; i++) temp[i][0] = 0;
  }
  power(temp1, temp, val);
  multiply(ans, temp1);
}
signed main() {
  long long int n, m;
  scanf("%lld %lld", &n, &m);
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &b[i], &a[i].first, &a[i].second);
    mm.insert({a[i].first, 0});
    mm.insert({a[i].first - 1, 0});
    mm.insert({a[i].first + 1, 0});
    mm.insert({a[i].second, 0});
    mm.insert({a[i].second - 1, 0});
    mm.insert({a[i].second + 1, 0});
  }
  mm.insert({m, 0});
  mm.insert({2, 0});
  long long int c = 0;
  for (auto it = mm.begin(); it != mm.end(); it++) {
    it->second = ++c;
    inv.insert({c, it->first});
  }
  for (long long int i = 1; i <= n; i++) {
    h[b[i]][mm[a[i].first]]++;
    h[b[i]][mm[a[i].second + 1]]--;
  }
  for (long long int i = 1; i <= c; i++) {
    h[1][i] += h[1][i - 1];
    h[2][i] += h[2][i - 1];
    h[3][i] += h[3][i - 1];
  }
  for (long long int i = 2; i <= mm[m]; i++) {
    long long int hh = 0;
    if (h[1][i]) hh++;
    hh <<= 1;
    if (h[2][i]) hh++;
    hh <<= 1;
    if (h[3][i]) hh++;
    has[i] = hh;
  }
  long long int l = mm[2];
  for (long long int i = mm[2] + 1; i <= mm[m]; i++) {
    if (has[i] != has[i - 1]) {
      solve(has[i - 1], inv[l], inv[i - 1]);
      l = i;
    }
  }
  solve(has[l], inv[l], m);
  printf("%lld", ans[0][1]);
  return 0;
}
