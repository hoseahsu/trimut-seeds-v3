#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, ans = 0;
  t = 1;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long int ans = ceil(((a - b) * (double)c) / (double)b);
    cout << ans << endl;
  }
}
