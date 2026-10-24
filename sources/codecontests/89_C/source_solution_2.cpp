#include <bits/stdc++.h>
using namespace std;
char mp[5005][5005];
int n, m, t, nr;
int L[5005 << 1], R[5005 << 1], U[5005 << 1], D[5005 << 1];
void init() {
  for (int i = t; i < t + n; i++) L[i] = R[i] = i;
  for (int i = t; i < t + m; i++) U[i] = D[i] = i;
}
void remove(int idx) {
  U[D[idx]] = U[idx];
  D[U[idx]] = D[idx];
  L[R[idx]] = L[idx];
  R[L[idx]] = R[idx];
}
void resume(int idx) {
  D[U[idx]] = U[D[idx]] = idx;
  L[R[idx]] = R[L[idx]] = idx;
}
void solve(int i, int j, int d) {
  int idx = i * m + j;
  remove(idx);
  if (mp[i][j] == 'L') {
    if (L[idx] == i + t)
      nr = (nr > d + 1 ? nr : d + 1);
    else
      solve(L[idx] / m, L[idx] % m, d + 1);
  } else if (mp[i][j] == 'R') {
    if (R[idx] == i + t)
      nr = (nr > d + 1 ? nr : d + 1);
    else
      solve(R[idx] / m, R[idx] % m, d + 1);
  } else if (mp[i][j] == 'U') {
    if (U[idx] == j + t)
      nr = (nr > d + 1 ? nr : d + 1);
    else
      solve(U[idx] / m, U[idx] % m, d + 1);
  } else if (mp[i][j] == 'D') {
    if (D[idx] == j + t)
      nr = (nr > d + 1 ? nr : d + 1);
    else
      solve(D[idx] / m, D[idx] % m, d + 1);
  }
  resume(idx);
}
int main() {
  int ne, me, idx, res, cnt;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf(" %s", mp[i]);
    t = n * m;
    res = -1;
    cnt = 1;
    init();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mp[i][j] == '.') continue;
        ne = j + t, me = i + t;
        idx = i * m + j;
        U[idx] = U[ne];
        D[idx] = ne;
        D[U[idx]] = idx;
        U[ne] = idx;
        L[idx] = L[me];
        R[idx] = me;
        R[L[idx]] = idx;
        L[me] = idx;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mp[i][j] == '.') continue;
        nr = 0;
        solve(i, j, 0);
        if (nr == res) {
          cnt++;
        } else if (nr > res) {
          res = nr;
          cnt = 1;
        }
      }
    }
    printf("%d %d\n", res, cnt);
  }
  return 0;
}
