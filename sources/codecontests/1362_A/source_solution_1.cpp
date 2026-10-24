#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int cnt = 0;
    while (a % 2 == 0 && a > b) {
      a /= 2;
      cnt++;
    }
    if (a != b)
      printf("-1\n");
    else {
      int ans = cnt / 3;
      cnt %= 3;
      ans += cnt / 2;
      cnt %= 2;
      ans += cnt;
      printf("%d\n", ans);
    }
  }
}
