#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-9;
template <class T>
bool INRANGE(T x, T a, T b) {
  return a <= x && x <= b;
}
template <class T>
void amin(T &a, T v) {
  if (a > v) a = v;
}
template <class T>
void amax(T &a, T v) {
  if (a < v) a = v;
}
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) {
  return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y)));
}
double SQSUM(double x, double y) { return x * x + y * y; }
int main() {
  int b, k;
  scanf("%d %d ", &b, &k);
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d ", &a[i]);
  }
  int even = 0;
  int odd = 0;
  for (int i = 0; i < k; ++i) {
    if (i == k - 1) {
      if (a[i] % 2 == 1) {
        odd++;
      } else {
        even++;
      }
    } else {
      if (a[i] % 2 == 1 && b % 2 == 1) {
        odd++;
      } else {
        even++;
      }
    }
  }
  if (odd % 2 == 1) {
    printf("odd\n");
  } else {
    printf("even\n");
  }
  return 0;
}
