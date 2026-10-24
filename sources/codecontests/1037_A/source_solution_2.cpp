#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 5;
const int MOD = 992353;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3fffffffffffffff;
int main() {
  int n;
  scanf("%d", &n);
  int x = 1;
  int ans = 0;
  while (x - 1 < n) x *= 2, ans++;
  printf("%d\n", ans);
  return 0;
}
