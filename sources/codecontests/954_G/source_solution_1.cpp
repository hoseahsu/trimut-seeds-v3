#include <bits/stdc++.h>
using namespace std;
long long int arr[500005], b[500005];
long long int n, r, k;
bool check(long long int x) {
  memcpy(b, arr, sizeof(arr));
  long long int sum = 0, cnt = k;
  int lo = 1, hi = 1;
  for (int i = 1; i <= n; i++) {
    while (lo < max(1 * 1ll, i - r)) {
      sum -= b[lo];
      lo++;
    }
    while (hi <= min(n, i + r)) {
      sum += b[hi];
      hi++;
    }
    if (sum < x) {
      if (cnt >= x - sum) {
        cnt -= x - sum;
        b[hi - 1] += x - sum;
        sum += x - sum;
      } else
        return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> r >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  long long int low = 0, high = 2e18, ans = 0;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans;
  return 0;
}
