#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 2;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
unsigned long long n, k, l, m;
struct Matrix {
  unsigned long long mat[maxm][maxm];
};
Matrix MM;
Matrix Matmul(Matrix x, Matrix y) {
  int i, j;
  int k;
  Matrix C;
  for (i = 0; i < maxm; i++) {
    for (j = 0; j < maxm; j++) {
      C.mat[i][j] = 0;
      for (k = 0; k < maxm; k++) {
        C.mat[i][j] += x.mat[i][k] * y.mat[k][j];
        C.mat[i][j] %= m;
      }
    }
  }
  return C;
}
Matrix Matpow(Matrix gg, unsigned long long t) {
  int i, j;
  if (t == 1) return gg;
  gg = Matpow(gg, t / 2);
  if (t % 2 == 0) {
    return Matmul(gg, gg);
  } else {
    return Matmul(Matmul(gg, gg), MM);
  }
}
unsigned long long mypow(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 1;
  while (y) {
    if (y & 1) {
      ret *= x;
      ret %= m;
    }
    x *= x;
    x %= m;
    y >>= 1;
  }
  return ret;
}
int main() {
  int i, j;
  while (cin >> n >> k >> l >> m) {
    if (k >= pow(2, l)) {
      puts("0");
      continue;
    } else {
      MM.mat[0][0] = MM.mat[0][1] = MM.mat[1][0] = 1;
      MM.mat[1][1] = 0;
      Matrix C = Matpow(MM, n);
      unsigned long long cnt = C.mat[0][0] + C.mat[0][1];
      cnt %= m;
      unsigned long long ff = mypow(2, n);
      ff = (ff - cnt + m) % m;
      unsigned long long ans = 1;
      for (i = 0; i < l; i++) {
        if ((k >> i) & 1) {
          ans *= ff;
        } else {
          ans *= cnt;
        }
        ans %= m;
      }
      ans %= m;
      cout << ans << endl;
    }
  }
  return 0;
}
