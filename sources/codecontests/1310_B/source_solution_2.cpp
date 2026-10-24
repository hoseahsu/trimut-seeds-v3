#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read_to_vector(size_t N, std::vector<T> &v) {
  for (size_t i = 0; i < N; i++) {
    T tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
}
template <typename T>
void print_vector(const std::vector<T> &v) {
  for (auto it = v.begin(); it < v.end(); it++) {
    if (it != v.begin()) std::cout << " ";
    std::cout << (*it);
  }
}
long long dp[1 << 17][18][2][2];
const long long INF = 1LL << 40;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long N = 1 << n;
  vector<long long> a;
  read_to_vector(k, a);
  vector<bool> ba(N);
  for (auto x : a) {
    ba[x - 1] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j][0][0] = -INF;
      dp[i][j][0][1] = -INF;
      dp[i][j][1][0] = -INF;
      dp[i][j][1][1] = -INF;
    }
  }
  for (int i = 0; i < N; i += 2) {
    if (ba[i] && ba[i + 1]) {
      dp[i][1][1][1] = 1;
      continue;
    }
    if (ba[i] || ba[i + 1]) {
      dp[i][1][1][0] = dp[i][1][0][1] = 1;
      continue;
    }
    dp[i][1][0][0] = 0;
  }
  for (int t = 2; t <= n; t++) {
    for (int i = 0; i < N; i += (1LL << t)) {
      int j = i + (1LL << (t - 1));
      auto &new0 = dp[i][t];
      auto &old0 = dp[i][t - 1];
      auto &old1 = dp[j][t - 1];
      for (auto u0 : {0, 1}) {
        for (auto l0 : {0, 1}) {
          for (auto u1 : {0, 1}) {
            for (auto l1 : {0, 1}) {
              long long g = old0[u0][l0] + old1[u1][l1];
              long long u = u0 + u1;
              long long l = l0 + l1;
              new0[0][0] = max(new0[0][0], g);
              if (u && l) {
                new0[1][1] = max(new0[1][1], g + 3);
              } else if (u == 2) {
                new0[1][1] = max(new0[1][1], g + 2);
              } else if (u == 1) {
                new0[1][0] = max(new0[1][0], g + 1);
                new0[0][1] = max(new0[0][1], g + 1);
              } else if (l) {
                new0[0][1] = max(new0[0][1], g + 2);
              }
            }
          }
        }
      }
      for (auto u : {0, 1}) {
        for (auto l : {0, 1}) {
        }
      }
    }
  }
  long long res = 0;
  res = max(res, dp[0][n][0][0]);
  res = max(res, dp[0][n][1][0] + 1);
  res = max(res, dp[0][n][0][1] + 1);
  res = max(res, dp[0][n][1][1] + 1);
  cout << res << endl;
}
void pre_compute() {}
int main() {
  std::cout << std::setprecision(15);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  pre_compute();
  solve();
  return 0;
}
