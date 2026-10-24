#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 50 + 10;
int n, x[N], y[N];
void solve(int* x) {
  for (int i = 1; i < n; ++i) putchar('(');
  for (int i = 1; i <= n; ++i) {
    if (i >= 2) putchar('+');
    printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x[i] >> 1, i, i);
    if (i >= 2) putchar(')');
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) x[i] = read(), y[i] = read(), read();
  solve(x), puts(""), solve(y), puts("");
  return 0;
}
