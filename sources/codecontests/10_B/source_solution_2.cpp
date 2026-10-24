#include <bits/stdc++.h>
int diru[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirv[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
template <class T>
T sq(T n) {
  return n * n;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
bool inside(T a, T b, T c) {
  return a <= b && b <= c;
}
template <class T>
void setmax(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void setmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
int n;
int val[102][102];
void cal(int s) {
  int ret = (1 << 29), i, j, x, yl, yr, k;
  for (i = 0; i < n; i++) {
    int cnt = 0;
    int cur = (((n >> 1) - i) < 0 ? (-((n >> 1) - i)) : ((n >> 1) - i)) * s;
    for (j = 0; j < s; j++) {
      cnt += val[i][j];
      cur += (((n >> 1) - j) < 0 ? (-((n >> 1) - j)) : ((n >> 1) - j));
    }
    j = 0;
    k = s - 1;
    while (k < n) {
      if (cnt == 0) {
        if (ret > cur) {
          ret = cur;
          x = i;
          yl = j;
          yr = k;
        }
      }
      cnt -= val[i][j];
      cur -= (((n >> 1) - j) < 0 ? (-((n >> 1) - j)) : ((n >> 1) - j));
      j++;
      k++;
      cnt += val[i][k];
      cur += (((n >> 1) - k) < 0 ? (-((n >> 1) - k)) : ((n >> 1) - k));
    }
  }
  if (ret == (1 << 29)) {
    puts("-1");
    return;
  }
  for (j = yl; j < yr + 1; j++) val[x][j] = 1;
  printf("%d %d %d\n", x + 1, yl + 1, yr + 1);
}
int main() {
  int T, t = 1, m, i, j, k;
  scanf("%d", &m);
  scanf("%d", &n);
  while (m--) {
    scanf("%d", &k);
    cal(k);
  }
  return 0;
}
