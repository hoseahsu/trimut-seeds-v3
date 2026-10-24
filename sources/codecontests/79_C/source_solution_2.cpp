#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const double eps = 1e-8;
const int iinf = INT_MAX;
const long long linf = 2e18;
const double dinf = 1e30;
const int MOD = 1000000007;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void print(int x) {
  cout << x << '\n';
  exit(0);
}
void PRINT(string x) {
  cout << x << '\n';
  exit(0);
}
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
int n, m, len[11];
char s[11][11], c[N];
bool check(int l, int r, int i) {
  if (r - l + 1 < len[i]) return 0;
  for (int j = len[i] - 1, k = r; j >= 0; j--, k--)
    if (c[k] != s[i][j]) return 0;
  return 1;
}
int main() {
  scanf("%s%d", c, &n);
  m = strlen(c);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }
  int ansl = 0, ansp = 0, l = 0, r = 0;
  while (l < m) {
    int flag = 0;
    for (int i = 1; i <= n; i++)
      if (check(l, r, i)) {
        flag = 1;
        l++;
        r = max(r, l);
        break;
      }
    if (!flag && r - l + 1 > ansl) ansl = r - l + 1, ansp = l;
    if (!flag) {
      if (r < m - 1)
        r++;
      else
        break;
    }
  }
  printf("%d %d\n", ansl, ansp);
  return 0;
}
