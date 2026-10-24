#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(INT_MAX / 2);
const int N = (int)(0);
const long long mod = (int)(1e+9 + 7);
int n, m, a, b;
int main() {
  long long num[2], ans = 0;
  for (int i = 0; i < 2; i++) scanf("%I64d", &num[1 - i]);
  num[1]--;
  for (int i = 0; i < 2; i++) {
    int e = num[i] % 10, f;
    if (num[i] / 10 == 0) {
      i == 0 ? ans += num[i] : ans -= num[i];
      continue;
    }
    if (i == 0)
      ans += num[i] / 10 + 9;
    else
      ans -= num[i] / 10 + 9;
    while (num[i]) {
      f = num[i] % 10;
      num[i] /= 10;
    }
    ans += (i == 0 ? -(f > e) : (f > e));
  }
  printf("%I64d\n", ans);
  return 0;
}
