#include <bits/stdc++.h>
using namespace std;
long long arr[10003], ans = 99999999999, n;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  n = 2 * n;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      v.clear();
      long long sum = 0;
      for (long long k = 1; k <= n; k++) {
        if (k == i || k == j) continue;
        v.push_back(arr[k]);
      }
      sort(v.begin(), v.end());
      for (long long id = 0; id < v.size(); id += 2) {
        long long x = abs(v[id] - v[id + 1]);
        sum += x;
      }
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
