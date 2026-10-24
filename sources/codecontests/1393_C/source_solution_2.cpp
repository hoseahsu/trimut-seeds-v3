#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    map<long long int, long long int> mp1;
    long long int maxi = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      mp1[a[i]]++;
      maxi = max(maxi, mp1[a[i]]);
    }
    long long int rem = 0, part;
    for (auto it : mp1) {
      if (it.second == maxi) rem++;
    }
    long long int ans = rem - 1;
    part = maxi - 1;
    long long int total = n - rem * maxi;
    ans += total / part;
    cout << ans << '\n';
  }
  return 0;
}
