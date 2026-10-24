#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6, pi = acos(-1);
const int N = 5e3 + 5, M = 1e9 + 7, SEGM = 4 * N, OO = 0x3f3f3f3f;
int t, n, k, arr[N];
int mem[N][N];
map<int, int> mp;
map<int, int> cnt;
int solve(int i, int tms) {
  if (tms <= 0) return 0;
  if (i >= n) return 0;
  int &ret = mem[i][tms];
  if (~ret) return ret;
  ret = solve(i + 1, tms);
  if (tms) {
    int idx = upper_bound(arr + i, arr + n, arr[i] + 5) - arr;
    ret = max(ret, solve(idx, tms - 1) + cnt[arr[i]]);
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", arr + i), ++mp[arr[i]];
  sort(arr, arr + n);
  arr[n] = OO;
  for (int i = 0; i < n; ++i)
    if (cnt.find(arr[i]) == cnt.end())
      for (int j = 0; j < 6; ++j) cnt[arr[i]] += mp[arr[i] + j];
  memset(mem, -1, sizeof mem);
  printf("%d", solve(0, k));
  return 0;
}
