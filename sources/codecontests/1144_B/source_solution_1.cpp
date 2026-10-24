#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, odd = 0, even = 0, res = 0, i;
  cin >> n;
  int arr[n], evenArr[n], oddArr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    if (arr[i] % 2) {
      evenArr[even++] = arr[i];
    } else {
      oddArr[odd++] = arr[i];
    }
  }
  if (even > odd) {
    even -= odd;
    for (i = 0; i < even - 1; i++) {
      res += evenArr[i];
    }
  } else if (odd > even) {
    odd -= even;
    for (i = 0; i < odd - 1; i++) {
      res += oddArr[i];
    }
  } else {
    res = 0;
  }
  cout << res << endl;
  return 0;
}
