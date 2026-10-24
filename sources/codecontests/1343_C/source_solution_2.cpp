#include <bits/stdc++.h>
using namespace std;
long long int solve(int *arr, int n) {
  long long int sum = 0;
  bool p;
  if (arr[0] > 0) {
    p = true;
  } else {
    p = false;
  }
  for (int i = 0; i < n;) {
    if (p) {
      int mx = INT_MIN;
      while (i < n && arr[i] > 0) {
        mx = max(mx, arr[i]);
        i++;
      }
      sum += mx;
      p = !p;
    } else {
      int mx = INT_MIN;
      while (i < n && arr[i] < 0) {
        mx = max(mx, arr[i]);
        i++;
      }
      sum += mx;
      p = !p;
    }
  }
  return sum;
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(arr, n) << "\n";
  }
  return 0;
}
