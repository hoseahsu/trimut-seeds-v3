#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
const long long N = 100005;
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long cur = 4 * n;
    while (n) {
      cout << cur << " ";
      cur -= 2;
      n--;
    }
    cout << endl;
  }
}
