#include <bits/stdc++.h>
using namespace std;
namespace mine {
long long qread() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num >= 10) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  putchar('\n');
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
bool IN(long long x, long long l, long long r) { return l <= x and x <= r; }
void GG() {
  puts("-1");
  exit(0);
}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int mm(const int x) { return x >= MOD ? x - MOD : x; }
template <typename T>
void add(T &x, const int &y) {
  x = (x + y >= MOD ? x + y - MOD : x + y);
}
long long qpower(long long x, long long e, int mod = MOD) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * x % mod;
    x = x * x % mod;
    e >>= 1;
  }
  return ans;
}
long long invm(long long x) { return qpower(x, MOD - 2); }
const int MM = 1e6 + 10;
long long fac[MM], facinv[MM], Inv[MM];
long long Comb(int n, int m) {
  return n < 0 or n < m ? 0 : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
void PRE() {
  fac[0] = 1;
  for (int i = (1), I = (MM - 1); i <= I; i++) fac[i] = fac[i - 1] * i % MOD;
  facinv[MM - 1] = invm(fac[MM - 1]);
  for (int i = (MM - 1), I = (1); i >= I; i--)
    facinv[i - 1] = facinv[i] * i % MOD;
  Inv[1] = 1;
  for (int i = (2), I = (MM - 1); i <= I; i++)
    Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
}
const int N = 1e6 + 10;
char str[N];
int n, q;
int To(char c) { return c == 'R' ? 0 : (c == 'P' ? 1 : 2); }
set<int> hh[3];
struct BIT {
  int bit[N];
  void clear() { memset(bit, 0, sizeof bit); }
  int lowbit(int x) { return x & -x; }
  void ch(int x, int c) {
    while (x < N) bit[x] += c, x += lowbit(x);
  }
  int ask(int x) {
    int ret = 0;
    while (x >= 1) ret += bit[x], x -= lowbit(x);
    return ret;
  }
  int ask(int l, int r) { return ask(r) - ask(l - 1); }
} bit[3];
int solve() {
  int ret = 0;
  for (int now = (0), I = (2); now <= I; now++) {
    if (!((int)(hh[(now + 1) % 3]).size())) {
      ret += ((int)(hh[now]).size());
      continue;
    }
    if (!((int)(hh[(now + 2) % 3]).size())) continue;
    int al = *hh[(now + 1) % 3].begin(), ar = *(--hh[(now + 1) % 3].end());
    int bl = *hh[(now + 2) % 3].begin(), br = *(--hh[(now + 2) % 3].end());
    if (al < bl and br < ar)
      ret += bit[now].ask(bl, br) + bit[now].ask(1, al) + bit[now].ask(ar, n);
    else if (al < bl)
      ret += bit[now].ask(1, al) + bit[now].ask(bl, n);
    else if (br < ar)
      ret += bit[now].ask(1, br) + bit[now].ask(ar, n);
    else
      ret += ((int)(hh[now]).size());
    printf("");
  }
  return ret;
}
void main() {
  n = qread(), q = qread();
  scanf("%s", str + 1);
  for (int i = (1), I = (n); i <= I; i++)
    hh[To(str[i])].insert(i), bit[To(str[i])].ch(i, 1);
  write2(solve());
  while (q--) {
    int i = qread();
    char c[10];
    scanf("%s", c);
    hh[To(str[i])].erase(i), bit[To(str[i])].ch(i, -1);
    str[i] = c[0];
    hh[To(str[i])].insert(i), bit[To(str[i])].ch(i, 1);
    write2(solve());
  }
}
};  // namespace mine
signed main() {
  srand(time(0));
  mine::PRE();
  mine::main();
  printf("");
}
