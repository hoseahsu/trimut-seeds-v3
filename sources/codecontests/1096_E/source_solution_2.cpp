#include <bits/stdc++.h>
using namespace std;
int C[5500][5500];
class Solution {
  const int MOD = 998244353;
  int inv(int x) {
    return x == 1 ? 1 : 1ll * (MOD - MOD / x) * inv(MOD % x) % MOD;
  }
  void init() {
    for (int i = 0; i < 5500; ++i) {
      C[i][i] = C[i][0] = 1;
      for (int j = 1; j < i; ++j) {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        if (C[i][j] >= MOD) C[i][j] -= MOD;
      }
    }
  }
  int dp(int p, int s, int m) {
    if (p == 0) return s == 0;
    int ans = 0;
    for (int i = 0; p - 1 + s - i * m >= 0 and i <= p; ++i) {
      ans += 1ll * C[p - 1 + s - i * m][p - 1] * (i & 1 ? MOD - 1 : 1) % MOD *
             C[p][i] % MOD;
      if (ans >= MOD) ans -= MOD;
    }
    return ans;
  }
  int p, s, r;

 public:
  void run(istream &in, ostream &out) {
    in >> p >> s >> r;
    if (p == 1) return out << 1 << '\n', void();
    init();
    long long ans = 0;
    const int ALL = C[p - 1 + s - r][p - 1];
    for (int score = r; score <= s; ++score) {
      for (int i = 1; i <= p; ++i) {
        ans += 1ll * inv(i) * C[p - 1][i - 1] % MOD *
               dp(p - i, s - score * i, score) % MOD;
        cerr << dp(p - i, s - score * i, score) << '\n';
        if (ans >= MOD) ans -= MOD;
      }
    }
    out << 1ll * ans * inv(ALL) % MOD << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Solution().run(cin, cout);
}
