#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long f[n], w[n];
  for (long long i = 0; i < n; i++) cin >> f[i];
  for (long long i = 0; i < n; i++) cin >> w[i];
  long long mh = 0;
  while ((1LL << mh) <= k) mh++;
  long long up[n][mh], s[n][mh], m[n][mh];
  for (long long i = 0; i < n; i++) {
    up[i][0] = f[i];
    s[i][0] = w[i];
    m[i][0] = w[i];
  }
  for (long long j = 1; j < mh; j++)
    for (long long i = 0; i < n; i++) {
      up[i][j] = up[up[i][j - 1]][j - 1];
      s[i][j] = s[i][j - 1] + s[up[i][j - 1]][j - 1];
      m[i][j] = min(m[i][j - 1], m[up[i][j - 1]][j - 1]);
    }
  for (long long i = 0; i < n; i++) {
    long long curr = i, s1 = 0, m1 = 1000000000;
    for (long long j = 0; j < mh; j++)
      if ((k >> j) & 1) {
        s1 += s[curr][j];
        m1 = min(m1, m[curr][j]);
        curr = up[curr][j];
      }
    cout << s1 << " " << m1 << endl;
  }
}
