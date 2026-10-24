#include <bits/stdc++.h>
using namespace std;
long long mark[5010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(), cout.tie();
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b, c = 0;
    cin >> n;
    a = n % 14;
    if (a >= 1 && a <= 6 && n >= 15)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
