#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
double eps = 1e-10;
long long INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 10;
const int maxn = 1e5 + 10;
long long inf = 100000000000000;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double pi = 2 * acos(0.0);
    double a = 0.5 / sin(pi / n / 2.0);
    double ans = a * cos(pi / 4.0 / n);
    ans = ans * 2;
    cout << fixed;
    cout << setprecision(8);
    cout << ans << endl;
  }
}
