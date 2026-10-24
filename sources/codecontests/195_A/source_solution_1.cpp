#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, ans;
  while (~scanf("%d%d%d", &a, &b, &c)) {
    ans = (a * c - b * c + b - 1) / b;
    printf("%d\n", ans);
  }
  return 0;
}
