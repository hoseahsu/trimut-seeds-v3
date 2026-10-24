#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int k, d, t;
  long double itime = 0.0;
  long double loop, partfin;
  cin >> k >> d >> t;
  if (k % d == 0)
    cout << setprecision(12) << fixed << t * 1.0;
  else {
    loop = 2 * t * 1.0 / (k + (k / d + 1) * d);
    partfin = ((k + (k / d + 1) * d) / (2 * t * 1.0)) * floor(loop);
    itime = (floor(loop)) * ((k / d + 1) * d);
    if (k * 1.0 / t >= 1 - partfin && partfin < 1) {
      itime += ((t * (1 - partfin)) * 1.0 / k) * k;
      partfin +=
          ((((t * (1 - partfin)) * 1.0 / k) * k) * 1.0 / k) * (k * 1.0 / t);
    } else if (partfin < 1) {
      itime += k;
      partfin += k * 1.0 / t;
      float x = (((k / d + 1) * d) - k) * 1.0;
      if (x / (2 * t) >= 1 - partfin) {
        itime += ((2 * t * (1 - partfin)) * 1.0 / x) * x;
      }
    }
    cout << setprecision(12) << fixed << itime;
  }
  return 0;
}
