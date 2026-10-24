#include <bits/stdc++.h>
using namespace std;
inline int IN() {
  int x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int X1, Y1, X2, Y2, dh, sh;
int main() {
  X1 = IN(), Y1 = IN(), X2 = IN(), Y2 = IN();
  dh = (Y2 - Y1 + 1) / 2 + 1, sh = (Y2 - Y1) / 2;
  printf("%I64d\n", 1ll * dh * ((X2 - X1) / 2 + 1) + 1ll * sh * (X2 - X1) / 2);
}
