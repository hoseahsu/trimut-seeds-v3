#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    s += x;
  }
  n++;
  int ans = 5;
  for (int i = 1; i <= 5; i++)
    if ((s + i) % n == 1) ans--;
  cout << ans;
  return 0;
}
