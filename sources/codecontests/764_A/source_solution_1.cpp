#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, z;
  scanf("%d %d %d", &n, &m, &z);
  int cnt = 0;
  for (int i = 1; i <= z; ++i) {
    if (i % n == 0 && i % m == 0) ++cnt;
  }
  printf("%d", cnt);
  return 0;
}
