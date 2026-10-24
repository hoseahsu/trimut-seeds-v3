#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<long long>> mul(vector<vector<long long>> A,
                              vector<vector<long long>> B) {
  int n = A.size();
  vector<vector<long long>> res(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return res;
}
vector<vector<long long>> mexp(vector<vector<long long>> M, long long e) {
  if (e == 1) return M;
  if (e % 2) return mul(M, mexp(M, e - 1));
  vector<vector<long long>> R = mexp(M, e / 2);
  return mul(R, R);
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (m > n) {
    cout << 1 << endl;
    return 0;
  }
  vector<vector<long long>> M(m, vector<long long>(m));
  M[0][0] = M[0][m - 1] = 1;
  for (int i = 1; i < m; i++) M[i][i - 1] = 1;
  vector<vector<long long>> R = mexp(M, n - m + 1);
  long long res = 0;
  for (int i = 0; i < m; i++) res = (res + R[0][i]) % MOD;
  cout << res << endl;
}
