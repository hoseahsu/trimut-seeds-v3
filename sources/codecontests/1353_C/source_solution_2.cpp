#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << 4 * (n / 2) * (n / 2 + 1) * (2 * (n / 2) + 1) / 3 << endl;
  }
}
