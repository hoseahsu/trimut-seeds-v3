#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d", &a);
  b = a % 4;
  if (b == 0) {
    printf("1 A");
  } else if (b == 1) {
    printf("0 A");
  } else if (b == 2) {
    printf("1 B");
  } else if (b == 3) {
    printf("2 A");
  }
  return 0;
}
