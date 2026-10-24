#include <bits/stdc++.h>
using namespace std;
int m, n, x;
bool read() {
  if (scanf("%d%d%d", &n, &m, &x) == EOF) return false;
  return true;
}
void process() {
  x--;
  int a = n - x * 2;
  int b = m - x * 2;
  int aa = a - 2;
  int bb = b - 2;
  a = max(a, 0);
  b = max(b, 0);
  aa = max(aa, 0);
  bb = max(bb, 0);
  int res = (a * b + 1) / 2 - (aa * bb + 1) / 2;
  printf("%d\n", res);
}
int main() {
  int t = -1;
  while (t-- && read()) process();
  return 0;
}
