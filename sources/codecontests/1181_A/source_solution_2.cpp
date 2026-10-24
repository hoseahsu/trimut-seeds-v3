#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y, z;
  cin >> x >> y >> z;
  if (x % z == 0 && y % z == 0) {
    cout << (x / z) + (y / z) << " " << 0 << "\n";
    return 0;
  } else {
    if (x % z == 0 || y % z == 0) {
      cout << (x / z) + (y / z) << " " << 0 << "\n";
      return 0;
    } else {
      long long t1 = x % z;
      long long t2 = y % z;
      if ((t1 + t2) % z == 0) {
        long long k = t1 <= t2 ? t1 : t2;
        cout << (x / z) + (y / z) + (t1 + t2) / z << " " << k << "\n";
        return 0;
      } else {
        long long k = (t1 + t2) / z;
        long long s = t1 >= t2 ? t1 : t2;
        long long r = k * z - s;
        if (k >= 1)
          cout << (x / z) + (y / z) + k << " " << r << "\n";
        else
          cout << (x / z) + (y / z) << " " << 0 << "\n";
        return 0;
      }
    }
  }
  return 0;
}
