#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, k, p, s = 0;
  char A[100][100], B[100][100];
  cin >> n;
  cin >> m;
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      cin >> A[i][j];
      B[i][j] = A[i][j];
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      for (k = 0; k <= m - 1; k++)
        if ((A[i][k] == A[i][j]) && (k != j) && (A[i][j] != '0')) {
          A[i][k] = '0';
          s++;
        }
      if (s > 0) A[i][j] = '0';
      s = 0;
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++) {
      for (p = 0; p <= n - 1; p++)
        if ((B[p][j] == B[i][j]) && (p != i) && (B[i][j] != '0')) {
          B[p][j] = '0';
          s++;
        }
      if (s > 0) B[i][j] = '0';
      s = 0;
    }
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= m - 1; j++)
      if ((A[i][j] != '0') && (B[i][j] != '0')) cout << A[i][j];
}
