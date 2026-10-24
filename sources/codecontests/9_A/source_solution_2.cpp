#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  a = max(a, b);
  b = 6 - a;
  if (b == 0 || b == 4)
    printf("%d/%d", b + 1, 6);
  else if (b == 1)
    printf("1/3");
  else if (b == 2)
    printf("1/2");
  else if (b == 3)
    printf("2/3");
  else
    printf("1/1");
  return 0;
}
