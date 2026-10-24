#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;
int n, m;
char s[MAX];
int q[105][MAX] = {0};
int t = 0;
queue<int> que;
void ps() {
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    int right = (u + 1) % n;
    if (q[t][right] > q[t][u] + 1) q[t][right] = q[t][u] + 1, que.push(right);
    int left = (u - 1 + n) % n;
    if (q[t][left] > q[t][u] + 1) q[t][left] = q[t][u] + 1, que.push(left);
  }
}
void chg() {
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      q[t][i] = 0;
      que.push(i);
    } else
      q[t][i] = -1u / 2;
  }
}
int main() {
  int c = 0;
  int mn = -1u / 2;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    t = i;
    chg();
    if (que.empty()) {
      printf("-1");
      return 0;
    }
    ps();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      q[0][i] += q[j][i];
    }
    mn = min(mn, q[0][i]);
  }
  printf("%d", mn);
  return 0;
}
