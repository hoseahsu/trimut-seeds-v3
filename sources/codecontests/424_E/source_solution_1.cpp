#include <bits/stdc++.h>
using namespace std;
typedef int row[3];
const int N = 60;
int a[N], b[N];
inline int tonum(row r) {
  if (r[0] > r[2]) return (r[2] << 4) + (r[1] << 2) + r[0];
  return (r[0] << 4) + (r[1] << 2) + r[2];
}
inline void torow(int x, row r) {
  r[0] = x & 3;
  r[1] = (x >> 2) & 3;
  r[2] = (x >> 4) & 3;
}
const int B = 1e6 + 3;
inline long long id(int n) {
  copy(a, a + n, b);
  sort(b, b + n - 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) ans = ans * B + b[i];
  return ans;
}
unordered_map<long long, double> mem;
const double p[4] = {1.0 / 6, 1.0 / 6, 2.0 / 6, 2.0 / 6}, eps = 1e-8;
double solve(int n) {
  long long h = id(n);
  if (mem.count(h)) return mem[h];
  double mn[4] = {1e9, 1e9, 1e9, 1e9};
  for (int i = 0; i < n - 1; i++)
    if (a[i]) {
      row ri, rn;
      torow(a[i], ri);
      torow(a[n - 1], rn);
      int ti = a[i], tn = a[n - 1];
      int nn = (rn[0] && rn[1] && rn[2] ? n : n - 1);
      if (nn == n) tn = rn[0] = rn[1] = rn[2] = 0;
      int k = 0;
      for (int j = 0; j < 3; j++)
        if (ri[j] && ((j != 1 && ri[1]) || (j == 1 && ri[0] && ri[2])))
          for (int k = 0; k < 3; k++)
            if (!rn[k]) {
              int ch = ri[j];
              swap(rn[k], ri[j]);
              a[nn] = tonum(rn);
              a[i] = tonum(ri);
              if (!ri[1] || (!ri[0] && !ri[2])) a[i] = 0;
              mn[ch] = min(mn[ch], solve(nn + 1));
              swap(rn[k], ri[j]);
              a[nn] = tn;
              a[i] = ti;
            }
    }
  double x = 0, p = 0;
  for (int i = 0; i < 4; i++)
    if (mn[i] < 1e8)
      x += ::p[i] * mn[i];
    else
      p += ::p[i];
  return mem[h] = (abs(1 - p) < eps ? 0 : (x + 1) / (1 - p));
}
inline int get(char x) {
  switch (x) {
    case 'R':
      return 1;
    case 'G':
      return 2;
    case 'B':
      return 3;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  mem.max_load_factor(0.25);
  mem.reserve(512);
  string tmp;
  int n;
  cin >> n;
  row r;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    for (int j = 0; j < 3; j++) r[j] = get(tmp[j]);
    a[i] = tonum(r);
  }
  cout << fixed << setprecision(13) << solve(n) << endl;
}
