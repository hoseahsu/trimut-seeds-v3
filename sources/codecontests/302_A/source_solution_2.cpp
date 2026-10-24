#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, t;
  scanf("%d %d", &n, &t);
  int x, i, a, b, cnt1 = 0, cnt2 = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x == 1)
      ++cnt1;
    else
      ++cnt2;
  }
  while (t--) {
    scanf("%d %d", &a, &b);
    int len = (abs(a - b) + 1);
    if (len % 2)
      cout << "0\n";
    else {
      if (cnt1 >= (len / 2) && cnt2 >= (len / 2))
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
  return 0;
}
