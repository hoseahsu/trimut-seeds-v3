#include <bits/stdc++.h>
using namespace std;
const long long maxn = (long long)3e5 + 7;
long long a[maxn];
long long b[maxn];
long long pos[maxn];
struct node {
  long long x, y;
} ans[maxn * 5];
signed main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    pos[a[i]] = i;
  }
  long long cnt = 0;
  for (long long i = 1; i <= n / 2; i++) {
    if (pos[i] == i) continue;
    if (i == 1) {
      if (pos[1] > n / 2) {
        ans[++cnt] = {1, pos[1]};
        long long temp = pos[1];
        swap(pos[a[1]], pos[1]);
        swap(a[temp], a[1]);
      } else {
        ans[++cnt] = {1, n};
        ans[++cnt] = {pos[1], n};
        ans[++cnt] = {1, n};
        long long temp = pos[1];
        swap(pos[a[1]], pos[1]);
        swap(a[temp], a[1]);
      }
      continue;
    }
    if (abs(pos[i] - i) >= n / 2) {
      ans[++cnt] = {i, pos[i]};
      long long temp = pos[i];
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    } else if (pos[i] <= n / 2) {
      long long temp = pos[i];
      ans[++cnt] = {i, n};
      ans[++cnt] = {pos[i], n};
      ans[++cnt] = {i, n};
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    } else {
      ans[++cnt] = {pos[i], 1};
      ans[++cnt] = {i, n};
      ans[++cnt] = {1, n};
      ans[++cnt] = {i, n};
      ans[++cnt] = {pos[i], 1};
      long long temp = pos[i];
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    }
  }
  for (long long i = n / 2 + 1; i <= n; i++) {
    if (pos[i] == i) continue;
    ans[++cnt] = {i, 1};
    ans[++cnt] = {pos[i], 1};
    ans[++cnt] = {i, 1};
    long long temp = pos[i];
    swap(pos[a[i]], pos[i]);
    swap(a[temp], a[i]);
  }
  cout << cnt << endl;
  for (long long i = 1; i <= cnt; i++) {
    cout << ans[i].x << " " << ans[i].y << endl;
  }
  return 0;
}
