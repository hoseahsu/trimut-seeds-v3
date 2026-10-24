#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, I;
  cin >> n >> I;
  vector<int> arr(n), all;
  for (int i = 0; i < n; i++) cin >> arr[i];
  all = arr;
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 0; i < n; i++)
    arr[i] = lower_bound(all.begin(), all.end(), arr[i]) - all.begin();
  sort(arr.begin(), arr.end());
  int mk = I * 8 / n;
  if (mk >= 20) {
    cout << "0\n";
    return 0;
  }
  mk = 1 << mk;
  int ans = 1e9;
  for (int i = 0; i < all.size(); i++) {
    int l = i, r = l + mk - 1;
    ans = min((int)(lower_bound(arr.begin(), arr.end(), l) - arr.begin() +
                    arr.end() - upper_bound(arr.begin(), arr.end(), r)),
              ans);
  }
  cout << ans << '\n';
  return 0;
}
