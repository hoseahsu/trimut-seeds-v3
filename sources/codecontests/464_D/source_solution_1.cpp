#include <bits/stdc++.h>
using namespace std;
void enable_comma() {}
string tostring(char c) {
  string s = "";
  s += c;
  return s;
}
string tostring(string s) { return "\"" + s + "\""; }
string tostring(const char *c) { return tostring((string)c); }
string tostring(long long x) {
  if (x < 0) return "-" + tostring(-x);
  if (x > 9)
    return tostring(x / 10) + tostring(char('0' + x % 10));
  else
    return tostring(char('0' + x));
}
string tostring(int x) { return tostring((long long)x); }
string tostring(unsigned long long x) {
  if (x > 9)
    return tostring((long long)(x / 10)) + tostring(char('0' + x % 10));
  else
    return tostring(char('0' + x));
}
string tostring(unsigned x) { return tostring((long long)x); }
string tostring(double x) {
  static char res[114];
  sprintf(res, "%lf", x);
  string s = tostring(res);
  return s.substr(1, (int)s.size() - 2);
}
string tostring(long double x) { return tostring((double)x); }
template <class A, class B>
string tostring(pair<A, B> p) {
  return "(" + tostring(p.first) + "," + tostring(p.second) + ")";
}
template <class T>
string tostring(T v) {
  string res = "";
  for (auto p : v) res += (res.size() ? "," : "{") + tostring(p);
  return res.size() ? res + "}" : "{}";
}
template <class A>
string tostring(A *a, int L, int R) {
  return tostring(vector<A>(a + L, a + R + 1));
};
template <class A>
string tostring(A a, int L, int R) {
  return tostring(a.data(), L, R);
}
string tostrings() { return ""; }
template <typename Head, typename... Tail>
string tostrings(Head H, Tail... T) {
  return tostring(H) + " " + tostrings(T...);
}
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <class T>
void ckmax(T &x, const T y) {
  if (x < y) x = y;
}
template <class T>
void ckmin(T &x, const T y) {
  if (x > y) x = y;
}
const int N = 100005, M = 1005;
int n, m = M - 5, k;
long double p[M], pp[M];
void solve() {
  n = read(), k = read();
  p[1] = 1;
  long double ans = 0;
  for (int i = (1); i <= (n); i++) {
    memset(pp, 0, sizeof(pp));
    for (int j = (1); j <= (m); j++) {
      ans += p[j] * ((1 + j + 1) * (j + 1) / 2 - 1) / (j + 1) / k;
      pp[j] += p[j] * j / (j + 1);
      pp[j + 1] += p[j] / (j + 1);
    }
    for (int j = (1); j <= (m); j++) {
      p[j] = (p[j] * (k - 1) + pp[j]) / k;
    }
  }
  ans *= k;
  printf("%.10lf\n", (double)ans);
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
