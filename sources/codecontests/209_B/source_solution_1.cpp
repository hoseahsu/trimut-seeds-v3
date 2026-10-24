#include <bits/stdc++.h>
using namespace std;
long long a[3];
int main() {
  long long ans;
  while (scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF) {
    sort(a, a + 3);
    ans = a[2];
    if ((a[0] + a[1]) % 2 == 0) {
      ans = min(ans, a[1]);
    }
    if ((a[1] + a[2]) % 2 == 0) {
      ans = min(ans, a[2]);
    }
    if ((a[0] + a[2]) % 2 == 0) {
      ans = min(ans, a[2]);
    }
    cout << ans << endl;
  }
}
