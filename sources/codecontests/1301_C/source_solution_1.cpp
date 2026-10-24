#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int x1 = ((n - m) / (m + 1)), nog = m + 1;
    cout << (((n * (n + 1)) / 2) - (((x1 * (x1 + 1)) / 2) * nog) -
             (x1 + 1) * ((n - m) % (m + 1)))
         << endl;
  }
}
