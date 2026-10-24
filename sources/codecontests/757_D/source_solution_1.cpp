#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int *F[76];
int *G[76];
int NM[76][76];
char S[77];
int main() {
  int N, i, j, k;
  int out = 0;
  scanf("%d %s", &N, S);
  for (i = 1; i <= N; ++i) {
    int x = 0;
    for (j = i; j <= N; ++j) {
      x = x * 2 + S[j - 1] - '0';
      NM[i][j] = x;
    }
  }
  i = 0;
  F[i] = new int[1 << 21];
  G[i] = new int[1 << 21];
  F[0][0] = 1;
  for (i = 1; i <= N; ++i) {
    if (i < 6) {
      F[i] = new int[1 << 21];
      G[i] = new int[1 << 21];
    } else {
      swap(F[i], F[i - 6]);
      swap(G[i], G[i - 6]);
      memset(F[i], 0, sizeof(int) * (1 << 21));
      memset(G[i], 0, sizeof(int) * (1 << 21));
    }
    F[i][0] = 1;
    if (S[i - 1] == '0') G[i][0] = F[i - 1][0] + G[i - 1][0];
    for (j = 1; j < (1 << 21); ++j) {
      int x = 0, y = max(1, i - 4);
      F[i][j] = 0;
      for (k = i; k >= y; --k) {
        x = NM[k][i];
        if (x && x <= 21 && (j >> x - 1) % 2) {
          F[i][j] += F[k - 1][j ^ (1 << x - 1)];
          if (F[i][j] >= MOD) F[i][j] -= MOD;
          F[i][j] += F[k - 1][j];
          if (F[i][j] >= MOD) F[i][j] -= MOD;
        }
      }
      if (i - 4 >= 1 && x <= 21 && x && (j >> x - 1) % 2) {
        F[i][j] += G[i - 5][j];
        if (F[i][j] >= MOD) F[i][j] -= MOD;
        F[i][j] += G[i - 5][j ^ (1 << x - 1)];
        if (F[i][j] >= MOD) F[i][j] -= MOD;
      }
      if (S[i - 1] == '0') {
        G[i][j] = F[i - 1][j] + G[i - 1][j];
        if (G[i][j] >= MOD) G[i][j] -= MOD;
      }
      if (((j + 1) & (j)) == 0) {
        out += F[i][j];
        if (out >= MOD) out -= MOD;
      }
    }
  }
  printf("%d", out);
  return 0;
}
