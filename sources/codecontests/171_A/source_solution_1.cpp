#include <bits/stdc++.h>
int main() {
  int a, b, k = 0;
  std::cin >> a >> b;
  while (b > 0) {
    k = k * 10 + b % 10;
    b /= 10;
  }
  std::cout << a + k;
}
