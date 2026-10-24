#include <bits/stdc++.h>
using namespace std;
int n;
double b[205][205], cc[205][205];
void M0(double a[][205], double bb[][205]) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) b[i][j] = bb[j][i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      double t = 0;
      for (int k = 1; k <= n; k++) t += a[i][k] * b[j][k];
      cc[i][j] = t;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = cc[i][j];
}
void M1(double a[], double b[][205]) {
  for (int j = 1; j <= n; j++) {
    double t = 0;
    for (int k = 1; k <= n; k++) t += a[k] * b[k][j];
    cc[0][j] = t;
  }
  for (int j = 1; j <= n; j++) a[j] = cc[0][j];
}
double w[14][205][205], p[205][205];
int X[205], Y[205];
int vis[205], siz[205];
double pp[205];
vector<int> E[205 * 205];
int main() {
  scanf("%d", &n);
  int maxn = 0;
  for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
  for (int i = 1; i <= n; i++) {
    int num = 0;
    fill(vis, vis + n + 1, 0);
    fill(siz, siz + n + 1, 0);
    for (int j = 1; j <= n; j++)
      if (X[i] == X[j] && i != j) {
        ++num;
        siz[j] = 0;
        for (int k = 1; k <= n; k++)
          if (X[i] == X[k]) vis[k] = j, ++siz[j];
        break;
      }
    vis[i] = -1;
    for (int j = 1; j <= n; j++) {
      if (vis[j]) continue;
      int up = Y[j] - Y[i], down = X[j] - X[i];
      ++num;
      siz[j] = 1;
      for (int k = j; k <= n; k++)
        if ((!vis[k]) && (Y[k] - Y[i]) * down == up * (X[k] - X[i]))
          vis[k] = j, ++siz[j];
    }
    for (int j = 1; j <= n; j++) {
      if (vis[j] != j) continue;
      double bas = 1.0 / (siz[j] * num);
      for (int k = j; k <= n; k++)
        if (vis[k] == j) p[k][i] += bas;
      p[i][i] += bas;
    }
    for (int j = i + 1; j <= n; j++)
      if (vis[j] == j) siz[j] = ++maxn, E[maxn].push_back(i);
    for (int k = i + 1; k <= n; k++)
      if (vis[k] > i) E[siz[vis[k]]].push_back(k);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (p[i][j] < 1e-6) exit(1000 * i + j);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) w[0][i][j] = p[i][j];
  for (int i = 1; i < 14; i++) {
    for (int k = 1; k <= n; k++)
      for (int j = 1; j <= n; j++) w[i][k][j] = w[i - 1][k][j];
    M0(w[i], w[i - 1]);
  }
  int qaq;
  scanf("%d", &qaq);
  while (qaq--) {
    int id, ds;
    scanf("%d%d", &id, &ds);
    --ds;
    fill(pp + 1, pp + n + 1, 0.0);
    pp[id] = 1;
    for (int i = 13; i >= 0; --i)
      if (ds >> i & 1) M1(pp, w[i]);
    double als = 0;
    for (int i = 1; i <= maxn; i++) {
      double tmp = 0;
      for (int j = 0; j < (int)E[i].size(); j++) {
        int x = E[i][j];
        tmp += pp[x];
      }
      tmp /= (double)E[i].size();
      als = max(als, tmp);
    }
    printf("%.10lf\n", als);
  }
  return 0;
}
