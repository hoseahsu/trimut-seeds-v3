#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int n, i, j, a[100][100], r[100], c[100], ans;
int main() {
  scanf("%d", &n);
  for (i = 0; i < (n); ++i)
    for (j = 0; j < (n); ++j) scanf("%d", a[i] + j);
  for (i = 0; i < (n); ++i)
    for (j = 0; j < (n); ++j) r[i] += a[i][j];
  for (j = 0; j < (n); ++j)
    for (i = 0; i < (n); ++i) c[j] += a[i][j];
  for (i = 0; i < (n); ++i)
    for (j = 0; j < (n); ++j)
      if (r[i] < c[j]) ans++;
  printf("%d\n", ans);
}
