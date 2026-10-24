#include <bits/stdc++.h>
using namespace std;
long long int d[330][330];
int n, m;
int main() {
  cin >> n;
  long long int soma = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> d[i][j];
      if (i < j) soma += d[i][j];
    }
  }
  cin >> m;
  for (int k = 1; k <= m; k++) {
    int v, u;
    long long int w;
    cin >> v >> u >> w;
    if (w < d[v][u]) {
      soma -= d[v][u] - w;
      d[v][u] = w;
      d[u][v] = w;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][v] + d[v][u] + d[u][j] < d[i][j]) {
          soma -= d[i][j] - (d[i][v] + d[v][u] + d[u][j]);
          d[j][i] = d[i][j] = d[i][v] + d[v][u] + d[u][j];
        }
        if (d[i][u] + d[u][v] + d[v][j] < d[i][j]) {
          soma -= d[i][j] - (d[i][u] + d[u][v] + d[v][j]);
          d[j][i] = d[i][j] = d[i][u] + d[u][v] + d[v][j];
        }
      }
    }
    cout << soma << " ";
  }
}
