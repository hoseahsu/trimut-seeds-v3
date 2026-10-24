#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> res;
long long my_pow(long long x) { return x * x * x; }
void dfs(long long m, long long s, long long v) {
  int x = 0;
  if (m <= 0) {
    res = max(res, make_pair(s, v));
    return;
  }
  while (my_pow(x + 1) <= m) {
    x++;
  }
  dfs(m - my_pow(x), s + 1, v + my_pow(x));
  if (x - 1 > 0) {
    dfs(my_pow(x) - 1 - my_pow(x - 1), s + 1, v + my_pow(x - 1));
  }
}
int main() {
  long long m, i, t, j, N = 0, X = 0, ansn = 0, ansX = 0, flag = 0, k, l;
  scanf("%I64d", &m);
  dfs(m, 0, 0);
  printf("%I64d %I64d\n", res.first, res.second);
}
