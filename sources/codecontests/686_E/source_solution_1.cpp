#include <bits/stdc++.h>
using namespace std;
struct P {
  long long x;
  long long y;
  long long z;
  P() {}
  P(long long lx, long long ly, long long lz) {
    x = lx;
    y = ly;
    z = lz;
  }
};
const int N = 100005;
long long x[N];
long long y[N];
long long z[N];
int n;
long long solX, solY, solZ;
bool possible(long long r) {
  long long minABC = x[0] + y[0] + z[0] - r;
  long long minA = -x[0] + y[0] + z[0] - r;
  long long minB = +x[0] - y[0] + z[0] - r;
  long long minC = +x[0] + y[0] - z[0] - r;
  long long maxABC = x[0] + y[0] + z[0] + r;
  long long maxA = -x[0] + y[0] + z[0] + r;
  long long maxB = +x[0] - y[0] + z[0] + r;
  long long maxC = +x[0] + y[0] - z[0] + r;
  for (int i = 0; i < n; i++) {
    minABC = max(minABC, x[i] + y[i] + z[i] - r);
    minA = max(minA, -x[i] + y[i] + z[i] - r);
    minB = max(minB, +x[i] - y[i] + z[i] - r);
    minC = max(minC, +x[i] + y[i] - z[i] - r);
    maxABC = min(maxABC, x[i] + y[i] + z[i] + r);
    maxA = min(maxA, -x[i] + y[i] + z[i] + r);
    maxB = min(maxB, +x[i] - y[i] + z[i] + r);
    maxC = min(maxC, +x[i] + y[i] - z[i] + r);
  }
  if (minA > maxA || minB > maxB || minC > maxC ||
      maxA + maxB + maxC < minABC || minA + minB + minC > maxABC) {
    return false;
  } else {
    long long a = minA, b = minB, c = minC;
    if (a + b + c < minABC) a += min(maxA - minA, minABC - a - b - c);
    if (a + b + c < minABC) b += min(maxB - minB, minABC - a - b - c);
    if (a + b + c < minABC) c += min(maxC - minC, minABC - a - b - c);
    long long x0 = (b + c) / 2, y0 = (a + c) / 2, z0 = (a + b) / 2;
    for (long long xx = x0 - 1; xx <= x0 + 1; xx++) {
      for (long long yy = y0 - 1; yy <= y0 + 1; yy++) {
        for (long long zz = z0 - 1; zz <= z0 + 1; zz++) {
          bool good = true;
          for (int i = 0; i < n; i++) {
            long long dist = abs(x[i] - xx) + abs(y[i] - yy) + abs(z[i] - zz);
            if (dist > r) {
              good = false;
              break;
            }
          }
          if (good) {
            solX = xx;
            solY = yy;
            solZ = zz;
            return true;
          }
        }
      }
    }
    return false;
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  long long lo = -1;
  long long hi = 3000000000000000001LL;
  while (hi - lo > 4) {
    long long mid = lo + (hi - lo) / 2;
    if (possible(mid))
      hi = mid;
    else
      lo = mid;
  }
  while (hi - 1 > lo && possible(hi - 1)) hi--;
  cout << solX << " " << solY << " " << solZ << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ncase;
  cin >> ncase;
  for (int csnum = 0; csnum < ncase; csnum++) {
    solve();
  }
}
