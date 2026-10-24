#include <bits/stdc++.h>
using namespace std;
int n, x, ind = 1, ans = 0;
char a[20], h[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main() {
  cin >> x;
  if (x == 0) {
    cout << "1" << endl;
    return 0;
  }
  while (x) {
    a[ind++] = h[(x % 16)];
    x /= 16;
  }
  for (int i = ind - 1; i >= 1; i--) {
    if (a[i] == '0' || a[i] == '4' || a[i] == '6' || a[i] == '9' ||
        a[i] == 'A' || a[i] == 'D')
      ans++;
    if (a[i] == '8' || a[i] == 'B') ans += 2;
  }
  cout << ans << endl;
  return 0;
}
