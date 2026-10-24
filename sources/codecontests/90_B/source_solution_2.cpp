#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x[111][111];
  char a[111][111];
  for (int i = 0; i < 111; i++)
    for (int j = 0; j < 111; j++) x[i][j] = 1;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      for (int k = j; k < m; k++)
        if (a[i][j] == a[i][k] && k > j) x[i][j] = x[i][k] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      for (int k = i; k < n; k++)
        if (a[i][j] == a[k][j] && k > i) x[i][j] = x[k][j] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (x[i][j]) cout << a[i][j];
}
