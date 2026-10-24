#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long Mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= Mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % Mod;
    a = a * a % Mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int T;
int num[4], sum;
int arr[maxn];
bool solve(int kai) {
  int so_num[4] = {0};
  for (int i = 0; i <= 3; i++) so_num[i] = num[i];
  int kk = kai;
  bool boo = true;
  for (int i = 1; i <= sum; i++) {
    arr[i] = kk;
    so_num[kk]--;
    if (!boo || i == sum) break;
    switch (kk) {
      case 0:
        if (so_num[1] <= 0) boo = false;
        kk = 1;
        break;
      case 1:
        if (so_num[0]) {
          kk = 0;
          break;
        }
        if (!so_num[2]) boo = false;
        kk = 2;
        break;
      case 2:
        if (so_num[3]) {
          kk = 3;
          break;
        }
        if (!so_num[1]) boo = false;
        kk = 1;
        break;
      case 3:
        if (so_num[2] <= 0) boo = false;
        kk = 2;
        break;
    }
  }
  if (!boo) return false;
  return true;
}
int main() {
  int T = 1;
  for (int cas = 1; cas <= T; ++cas) {
    sum = 0;
    for (int i = 0; i <= 3; i++) scanf("%d", &num[i]);
    for (int i = 0; i <= 3; i++) sum += num[i];
    bool bo = false;
    for (int j = 0; j <= 3; j++)
      if (num[j] != 0 && solve(j)) {
        bo = true;
        break;
      }
    if (!bo)
      puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= sum; i++) printf("%d ", arr[i]);
      puts("");
    }
  }
  return 0;
}
