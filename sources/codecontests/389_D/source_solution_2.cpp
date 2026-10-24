#include <bits/stdc++.h>
using namespace std;
const int NMax = 2001;
const int INF = int(1e9);
const int sizeTree = 524289;
const double eps = 1e-9;
const double PI = 3.141592653589793238462;
const int MOD = int(1e9);
int t[30];
char ans[NMax][NMax];
int d[30][2];
int k, pos, v = 3, cnt = 0;
void connect(int v, int u) {
  ans[v][u] = 'Y';
  ans[u][v] = 'Y';
}
int main() {
  t[0] = 1;
  for (int i = 1; i <= 29; i++) t[i] = t[i - 1] * 2;
  scanf("%i", &k);
  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= 1000; j++) ans[i][j] = 'N';
  while (k > 0) {
    for (int i = 0; i <= 29; i++) {
      if (t[i] > k) break;
      pos = i;
    }
    k -= t[pos];
    if (cnt == 0) {
      if (pos == 0) {
        connect(1, 2);
        continue;
      }
      cnt = pos;
      for (int i = 1; i <= pos; i++) {
        d[i][0] = v;
        d[i][1] = v + 1;
        v += 2;
      }
      connect(1, d[1][0]);
      connect(1, d[1][1]);
      for (int i = 2; i <= pos; i++) {
        connect(d[i - 1][0], d[i][0]);
        connect(d[i - 1][1], d[i][0]);
        connect(d[i - 1][0], d[i][1]);
        connect(d[i - 1][1], d[i][1]);
      }
      connect(2, d[pos][0]);
      connect(2, d[pos][1]);
      continue;
    }
    connect(1, v);
    v++;
    for (int i = 2; i <= cnt - pos; i++) {
      connect(v - 1, v);
      v++;
    }
    if (pos == 0) {
      connect(v - 1, 2);
    } else {
      connect(v - 1, d[cnt - pos + 1][0]);
      connect(v - 1, d[cnt - pos + 1][1]);
    }
  }
  v--;
  printf("%i\n", v);
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= v; j++) printf("%c", ans[i][j]);
    printf("\n");
  }
  return 0;
}
