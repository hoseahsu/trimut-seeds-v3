#include <bits/stdc++.h>
using namespace std;
long long a, b, c, l;
long long sum = 0, t;
long long check(long long a, long long b, long long c) {
  long long ans = 0;
  for (long long i = 0; i <= l; i++) {
    long long tmpa = a + i;
    if (tmpa < b + c)
      continue;
    else {
      t = min(tmpa - b - c, l - i);
      ans += (t + 2) * (t + 1) / 2;
    }
  }
  return ans;
}
int main() {
  long long t = 0;
  cin >> a >> b >> c >> l;
  long long sum = (l + 3) * (l + 2) * (l + 1) / 6;
  sum -= check(a, b, c);
  sum -= check(b, a, c);
  sum -= check(c, b, a);
  cout << sum << endl;
}
