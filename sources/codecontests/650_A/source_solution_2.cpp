#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[212345];
int main() {
  int i, j, k, n, s;
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) {
      scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    int pre = a[i].first, cnt = 0;
    long long ans = 0;
    for (i = 0; i < n; i++) {
      if (a[i].first == pre) {
        cnt++;
      } else {
        pre = a[i].first;
        ans += cnt * 1LL * (cnt - 1) / 2;
        cnt = 1;
      }
    }
    ans += cnt * 1LL * (cnt - 1) / 2;
    for (i = 0; i < n; i++) {
      swap(a[i].first, a[i].second);
    }
    sort(a, a + n);
    pre = a[i].first;
    cnt = 0;
    for (i = 0; i < n; i++) {
      if (a[i].first == pre) {
        cnt++;
      } else {
        pre = a[i].first;
        ans += cnt * 1LL * (cnt - 1) / 2;
        cnt = 1;
      }
    }
    ans += cnt * 1LL * (cnt - 1) / 2;
    int x = a[i].first, y = a[i].second;
    cnt = 0;
    for (i = 0; i < n; i++) {
      if (a[i].first == x && a[i].second == y) {
        cnt++;
      } else {
        x = a[i].first;
        y = a[i].second;
        ans -= cnt * 1LL * (cnt - 1) / 2;
        cnt = 1;
      }
    }
    ans -= cnt * 1LL * (cnt - 1) / 2;
    cout << ans << endl;
  }
}
