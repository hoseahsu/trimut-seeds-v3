#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n / 2; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n / 2 + 1);
    for (int i = 1; i <= n / 2; i++) {
      ans1 += abs(i * 2 - 1 - a[i]);
      ans2 += abs(i * 2 - a[i]);
    }
    printf("%d\n", min(ans1, ans2));
  }
  return 0;
}
