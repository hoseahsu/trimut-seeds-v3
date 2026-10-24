#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int spf[10000005];
void sieve() {
  for (long long int i = 2; i <= 10000004; i++) spf[i] = i;
  for (long long int i = 2; i <= 10000004; i += 2) spf[i] = 2;
  for (long long int i = 3; i * i < 10000004; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j < 10000004; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long int pre[10000005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n;
  sieve();
  vector<long long int> v(n);
  for (auto &x : v) cin >> x;
  for (auto x : v) {
    long long int num = x;
    map<long long int, long long int> ma;
    while (num != 1) {
      ma[spf[num]]++;
      num /= spf[num];
    }
    for (auto y : ma) pre[y.first]++;
  }
  for (long long int i = 1; i < 10000003; ++i) pre[i] += pre[i - 1];
  long long int m;
  cin >> m;
  while (m--) {
    long long int x, y;
    cin >> x >> y;
    if (x > 10000000LL) {
      cout << "0\n";
      continue;
    }
    y = min(y, 10000002LL);
    x--;
    cout << pre[y] - pre[x] << "\n";
  }
}
