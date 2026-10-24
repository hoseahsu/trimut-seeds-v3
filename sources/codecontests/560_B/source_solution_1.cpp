#include <bits/stdc++.h>
using namespace std;
bool fit(int a1, int b1, int a2, int b2) {
  if ((max(a1, b1) < max(a2, b2)) || (min(a1, b1) < min(a2, b2))) {
    return false;
  }
  return true;
}
int main(int argc, const char* argv[]) {
  int a1, b1, a2, b2, a3, b3;
  scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
  if (!fit(a1, b1, a2, b2)) {
    printf("NO");
    return 0;
  }
  if (!fit(a1, b1, a3, b3)) {
    printf("NO");
    return 0;
  }
  if (a1 >= a2 && b1 >= b2) {
    if (fit(a1 - a2, b1, a3, b3) || fit(a1, b1 - b2, a3, b3)) {
      printf("YES");
      return 0;
    }
  }
  swap(a2, b2);
  if (a1 >= a2 && b1 >= b2) {
    if (fit(a1 - a2, b1, a3, b3) || fit(a1, b1 - b2, a3, b3)) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
