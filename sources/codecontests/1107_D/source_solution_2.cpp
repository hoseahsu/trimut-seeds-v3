#include <bits/stdc++.h>
using namespace std;
bool mat[5205][5205];
int prefR[5205][5205], prefC[5205][5205];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    int n, i, j, k;
    cin >> n;
    char ch;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j += 4) {
        cin >> ch;
        long long int num = 0;
        if (isdigit(ch))
          num = ch - '0';
        else
          num = ch - 'A' + 10;
        k = j + 3;
        while (num > 0) {
          mat[i][k] = num % 2;
          k--;
          num /= 2;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) prefR[i][j] = prefR[i][j - 1] + mat[i][j];
    }
    for (j = 1; j <= n; j++) {
      for (i = 1; i <= n; i++) prefC[i][j] = prefC[i - 1][j] + mat[i][j];
    }
    for (i = n; i >= 2; i--) {
      long long int f = 1;
      if (n % i == 0) {
        for (k = 1; k <= n; k++) {
          for (j = 1; j <= n; j += i) {
            long long int val = prefC[j + i - 1][k] - prefC[j - 1][k];
            if (val != i * mat[j][k]) {
              f = 0;
              break;
            }
          }
          if (!f) break;
        }
        if (!f) continue;
        for (k = 1; k <= n; k++) {
          for (j = 1; j <= n; j += i) {
            long long int val = prefR[k][j + i - 1] - prefR[k][j - 1];
            if (val != i * mat[k][j]) {
              f = 0;
              break;
            }
          }
          if (!f) break;
        }
        if (f) {
          cout << i << "\n";
          return 0;
        }
      }
    }
    cout << "1\n";
  }
  return 0;
}
