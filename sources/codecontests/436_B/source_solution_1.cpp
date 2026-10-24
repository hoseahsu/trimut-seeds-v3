#include <bits/stdc++.h>
using namespace std;
char mapa[2005][2005];
int C[2005];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> mapa[i];
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] == '.') continue;
      if (mapa[i][j] == 'D') continue;
      if (mapa[i][j] == 'U') {
        if (i % 2 == 0) C[j]++;
        continue;
      }
      int pos = j;
      if (mapa[i][j] == 'R')
        pos += i;
      else
        pos -= i;
      if (pos < 0 || pos >= m) continue;
      C[pos]++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (i) cout << " ";
    cout << C[i];
  }
  cout << endl;
  return 0;
}
