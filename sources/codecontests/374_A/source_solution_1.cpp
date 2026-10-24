#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int solve(int i, int j) {
  if (i % a != 0) return INT_MAX;
  if (j % b != 0) return INT_MAX;
  i /= a;
  j /= b;
  if ((i + j) & 1) return INT_MAX;
  if (!i && !j) return 0;
  if (b >= m || a >= n) return INT_MAX;
  return max(i, j);
}
int main() {
  int i, j;
  scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
  int ans = INT_MAX;
  ans = min(ans, solve(i - 1, j - 1));
  ans = min(ans, solve(i - 1, m - j));
  ans = min(ans, solve(n - i, m - j));
  ans = min(ans, solve(n - i, j - 1));
  if (ans == INT_MAX)
    puts("Poor Inna and pony!");
  else
    printf("%d\n", ans);
  return 0;
}
