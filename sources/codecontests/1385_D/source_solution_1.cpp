#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int te, n, a[26][N], b[N], ln;
int d[26][132000];
string s;
int f(int pos, int len, int c) {
  if (d[c][pos] <= n) return d[c][pos];
  if (len == 0) return d[c][pos] = (b[pos] != c);
  int mid = pos + (1 << (len - 1));
  d[c][pos] =
      min(mid - pos - a[c][mid - 1] + a[c][pos - 1] + f(mid, len - 1, c + 1),
          mid - pos - a[c][pos + (1 << len) - 1] + a[c][mid - 1] +
              f(pos, len - 1, c + 1));
  return d[c][pos];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> te;
  for (; te--;) {
    cin >> n >> s;
    for (int i = 0; i < 17; i++)
      for (int j = 0; j < 26; j++)
        for (int k = 1; k <= n; k++) d[j][k] = n + 1;
    for (int i = 1; i <= n; i++) {
      b[i] = s[i - 1] - 'a';
      for (int j = 0; j < 26; j++) a[j][i] = a[j][i - 1];
      a[b[i]][i]++;
    }
    ln = 0;
    while ((1 << ln) < n) ln++;
    cout << f(1, ln, 0) << "\n";
  }
}
