#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int cf[maxn];
int p[maxn];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int L = 0, R = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (p[i] <= i)
      R++;
    else
      L++;
    cf[(p[i] + n - i) % n]++;
    sum += abs(p[i] - i);
  }
  long long ans = sum;
  int op = 0;
  for (int i = 1; i < n; i++) {
    sum = sum - L;
    sum = sum + R - 1;
    sum = sum - abs(p[n - i + 1] - n) + abs(p[n - i + 1] - 1);
    L = L - (cf[i] - 1);
    R = R + (cf[i] - 1);
    if (ans > sum) {
      ans = sum;
      op = i;
    }
  }
  printf("%lld %d\n", ans, op);
  return 0;
}
