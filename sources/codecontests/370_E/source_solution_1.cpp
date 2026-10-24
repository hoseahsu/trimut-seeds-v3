#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ret[200005], cnt[200005];
pair<int, int> lb[200005], ub[200005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (a[1] > 1) return puts("-1");
  lb[1] = ub[1] = make_pair(1, 1);
  for (int i = 2; i <= n; i++) {
    lb[i] = lb[i - 1];
    lb[i].second++;
    ub[i] = ub[i - 1];
    ub[i].second++;
    if (lb[i].second > 5) {
      lb[i].first++;
      lb[i].second = 1;
    }
    if (ub[i].second > 2) {
      ub[i].first++;
      ub[i].second = 1;
    }
    if (a[i]) {
      if (!(lb[i].first <= a[i] && a[i] <= ub[i].first)) {
        return puts("-1");
      }
      lb[i] = max(lb[i], make_pair(a[i], 1));
      ub[i] = min(ub[i], make_pair(a[i], 5));
    }
  }
  pair<int, int> ans = ub[n];
  if (ans.second == 1) {
    ans.first--;
    ans.second = 5;
  }
  if (ans < lb[n]) return puts("-1");
  ret[n] = ans.first;
  cnt[ans.first] = 1;
  printf("%d\n", ans.first);
  for (int i = n - 1; i >= 1; i--) {
    ret[i] = min(ret[i + 1], ub[i].first);
    if (cnt[ret[i]] == 5) {
      ret[i]--;
    }
    cnt[ret[i]]++;
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ret[i], i == n ? '\n' : ' ');
}
