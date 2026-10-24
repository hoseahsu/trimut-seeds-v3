#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
T cube(T a) {
  return a * a * a;
}
template <typename T>
inline void smin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void smax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
  err(++it, args...);
}
inline int in() {
  int n;
  scanf("%d", &n);
  return n;
}
inline long long Lin() {
  long long n;
  scanf("%lld", &n);
  return n;
}
inline double Din() {
  double n;
  scanf("%lf", &n);
  return n;
}
inline int add(int a, int b, int mod) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod) { return (long long)a * b % mod; }
const int N = 2e5 + 5;
const int inf = (int)2e9 + 5;
const long long Inf = (long long)1e18 + 5;
const int mod = (int)1e9 + 7;
const long long Mod = (long long)1e9 + 7;
vector<int> b[N];
int solve() {
  int n = in(), k = in();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = in();
  }
  for (int i = 0; i < n; i++) {
    int x = a[i], cur = 0;
    while (x >= 1) {
      b[x].push_back(cur);
      x /= 2;
      cur++;
    }
  }
  long long ans = Inf;
  for (int i = 0; i <= 2e5; i++) {
    sort(b[i].begin(), b[i].end());
    if ((int)b[i].size() >= k) {
      long long cur = 0;
      for (int j = 0; j < k; j++) {
        cur += b[i][j];
      }
      smin(ans, cur);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
int main() {
  int test = 1, tc = 0;
  while (test--) {
    solve();
  }
  return 0;
}
