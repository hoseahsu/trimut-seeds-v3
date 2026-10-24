#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, inv2 = (MOD + 1) / 2;
double eps = 1e-6;
long long INF = 1e15;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> c[200010];
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
int main() {
  int n = read();
  int now = n * n;
  for (int i = (int)1; i <= (int)n; i++)
    if (i % 2 == 1) {
      for (int j = (int)1; j <= (int)n; j++) {
        c[j].push_back(now);
        now--;
      }
    } else {
      for (int j = (int)n; j >= (int)1; j--) {
        c[j].push_back(now);
        now--;
      }
    }
  for (int i = (int)1; i <= (int)n; i++) {
    for (int j = 0; j < c[i].size(); j++) printf("%d ", c[i][j]);
    printf("\n");
  }
  return 0;
}
