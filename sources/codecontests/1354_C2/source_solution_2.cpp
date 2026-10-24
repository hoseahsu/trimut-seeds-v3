#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << fixed << setprecision(9)
         << cos(3.14159265358979323846 / (4 * n)) /
                sin(3.14159265358979323846 / (2 * n))
         << "\n";
  }
  return 0;
}
