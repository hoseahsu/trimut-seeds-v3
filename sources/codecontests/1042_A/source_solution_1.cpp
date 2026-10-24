#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int temp = arr[n - 1];
  int maxx = arr[n - 1] + m;
  int minn = 0;
  for (int i = 0; i < n; i++) {
    int t = temp - arr[i];
    if (t <= m) {
      arr[i] += (t);
      m -= (t);
    } else {
      arr[i] += m;
      m = 0;
      break;
    }
  }
  minn = (m % n) == 0 ? arr[n - 1] + (m / n) : arr[n - 1] + (m / n) + 1;
  cout << minn << " " << maxx << endl;
  return 0;
}
