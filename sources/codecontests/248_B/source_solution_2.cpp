#include <bits/stdc++.h>
using namespace std;
int n, t = 50;
int main() {
  cin >> n;
  if (n == 1 || n == 2) {
    printf("-1\n");
    return 0;
  }
  if (n == 3) {
    printf("210\n");
    return 0;
  }
  printf("1");
  for (int i = 1; i <= n - 4; i++) {
    cout << "0";
    t = t * 10 % 210;
  }
  printf("%03d\n", t);
  return 0;
}
