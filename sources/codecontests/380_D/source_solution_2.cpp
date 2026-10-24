#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int MOD = 1000000007;
int add(int a, int b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) { return a * 1ll * b % MOD; }
int mpow(int a, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) res = mul(res, a);
    a = mul(a, a);
    p /= 2;
  }
  return res;
}
int aim[MAXN];
int num[MAXN];
int place[MAXN];
int sz;
int n;
int fact[MAXN];
int inv_fact[MAXN];
int for_empty(int len) { return mpow(2, max(0, len - 1)); }
int C(int N, int K) {
  if (K > N || N < 0 || K < 0) return 0;
  return mul(fact[N], mul(inv_fact[N - K], inv_fact[K]));
}
int solve(int i, int l, int r) {
  if (l < 0 || l >= n || r < 0 || r >= n) return 0;
  if (i == sz) {
    int all = n - num[i - 1];
    int cnt = l;
    return C(all, cnt);
  }
  if (l <= aim[i] && aim[i] <= r) return 0;
  if (r < aim[i]) {
    int all = num[i] - num[i - 1] - 1;
    int cnt = aim[i] - r - 1;
    int can = aim[i] - (r - l + 1);
    if (all > can) return 0;
    return mul(C(all, cnt), solve(i + 1, l - (all - cnt), aim[i]));
  } else {
    assert(l > aim[i]);
    int all = num[i] - num[i - 1] - 1;
    int cnt = l - aim[i] - 1;
    int can = n - aim[i] - 1 - (r - l + 1);
    if (all > can) return 0;
    return mul(C(all, cnt), solve(i + 1, aim[i], r + (all - cnt)));
  }
}
int main() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mpow(fact[i], MOD - 2);
  }
  memset(place, -1, sizeof place);
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) {
    int a;
    scanf("%d", &a);
    if (a) {
      place[a - 1] = i;
    }
  }
  sz = 0;
  for (int i = 0; i < (int)n; i++)
    if (place[i] != -1) {
      aim[sz] = place[i];
      num[sz++] = i + 1;
    }
  if (sz == 0) {
    printf("%d\n", for_empty(n));
    return 0;
  }
  int ans = 0;
  int cnt = num[0] - 1;
  if (cnt <= aim[0]) {
    ans = add(ans, mul(for_empty(cnt), solve(1, aim[0] - cnt, aim[0])));
  }
  if (cnt <= n - aim[0] - 1 && cnt > 0) {
    ans = add(ans, mul(for_empty(cnt), solve(1, aim[0], aim[0] + cnt)));
  }
  printf("%d\n", ans);
  return 0;
}
