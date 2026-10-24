#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1000;
long long v[N];
long long binarysearch(long long h, long long lo, long long hi) {
  long long ans = 1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (v[mid] < h) {
      lo = mid + 1;
    } else if (v[mid] > h) {
      hi = mid - 1;
    } else {
      ans = 0;
      break;
    }
  }
  return ans;
}
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long b1, q, l, m;
  cin >> b1 >> q >> l >> m;
  long long tmp = b1;
  long long ans = 0;
  for (long long i = 1; i <= m; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + m + 1);
  bool f = false;
  long long cnt = 0;
  while (1) {
    cnt += 1;
    if (f) {
      b1 = tmp * q;
    }
    if (cnt > N) {
      if (ans > 1000) {
        ans = -1;
      }
      break;
    }
    f = true;
    if (abs(b1) <= l) {
      if (binarysearch(b1, 1, m)) {
        ans += 1;
        tmp = b1;
      } else {
        tmp = b1;
      }
    } else {
      break;
    }
  }
  if (ans == -1) {
    cout << "inf" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
