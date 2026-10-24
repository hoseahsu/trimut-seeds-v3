#include <bits/stdc++.h>
using namespace std;
int a[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", (n < 12) ? a[n] : 292 + (n - 11) * 49);
  return 0;
}
