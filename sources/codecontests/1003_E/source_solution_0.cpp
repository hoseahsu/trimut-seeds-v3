#include <bits/stdc++.h>
int n, d, k, x, z;
std::vector<int> V1, V2;
void add(int u, int v) {
  V1.push_back(u);
  V2.push_back(v);
}
void dfs(int u, int dd, int p) {
  if (p)
    while (dd--) {
      if (x >= n) return;
      add(u, ++x);
      dfs(x, k - 1, p - 1);
    }
}
int main() {
  std::cin >> n >> d >> k;
  z = d / 2;
  x = 1;
  if (n == 1 || d >= n || k == 1 && n > 2) return puts("NO"), 0;
  if (d & 1) {
    add(1, ++x);
    n -= z;
    dfs(1, k - 1, z);
    n += z;
    dfs(2, k - 1, z);
  } else {
    n -= z;
    dfs(1, k / 2, z);
    n += z;
    dfs(1, k - k / 2, z);
  }
  if (x < n) return puts("NO"), 0;
  puts("YES");
  for (int i = 0; i < n - 1; ++i) printf("%d %d\n", V1[i], V2[i]);
  return 0;
}
