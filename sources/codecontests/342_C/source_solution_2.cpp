#include <bits/stdc++.h>
int main() {
  int R, H;
  while (scanf("%d%d", &R, &H) != EOF) {
    int ans = H / R * 2;
    H -= ans * R / 2;
    if (H * 2 < R)
      ans++;
    else {
      if ((double)(2 * H) < sqrt(3.0) * (double)R)
        ans += 2;
      else
        ans += 3;
    }
    printf("%d\n", ans);
  }
  return 0;
}
