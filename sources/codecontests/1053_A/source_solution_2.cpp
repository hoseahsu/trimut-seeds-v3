#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
bool vis[10005];
long long n, m, k;
int main() {
  cin >> n >> m >> k;
  if ((n * m * 2) % k != 0)
    puts("NO");
  else {
    puts("YES");
    puts("0 0");
    if ((n * 2) % k == 0) {
      printf("%lld 0\n", n * 2 / k);
      printf("%lld %lld\n", n / 2, m);
    } else if ((m * 2) % k == 0) {
      printf("%lld 0\n", n);
      printf("%lld %lld\n", n / 2, m * 2 / k);
    } else {
      for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
          while (k % i == 0) {
            v.push_back(i);
            k /= i;
          }
        }
      }
      if (k != 1) v.push_back(k);
      long long len = v.size(), N = n, M = m;
      for (int i = 0; i < len; i++) {
        if (N % v[i] == 0) {
          N /= v[i];
          vis[i] = 1;
        }
      }
      for (int i = 0; i < len; i++) {
        if (vis[i]) continue;
        if (M % v[i] == 0) {
          M /= v[i];
          vis[i] = 1;
        }
      }
      long long cnt = 2;
      for (int i = 0; i < len; i++) {
        if (!vis[i]) cnt = 1;
      }
      if (N < n) {
        printf("%lld 0\n", N * cnt);
        printf("%lld %lld\n", N, M);
      } else {
        printf("%lld 0\n", N);
        printf("%lld %lld\n", N, M * cnt);
      }
    }
  }
  return 0;
}
