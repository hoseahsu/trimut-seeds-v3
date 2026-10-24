#include <bits/stdc++.h>
using namespace std;
const int limit = 1000000;
void maximize(long long int &a, long long int b) { a = max(a, b); }
int n;
long long int a[limit];
long long int sa[limit];
long long int sari[limit];
long long int sale[limit];
long long int b[limit];
long long int sb[limit];
long long int sbri[limit];
long long int sble[limit];
long long int sol[limit];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sa[i] = sa[i - 1] + a[i];
    sari[i] = sari[i - 1] + i * a[i];
  }
  for (int i = 1; i <= n; i++)
    sale[n - i + 1] = sale[n - i + 2] + a[n - i + 1] * i;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sb[i] = sb[i - 1] + b[i];
    sbri[i] = sbri[i - 1] + i * b[i];
  }
  for (int i = 1; i <= n; i++)
    sble[n - i + 1] = sble[n - i + 2] + b[n - i + 1] * i;
  sol[n] = b[n];
  for (int i = n - 1; i >= 1; i--) {
    if (i <= n - 2)
      maximize(sol[i], b[i] + 2 * b[i + 1] + 3 * a[i + 1] + sol[i + 2] +
                           4 * (sa[n] - sa[i + 1] + sb[n] - sb[i + 1]));
    maximize(sol[i], sari[n] - sari[i - 1] - i * (sa[n] - sa[i - 1]) +
                         (sble[i] - sble[n + 1]) +
                         (n - i) * (sb[n] - sb[i - 1]));
    maximize(sol[i], b[i] + sbri[n] - sbri[i] + (1 - i) * (sb[n] - sb[i]) +
                         (sale[i + 1] - sale[n + 1]) +
                         (1 + n - i) * (sa[n] - sa[i]));
  }
  cout << sol[1] << endl;
}
