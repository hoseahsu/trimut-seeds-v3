#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
T maxm(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T minm(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T abs(T a) {
  return a > 0 ? a : (-1) * a;
}
template <class T>
T sq(T a) {
  return a * a;
}
char s[200005];
int main() {
  int n, f = 0, in = 0, a = 0;
  char ch;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%c", &ch);
    if (ch == 'A')
      a++;
    else if (ch == 'F')
      f++;
    else
      in++;
  }
  if (in == 1)
    cout << 1;
  else if (in > 1)
    cout << 0;
  else if (in == 0)
    cout << a;
  return 0;
}
