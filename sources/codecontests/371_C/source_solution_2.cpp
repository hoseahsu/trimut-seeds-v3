#include <bits/stdc++.h>
using namespace std;
string ham;
long long cb, cs, cc;
long long pb, ps, pc;
long long nb, ns, nc;
long long r;
int main() {
  cin >> ham;
  for (int i = 0; i < ham.size(); i++) {
    if (ham[i] == 'B') cb++;
    if (ham[i] == 'S') cs++;
    if (ham[i] == 'C') cc++;
  }
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  long long lp = 0, rp = 1E13;
  while (lp < rp) {
    long long mid = (lp + rp + 1) / 2;
    long long cost = max(0LL, cb * mid - nb) * pb +
                     max(0LL, cs * mid - ns) * ps +
                     max(0LL, cc * mid - nc) * pc;
    if (cost <= r)
      lp = mid;
    else
      rp = mid - 1;
  }
  cout << rp << '\n';
}
