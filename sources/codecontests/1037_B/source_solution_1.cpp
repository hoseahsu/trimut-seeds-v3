#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long s;
  cin >> n >> s;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = 0;
  if (s == a[n / 2]) {
  } else if (s > a[n / 2]) {
    int i = n / 2;
    while (s > a[i] && i < n) {
      ans += (s - a[i]);
      i++;
    }
  } else {
    int i = n / 2;
    while (s < a[i] && i >= 0) {
      ans += (a[i] - s);
      i--;
    }
  }
  cout << ans << endl;
  return 0;
}
