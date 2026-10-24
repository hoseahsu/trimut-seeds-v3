#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, a[6005], s;
bool check(int x) {
  if (x <= 1) return 0;
  int i;
  for (i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void solve(int x) {
  int i;
  for (((i)) = ((n)); ((i)) >= (1); ((i))--)
    if (i <= x && !a[i]) {
      a[i] = 1;
      x -= i;
    }
}
void solve2(int s) {
  int i;
  for (((i)) = (1); ((i)) <= ((s - 1)); ((i))++)
    if (check(i) && check(s - i)) {
      solve(i);
      int t = 0;
      for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
        printf("%d ", a[i] + 1);
      }
      exit(0);
    }
}
int main() {
  read(n);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) s += i;
  if (check(s)) {
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) printf("1 ");
    return 0;
  }
  if (s % 2 == 0) solve2(s);
  if (check(s - 2)) {
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) printf("%d ", (i == 2 ? 2 : 1));
    return 0;
  }
  for (i = n;; i--)
    if (check(i)) {
      a[i] = 2;
      solve2(s - i);
    }
  return 0;
}
