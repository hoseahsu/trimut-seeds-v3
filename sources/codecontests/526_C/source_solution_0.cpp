#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, h1, h2, w1, w2;
  cin >> c >> h1 >> h2 >> w1 >> w2;
  if (w1 < w2) {
    swap(w1, w2);
    swap(h1, h2);
  }
  long long ans = 0;
  if (w1 >= sqrt(c)) {
    for (int i = 0; i <= c / w1; i++) {
      ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
    }
  } else {
    if (h1 * w2 > h2 * w1) {
      swap(w1, w2);
      swap(h1, h2);
    }
    for (int i = 0; i <= w2; i++) {
      ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
