#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 1e5 + 10;
const long double eps = 1e-10, pi = acos(-1);
int n;
struct point {
  long double x, y;
  inline bool operator==(const point &a) {
    return fabs(a.x - x) <= eps && fabs(a.y - y) <= eps;
  }
  inline point operator-(const point &a) { return (point){x - a.x, y - a.y}; }
  inline long double ang() {
    long double ret = atan2(y, x);
    if (ret < -eps) ret += 2 * pi;
    return ret;
  }
} O, p[N];
int cnt1, cnt2;
struct cmp {
  inline bool operator()(const long double x, const long double y) {
    return x + eps < y;
  }
};
multiset<long double, cmp> s;
inline void Add(point p) {
  if (p == O) return ++cnt1, void(0);
  p = p - O;
  long double a = p.ang(), b = a + pi;
  if (b >= 2 * pi) b -= 2 * pi;
  if (s.find(a) == s.end() && s.find(b) != s.end()) ++cnt2;
  s.insert(a);
}
inline void Del(point p) {
  if (p == O) return --cnt1, void(0);
  p = p - O;
  long double a = p.ang(), b = a + pi;
  if (b >= 2 * pi) b -= 2 * pi;
  s.erase(s.find(a));
  if (s.find(a) == s.end() && s.find(b) != s.end()) --cnt2;
}
inline bool check3() {
  if (((int)(s).size()) < 3) return 0;
  if (*s.rbegin() - *s.begin() <= pi) return 0;
  auto pre = s.lower_bound(pi), nxt = pre;
  if (nxt == s.end() || pre == s.begin()) return 0;
  --pre;
  return *nxt - *pre <= pi;
}
int main() {
  int a = read(), b = read(), c = read();
  O.x = 1.0 * a / (a + b + c), O.y = 1.0 * b / (a + b + c);
  int T = read();
  while (T--) {
    char opt[5];
    scanf("%s", opt);
    if (opt[0] == 'A') {
      int x = read(), y = read(), z = read();
      p[++n] = (point){1.0 * x / (x + y + z), 1.0 * y / (x + y + z)};
      Add(p[n]);
    } else {
      int x = read();
      Del(p[x]);
    }
    if (cnt1)
      puts("1");
    else if (cnt2)
      puts("2");
    else if (check3())
      puts("3");
    else
      puts("0");
  }
}
