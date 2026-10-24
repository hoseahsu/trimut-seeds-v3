#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    int cnt = 0;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      cnt += x / k;
      if (x % k != 0) cnt++;
    }
    if (cnt % 2 == 0)
      cout << cnt / 2 << endl;
    else
      cout << (cnt) / 2 + 1 << endl;
  }
  return 0;
}
