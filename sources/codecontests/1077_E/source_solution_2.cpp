#include <bits/stdc++.h>
using namespace std;
long long N, M, a, b, c;
int inp[300005];
map<int, int> mp;
vector<int> v;
long long pow2[200005];
long long ans;
int chk(long long x) {
  int t = 0;
  int start = -1;
  while (1) {
    int idx = lower_bound(v.begin() + start + 1, v.end(), x) - v.begin();
    if (idx == v.size()) break;
    start = idx;
    t++;
    x *= 2;
  }
  return t;
}
int main() {
  pow2[0] = 1;
  scanf("%lld", &N);
  for (int i = 1; i <= N; i++) {
    pow2[i] = pow2[i - 1] * 2;
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", inp + i);
    mp[inp[i]]++;
  }
  for (auto &it : mp) {
    v.push_back(it.second);
  }
  sort(v.begin(), v.end());
  for (int n = 1; n <= v.size(); n++) {
    long long l = 0, r = 2e5 + 5;
    while (l + 1 < r) {
      long long mid = l + r >> 1;
      if (chk(mid) >= n)
        l = mid;
      else
        r = mid;
    }
    if (l == 0) continue;
    long long ret = l * (pow2[n] - 1);
    ans = max(ans, ret);
  }
  printf("%lld", ans);
}
