#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, long long>> a(n);
  vector<long long> cval;
  for (auto &i : a) {
    scanf("%lld %lld", &i.first, &i.second);
    cval.push_back(i.first);
    cval.push_back(i.second + 1);
  }
  sort(cval.begin(), cval.end());
  cval.resize(unique(cval.begin(), cval.end()) - cval.begin());
  vector<int> cnt(2 * n);
  for (auto &i : a) {
    int posl = lower_bound(cval.begin(), cval.end(), i.first) - cval.begin();
    int posr =
        lower_bound(cval.begin(), cval.end(), i.second + 1) - cval.begin();
    ++cnt[posl];
    --cnt[posr];
  }
  for (int i = 1; i < 2 * n; ++i) cnt[i] += cnt[i - 1];
  vector<long long> ans(n + 1);
  for (int i = 1; i < 2 * n; ++i) ans[cnt[i - 1]] += cval[i] - cval[i - 1];
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  puts("");
  return 0;
}
