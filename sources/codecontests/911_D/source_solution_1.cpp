#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
int a[1505];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i] > a[j]) ans++;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int x = r - l + 1;
    x = x * (x - 1) / 2;
    if (x % 2) ans++;
    if (ans % 2)
      cout << "odd" << endl;
    else
      cout << "even" << endl;
  }
}
