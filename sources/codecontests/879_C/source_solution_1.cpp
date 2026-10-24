#include <bits/stdc++.h>
using namespace std;
int n;
void clean() {}
void solve() {
  clean();
  int a = 0, b = 1023;
  for (int x, i = 1; i <= n; i++) {
    char s[5];
    scanf("%s %d", s, &x);
    switch (s[0]) {
      case '^':
        a ^= x, b ^= x;
        break;
      case '|':
        a |= x, b |= x;
        break;
      case '&':
        a &= x, b &= x;
        break;
    }
  }
  int A = 1023, X = 0, O = 0, bs = 1;
  for (int i = 0; i < 10; i++) {
    int taki = a & 1, mitsuha = b & 1;
    if (taki == 0) {
      if (mitsuha == 0) A -= bs;
      if (mitsuha == 1)
        ;
    } else if (taki == 1) {
      if (mitsuha == 0) X += bs;
      if (mitsuha == 1) O += bs;
    }
    a >>= 1, b >>= 1, bs <<= 1;
  }
  printf("3\n| %d\n^ %d\n& %d\n", O, X, A);
}
int main() {
  scanf("%d", &n), solve();
  return 0;
}
