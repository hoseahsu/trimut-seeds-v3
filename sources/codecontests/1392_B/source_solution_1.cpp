#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n], arr1[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long maxi = *max_element(arr, arr + n);
    for (long long i = 0; i < n; i++) {
      arr[i] = maxi - arr[i];
    }
    maxi = *max_element(arr, arr + n);
    for (long long i = 0; i < n; i++) arr1[i] = maxi - arr[i];
    if (k % 2 == 1) {
      for (long long i = 0; i < n; i++) cout << arr[i] << " ";
      cout << "\n";
    } else {
      for (long long i = 0; i < n; i++) cout << arr1[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}
