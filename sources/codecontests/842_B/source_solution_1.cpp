#include <bits/stdc++.h>
int main() {
  int pizza_r, crust_w, n;
  std::cin >> pizza_r >> crust_w >> n;
  int x[n];
  int y[n];
  int r[n];
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i] >> r[i];
  }
  int R = pizza_r - crust_w;
  int R_2 = R * R;
  int ans = 0;
  int L_2;
  bool F, S;
  for (int i = 0; i < n; i++) {
    L_2 = x[i] * x[i] + y[i] * y[i];
    F = false;
    S = false;
    if (L_2 >= R_2 + 2 * R * r[i] + r[i] * r[i]) F = true;
    if (pizza_r >= sqrt(L_2) + r[i]) S = true;
    if (F && S) ans++;
  }
  std::cout << ans;
  return 0;
}
