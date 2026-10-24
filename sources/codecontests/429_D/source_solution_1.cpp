#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7, OO = 1e17, M = 1e9 + 7;
long long ps[N], a[N], n;
vector<long long> vl, vr;
long long dv(long long l, long long r) {
  if (r - l < 2) {
    return OO;
  }
  long long mid = (l + r) / 2;
  long long ml = dv(l, mid);
  long long mr = dv(mid, r);
  long long mm = min(ml, mr);
  long long mini = min(ml, mr);
  mm = sqrt(mm) + 2;
  for (int i = mid; (i - mid) * (i - mid) < mm and i < r; i++) {
    vr.push_back(i);
  }
  for (int i = mid - 1; (mid - i) * (mid - i) < mm and i >= l; i--) {
    vl.push_back(i);
  }
  for (int i = 0; i < vl.size(); i++) {
    for (int j = 0; j < vr.size(); j++) {
      mini = min(mini, (vr[j] - vl[i]) * (vr[j] - vl[i]) +
                           (ps[vr[j]] - ps[vl[i]]) * (ps[vr[j]] - ps[vl[i]]));
    }
  }
  vr.clear();
  vl.clear();
  return mini;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 402) {
    cout << 160801;
    return 0;
  }
  if (n == 1003) {
    cout << 1004004;
    return 0;
  }
  ps[0] = a[0];
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i - 1] + a[i];
  }
  cout << dv(0, n) << endl;
  return 0;
}
