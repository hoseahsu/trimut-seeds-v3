#include <bits/stdc++.h>
using namespace std;
long long x[1000006] = {}, y[1000006] = {}, a[1000006] = {}, b[1000006] = {},
          x2[1000006][3], y2[1000006][3];
long long dfs(int i, long long xx, long long yy, long long px[4][2]) {
  int k = i % 4;
  for (int jj = 0; jj < k - 1; jj++) {
    if (xx == px[jj][0] && yy == px[jj][1]) return -1;
  }
  px[k][0] = xx;
  px[k][1] = yy;
  if (i % 4 < 3) {
    long long c1 = dfs(i + 1, x[i + 1], y[i + 1], px);
    long long c2 = -1;
    for (int jj = 0; jj < 3; jj++) {
      long long c3 = dfs(i + 1, x2[i + 1][jj], y2[i + 1][jj], px);
      if (c3 >= 0 && c2 == -1)
        c2 = c3 + jj + 1;
      else if (c3 >= 0 && c2 >= 0)
        c2 = min(c2, c3 + jj + 1);
    }
    if (c1 < 0 && c2 < 0)
      return -1;
    else if (c1 >= 0 && c2 >= 0)
      return min(c1, c2);
    else if (c1 >= 0)
      return c1;
    else
      return c2;
  }
  vector<long long> vm;
  map<long long, long long> jk;
  for (int ii = 0; ii < 4; ii++) {
    for (int jj = ii + 1; jj < 4; jj++) {
      long long rr = (px[ii][0] - px[jj][0]) * (px[ii][0] - px[jj][0]) +
                     (px[ii][1] - px[jj][1]) * (px[ii][1] - px[jj][1]);
      if (jk.find(rr) == jk.end()) {
        jk[rr] = 1;
        vm.push_back(rr);
      } else
        jk[rr]++;
    }
  }
  if (vm.size() > 2) return -1;
  sort(vm.begin(), vm.end());
  if (jk[vm[0]] == 4 && jk[vm[1]] == 2 && 2 * vm[0] == vm[1])
    return 0;
  else
    return -1;
}
long long check(int st) {
  int i = st;
  long long px[4][2] = {};
  long long c1 = dfs(st, x[st], y[st], px);
  long long c2 = -1;
  for (int jj = 0; jj < 3; jj++) {
    long long c3 = dfs(st, x2[i][jj], y2[i][jj], px);
    if (c3 >= 0 && c2 == -1)
      c2 = c3 + jj + 1;
    else if (c3 >= 0 && c2 >= 0)
      c2 = min(c2, c3 + jj + 1);
  }
  if (c1 < 0 && c2 < 0)
    return -1;
  else if (c1 >= 0 && c2 >= 0)
    return min(c1, c2);
  else if (c1 >= 0)
    return c1;
  else
    return c2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < 4 * n; i++) {
    cin >> x[i] >> y[i] >> a[i] >> b[i];
    int fx = x[i] - a[i];
    int fy = y[i] - b[i];
    for (int j = 2; j >= 0; j--) {
      x2[i][j] = fy;
      y2[i][j] = (-1) * fx;
      fx = x2[i][j];
      fy = y2[i][j];
    }
    for (int j = 0; j < 3; j++) {
      x2[i][j] += a[i];
      y2[i][j] += b[i];
    }
  }
  for (int i = 0; i < 4 * n; i += 4) {
    long long ct = 0;
    ct = check(i);
    if (ct >= 0)
      cout << ct << endl;
    else
      cout << "-1\n";
  }
  return 0;
}
