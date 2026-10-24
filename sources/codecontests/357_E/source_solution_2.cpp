#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  int n, m, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a[k]++;
    sum += k;
  }
  if (sum < 3 || sum == 5) {
    cout << -1;
    return 0;
  }
  int cnt = 0;
  if (a[1] >= a[2]) {
    cnt += a[2];
    a[3] += a[2];
    a[1] -= a[2];
    a[2] = 0;
    if (a[1] == 1 && a[3] == 0)
      cnt += 2;
    else
      cnt += a[1] / 3 * 2 + (a[1] % 3);
  } else {
    cnt += a[1];
    a[3] += a[1];
    a[2] -= a[1];
    a[1] = 0;
    cnt += a[2] / 3 * 2;
    if (a[2] % 3 == 2)
      cnt += 2;
    else if (a[2] % 3 == 1)
      if (a[4])
        cnt++;
      else
        cnt += 2;
  }
  cout << cnt;
  return 0;
}
