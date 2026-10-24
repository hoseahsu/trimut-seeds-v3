#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, val, f[2000] = {0}, mat[30][30];
  memset(mat, -1, sizeof(mat));
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) {
    scanf("%d", &val);
    f[val]++;
  }
  for (int val = 1; val <= 1000; val++) {
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 1; j <= n / 2; j++) {
        if (mat[i][j] == -1 && f[val] >= 4) {
          mat[i][j] = val;
          mat[i][n - j + 1] = val;
          mat[n - i + 1][j] = val;
          mat[n - i + 1][n - j + 1] = val;
          f[val] -= 4;
        }
      }
    }
  }
  if (n % 2) {
    for (int val = 1; val <= 1000; val++) {
      for (int i = 1; i <= n / 2; i++) {
        if (mat[(n + 1) / 2][i] == -1 && f[val] >= 2) {
          mat[(n + 1) / 2][i] = mat[(n + 1) / 2][n - i + 1] = val;
          f[val] -= 2;
        }
      }
      for (int i = 1; i <= n / 2; i++) {
        if (mat[i][(n + 1) / 2] == -1 && f[val] >= 2) {
          mat[i][(n + 1) / 2] = mat[n - i + 1][(n + 1) / 2] = val;
          f[val] -= 2;
        }
      }
      if (f[val] == 1) {
        mat[(n + 1) / 2][(n + 1) / 2] = val;
        f[val]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mat[i][j] == -1) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
