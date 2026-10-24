#include <stdio.h>
#include <algorithm>

const int N = 200005;

char a[N];

int main() {
  int n;
  scanf("%d %s", &n, a);
  int w = 0;
  for (int i = 0; i < n; i++) {
    w += (a[i] == '.');
  }
  int b = 0;
  int ans = (1 << 30);
  for (int i = 0; i < n; i++) {
    ans = std::min(ans, b + w);
    if (a[i] == '#') {
      b++;
    }
    if (a[i] == '.') {
      w--;
    }
  }
  printf("%d\n", std::min(ans, b + w));
  return 0;
}