#include <bits/stdc++.h>
using namespace std;
const long long int P = 1000000007;
const int N = 101;
struct mat {
  long long int a[N][N] = {{0}};
  mat operator*(const mat &r) const {
    mat res;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++)
          res.a[i][j] = (res.a[i][j] + a[i][k] * r.a[k][j]) % P;
    return res;
  }
  mat operator^(int n) {
    mat res;
    for (int i = 0; i < N; i++) res.a[i][i] = 1;
    for (; n > 0; n >>= 1, *this = *this * *this) {
      if (n & 1) res = res * *this;
    }
    return res;
  }
};
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  mat m;
  for (int i = 1; i < N - 1; i++) m.a[i][i - 1] = 1;
  m.a[100][100] = 1;
  for (int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    m.a[0][t - 1]++;
  }
  m.a[0][100] = 1;
  m = m ^ x;
  printf("%lld\n", (m.a[0][0] + m.a[0][100]) % P);
}
