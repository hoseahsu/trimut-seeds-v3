#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long sum = 0;
  if (a[n / 2] == m) {
    cout << 0 << endl;
    return 0;
  } else {
    sum += abs(m - a[n / 2]);
    if (a[n / 2] < m) {
      long long i = (n / 2) + 1;
      while (i < n && a[i] < m) {
        sum += (m - a[i]);
        i++;
      }
    } else {
      long long i = (n / 2) - 1;
      while (i >= 0 && a[i] > m) {
        sum += (a[i] - m);
        i--;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
