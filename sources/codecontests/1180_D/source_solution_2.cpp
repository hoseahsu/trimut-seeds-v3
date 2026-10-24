#include <bits/stdc++.h>
using namespace std;
int rows, cols;
int r1, c1, r2, c2;
int dir = 1;
int main() {
  cin >> rows >> cols;
  r1 = c1 = 1, r2 = rows, c2 = cols;
  for (int i = 1; i <= (rows * cols + 1) / 2; i++) {
    printf("%d %d\n", r1, c1);
    if (r1 == r2 && c1 == c2) {
      break;
    }
    printf("%d %d\n", r2, c2);
    c1 += dir, c2 -= dir;
    if (c1 > cols) {
      c1 = 1, c2 = cols;
      r1++, r2--;
    }
  }
  return 0;
}
