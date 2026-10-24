#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long int> d;
  for (long long int i = 1; (i * i) <= n; i++) {
    if (n % i) continue;
    d.push_back(i);
    if (i != n / i) d.push_back(n / i);
  }
  sort(d.rbegin(), d.rend());
  for (int j : d) {
    long long int sum = 1 + n - (j - 1);
    sum *= n / j;
    sum /= 2;
    printf("%lld ", sum);
  }
  return 0;
}
