#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c)
    if (b & i) res = 1LL * res * a % c;
  return res;
}
const int N = 300000;
const int inf = 1000000001;
int x[N];
int n, m;
int go(int p, int d, int dir) {
  int l, r;
  int s = 1, t = p;
  while (s <= t) {
    int m = (s + t) >> 1;
    if (x[p] - x[m] <= d)
      l = m, t = m - 1;
    else
      s = m + 1;
  }
  s = p, t = n;
  while (s <= t) {
    int m = (s + t) >> 1;
    if (x[m] - x[p] <= d)
      r = m, s = m + 1;
    else
      t = m - 1;
  }
  if (l == p && r == p) return p;
  if (!dir) {
    if (r == p)
      return go(p, d, 1);
    else {
      if (l == p) {
        if ((d / (x[r] - x[p])) % 2 == 0)
          return go(p, d % (x[r] - x[p]), 0);
        else
          return go(r, d % (x[r] - x[p]), 1);
      } else
        return go(r, d - (x[r] - x[p]), 1);
    }
  } else {
    if (l == p)
      return go(p, d, 0);
    else {
      if (r == p) {
        if ((d / (x[p] - x[l])) % 2 == 0)
          return go(p, d % (x[p] - x[l]), 1);
        else
          return go(l, d % (x[p] - x[l]), 0);
      } else
        return go(l, d - (x[p] - x[l]), 0);
    }
  }
}
map<int, int> S;
int y[N];
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) read(x + i), S[x[i]] = i, y[i] = x[i];
  sort(x + 1, x + n + 1);
  while (m--) {
    int p, d;
    read(&p);
    read(&d);
    p = lower_bound(x + 1, x + n + 1, y[p]) - x;
    printf("%d\n", S[x[go(p, d, 0)]]);
  }
  return 0;
}
