#include <cstdio>

int main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  puts(a + b + c <= 21 ? "win" : "bust");
  return 0;
}