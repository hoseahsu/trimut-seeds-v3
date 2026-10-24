#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, result;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (k % a == 0) result = min(result, k / a);
  }
  printf("%d\n", result);
  return 0;
}
