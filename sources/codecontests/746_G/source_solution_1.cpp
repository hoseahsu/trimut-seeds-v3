#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
map<int, int> cur[N];
int a[N], n, t, k;
int ed = 0, u[N], v[N];
int main() {
  scanf("%d%d%d", &n, &t, &k);
  for (int i = 1; i <= t; i++) scanf("%d", &a[i]);
  a[0] = 1;
  if (n - t < k || a[t] > k) return puts("-1"), 0;
  int curr = 0;
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j < a[i]; j++) cur[i][j] = ++curr;
  }
  int nleaf = n - t - k;
  for (int i = 0; i < a[1]; i++) u[++ed] = 1, v[ed] = cur[1][i];
  for (int i = 2; i <= t; i++) u[++ed] = cur[i - 1][0], v[ed] = cur[i][0];
  for (int i = 2; i <= t; i++) {
    for (int j = 1; j < a[i]; j++) {
      if (nleaf && j < a[i - 1]) {
        u[++ed] = cur[i - 1][j];
        v[ed] = cur[i][j];
        nleaf--;
      } else
        u[++ed] = cur[i - 1][0], v[ed] = cur[i][j];
    }
  }
  if (nleaf) return puts("-1"), 0;
  printf("%d\n", n);
  for (int i = 1; i <= ed; i++) cout << u[i] << " " << v[i] << "\n";
}
