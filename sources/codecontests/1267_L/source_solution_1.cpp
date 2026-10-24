#include <bits/stdc++.h>
using namespace std;
const int INF = 1061109567;
const long long LINF = 4557430888798830399ll;
const int MOD = 1000000007;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  if (c == EOF) exit(0);
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  assert(c != EOF);
}
int reads(char *s) {
  int l = 0;
  *s = getchar();
  if (*s == EOF) exit(0);
  while (*s != ' ' && *s != '\t' && *s != '\r' && *s != '\n' && *s != EOF) {
    ++s;
    ++l;
    *s = getchar();
  }
  assert(*s != EOF);
  *s = '\0';
  return l;
}
long long qpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
int n, l, k;
char s[1000005];
char t[1005][1005];
void test_case() {
  sort(s + 1, s + 1 + n * l);
  int cur = 0, b = 1;
  for (int j = 1; j <= l; ++j) {
    for (int i = b; i <= k; ++i) {
      t[i][j] = s[++cur];
      if (i > 1 && t[i][j] > t[i - 1][j]) b = i;
    }
    if (k == 1 || t[k][j] != t[k - 1][j]) {
      for (int tj = j + 1; tj <= l; ++tj) t[k][tj] = s[++cur];
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= l; ++j) {
      if (t[i][j] == '\0') t[i][j] = s[++cur];
      putchar(t[i][j]);
    }
    putchar('\n');
  }
}
int main() {
  while (1) {
    read(n), read(l), read(k);
    reads(s + 1);
    memset(t, '\0', sizeof(t));
    test_case();
  }
}
