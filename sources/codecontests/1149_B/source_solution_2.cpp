#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
const long long L = 256;
const long long INF = 1e9 + 7;
const long long C = 26;
long long dp[L][L][L];
string a[3];
long long mn[3];
long long to[N][C];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 0; i < L; ++i) {
    for (long long j = 0; j < L; ++j) {
      for (long long k = 0; k < L; ++k) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (long long i = 0; i < C; ++i) {
    to[n][i] = INF;
  }
  for (long long i = n - 1; i >= 0; --i) {
    for (long long j = 0; j < C; ++j) {
      to[i][j] = to[i + 1][j];
    }
    to[i][s[i] - 'a'] = i;
  }
  while (q--) {
    char t;
    cin >> t;
    if (t == '+') {
      long long i;
      char c;
      cin >> i >> c;
      --i;
      a[i] += c;
      for (long long t = 0; t < 3; ++t) {
        mn[t] = 0;
      }
      mn[i] = a[i].size();
      for (long long p0 = mn[0]; p0 <= a[0].size(); ++p0) {
        for (long long p1 = mn[1]; p1 <= a[1].size(); ++p1) {
          for (long long p2 = mn[2]; p2 <= a[2].size(); ++p2) {
            if (p0 && dp[p0 - 1][p1][p2] != INF) {
              long long pos = to[dp[p0 - 1][p1][p2]][a[0][p0 - 1] - 'a'];
              if (pos != INF) {
                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
              }
            }
            if (p1 && dp[p0][p1 - 1][p2] != INF) {
              long long pos = to[dp[p0][p1 - 1][p2]][a[1][p1 - 1] - 'a'];
              if (pos != INF) {
                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
              }
            }
            if (p2 && dp[p0][p1][p2 - 1] != INF) {
              long long pos = to[dp[p0][p1][p2 - 1]][a[2][p2 - 1] - 'a'];
              if (pos != INF) {
                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
              }
            }
          }
        }
      }
    } else {
      long long i;
      cin >> i;
      --i;
      for (long long t = 0; t < 3; ++t) {
        mn[t] = 0;
      }
      mn[i] = a[i].size();
      for (long long p0 = mn[0]; p0 <= a[0].size(); ++p0) {
        for (long long p1 = mn[1]; p1 <= a[1].size(); ++p1) {
          for (long long p2 = mn[2]; p2 <= a[2].size(); ++p2) {
            dp[p0][p1][p2] = INF;
          }
        }
      }
      a[i].pop_back();
    }
    if (dp[a[0].size()][a[1].size()][a[2].size()] == INF) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
