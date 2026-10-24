#include <bits/stdc++.h>
using namespace std;
int main() {
  int z, o;
  scanf("%d %d", &z, &o);
  int max1 = 4 + 2 * (z - 1);
  if ((o < z - 1) || (o > max1)) {
    puts("-1");
    return 0;
  }
  int mid = z - 1, rem = o - mid;
  if (rem > 4) mid += rem - 4, rem = 4;
  int exr = mid - z + 1;
  for (__typeof(rem / 2) i = 0; i < rem / 2; ++i) printf("1");
  for (__typeof(z) i = 0; i < z; ++i) {
    if (i) {
      printf("1");
      if (exr > 0) exr--, printf("1");
    }
    printf("0");
  }
  for (__typeof(rem - (rem / 2)) i = 0; i < rem - (rem / 2); ++i) printf("1");
  return 0;
}
