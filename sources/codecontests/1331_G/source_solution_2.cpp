#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[11];
  for (long long int i = 0; i < 11; i++) cin >> a[i];
  int k = 10;
  for (long long int i = 0; i < 11; i++) {
    double ans = 5.0 * a[10 - i] * a[10 - i] * a[10 - i] + sqrt(abs(a[10 - i]));
    if (ans < 400)
      cout << "f(" << a[k--] << ") = " << fixed << setprecision(2) << ans
           << endl;
    else
      cout << "f(" << a[k--] << ") = "
           << "MAGNA NIMIS!" << endl;
  }
  return 0;
}
