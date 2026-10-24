#include <bits/stdc++.h>
using namespace std;
long long bi[(1LL << 19) + 1];
long long sum(long long a) {
  long long s = 0;
  while (a > 0) {
    s += bi[a];
    a -= a & -a;
  }
  return s;
}
void add(long long a, long long x) {
  while (a <= (1LL << 19)) {
    bi[a] += x;
    a += a & -a;
  }
}
long long mod_div(long long a, long long b) {
  long long tmp = 998244353 - 2, c = b, ret = 1;
  while (tmp > 0) {
    if (tmp & 1) {
      ret *= c;
      ret %= 998244353;
    }
    c *= c;
    c %= 998244353;
    tmp >>= 1;
  }
  return a * ret % 998244353;
}
long long used[222222];
long long remain[222222];
int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  vector<long long> v(n);
  for (long long(i) = (0); (i) < (n); ++i) {
    cin >> v[i];
    if (v[i] == -1) {
      remain[i]++;
    } else {
      ans = (ans + (sum(n) - sum(v[i]))) % 998244353;
      add(v[i], 1);
      used[v[i]]++;
    }
  }
  for (long long(i) = (0); (i) < (222221); ++i) {
    remain[i + 1] += remain[i];
    used[i + 1] += used[i];
  }
  ans = (ans + mod_div(remain[n] * (remain[n] - 1) % 998244353, 4)) % 998244353;
  for (long long(i) = (0); (i) < (n); ++i) {
    if (v[i] != -1) {
      long long smaller = v[i] - used[v[i]];
      long long bigger = n - used[n] - smaller;
      long long le = remain[i];
      long long ri = remain[n] - le;
      long long tmp = 0;
      if (le + ri)
        tmp = mod_div(
            (bigger * le % 998244353 + smaller * ri % 998244353) % 998244353,
            le + ri);
      ans = (ans + tmp) % 998244353;
    }
  }
  cout << ans << endl;
  return 0;
}
