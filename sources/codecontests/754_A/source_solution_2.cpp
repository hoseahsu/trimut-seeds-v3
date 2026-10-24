#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
namespace Dup4 {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c - '0');
  return x * (f ? 1 : -1);
}
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c - '0');
  x *= f ? 1 : -1;
}
template <typename T>
inline void write(T x) {
  if (!x) {
    putchar(48);
    return;
  }
  if (x < 0) x = -x, putchar('-');
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
}
inline char nc() {
  static char buf[100000], *i = buf, *j = buf;
  return i == j && (j = (i = buf) + fread(buf, 1, 100000, stdin), i == j)
             ? EOF
             : *i++;
}
template <typename T>
inline void _read(T &sum) {
  char ch = nc();
  sum = 0;
  while (!(ch >= '0' && ch <= '9')) ch = nc();
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = nc();
}
template <typename T>
inline T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
const double PI = acos(-1.0);
const double EI = exp(1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
}  // namespace Dup4
using namespace Dup4;
namespace FastIO {
bool IOerror = false;
inline char NC() {
  static char buf[10000005], *p1 = buf + 10000005, *pend = buf + 10000005;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 10000005, stdin);
    if (pend == p1) {
      IOerror = true;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void __read(char &x) {
  char ch;
  while (blank(ch = NC()))
    ;
  if (IOerror) return;
  x = ch;
}
inline void __read(int &x) {
  char ch;
  while (blank(ch = NC()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; isdigit(ch = NC()); x = x * 10 + ch - '0')
    ;
}
}  // namespace FastIO
using namespace FastIO;
const int maxn = (int)1e2 + 100;
const int Maxn = (int)1e3 + 100;
const int MOD = (int)1e9 + 7;
int n;
int arr[maxn];
bool flag;
bool Input() {
  if (scanf("%d", &n) == EOF) return false;
  flag = false;
  for (int i = 1; i <= n; i++) {
    arr[i] = read();
    if (arr[i]) flag = true;
  }
  return true;
}
struct node {
  int l, r, sum;
  node() {}
  node(int l, int r, int sum) : l(l), r(r), sum(sum) {}
};
void Solve() {
  if (flag == false) {
    puts("NO");
    return;
  }
  vector<node> ans;
  int index = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0) {
      if (ans.empty()) {
        if (index == 0) index = i;
      } else
        (*ans.rbegin()).r++;
    } else {
      int l = i;
      if (index) l = index, index = 0;
      ans.push_back(node(l, i, arr[i]));
    }
  }
  puts("YES");
  cout << ans.size() << endl;
  for (auto it : ans) printf("%d %d\n", it.l, it.r);
}
int main() {
  while (Input()) Solve();
}
