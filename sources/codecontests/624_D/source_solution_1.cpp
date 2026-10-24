#include <bits/stdc++.h>
using namespace std;
long long arr[(int)(1e6 + 10)], n, a, b, ans = 1e16;
vector<long long> d;
void div(long long x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      d.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) d.push_back(x);
}
long long solve(long long x) {
  long long op1 = 0, op2 = 0, op3 = 0, cur = 1e16;
  for (int i = 1; i <= n; i++) {
    cur = 1e16;
    if (arr[i] % x == 0)
      cur = 0;
    else if ((arr[i] + 1) % x == 0 or (arr[i] - 1) % x == 0)
      cur = b;
    op1 += cur;
    op2 += a;
    op3 += cur;
    op1 = min((long long)1e16, op1);
    op2 = min(op1, op2);
    op3 = min(op3, op2);
  }
  return op3;
}
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  for (int i = -1; i <= 1; i++) div(arr[1] + i), div(arr[n] + i);
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (__typeof(d.begin()) i = d.begin(); i != d.end(); i++)
    ans = min(ans, solve(*i));
  cout << ans << '\n';
}
