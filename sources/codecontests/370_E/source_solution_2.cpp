#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
int ok(int l, int r, int a, int b) {
  if (l > r) {
    if ((a + 1) == b) return 1;
    return 0;
  }
  int gap = r - l + 1;
  int lage = b - a - 1;
  if (5 * lage < gap) return 0;
  if ((2 * lage) > gap) return 0;
  return 1;
}
int a[400007];
int n;
int dp[400007][7];
int P[400007];
int N[400007];
int ar[400007];
int lol(int p, int pv) {
  if (p == (n + 1)) {
    int vl = a[P[p]];
    int lstend = P[p] + ar[P[p]] + pv;
    if (P[p] == 0) lstend++;
    int gap = p - lstend;
    if (gap == 1) return -2000000000;
    return vl + (gap / 2);
  }
  int &res = dp[p][pv];
  if (res != -1) return res;
  res = -2000000000;
  int lstend = P[p] + ar[P[p]] + pv;
  if (P[p] == 0) lstend++;
  for (int bac = 0; bac < 5; bac++) {
    for (int fr = 0; fr < 5; fr++) {
      if ((bac + fr + 1) > 5) continue;
      if ((bac + fr + 1) < 2) continue;
      if ((p - bac) < lstend) continue;
      if ((p + fr) >= N[p]) continue;
      if ((p + fr) < (p + ar[p] - 1)) continue;
      int tp = ok(lstend, p - bac - 1, a[P[p]], a[p]);
      if (tp) {
        res = max(res, lol(N[p], (p + fr - (p + ar[p] - 1))));
      }
    }
  }
  return res;
}
void Fill(int l, int r, int st, int ed) {
  if (l > r) return;
  int gap = r - l + 1;
  int vl = ed - st + 1;
  int mid = gap / vl;
  int rm = gap % vl;
  for (int i = l; i <= r; i += mid) {
    for (int j = i; j < i + mid; j++) {
      a[j] = st;
    }
    if (rm) {
      rm--;
      a[i + mid] = st;
      i++;
    }
    st++;
  }
}
void path(int p, int pv) {
  if (p == (n + 1)) {
    int vl = a[P[p]];
    int lstend = P[p] + ar[P[p]] + pv;
    if (P[p] == 0) lstend++;
    int gap = p - lstend;
    Fill(lstend, p - 1, vl + 1, vl + (gap / 2));
    return;
  }
  int res = lol(p, pv);
  int lstend = P[p] + ar[P[p]] + pv;
  if (P[p] == 0) lstend++;
  int f = 0;
  for (int bac = 0; bac < 5; bac++) {
    for (int fr = 0; fr < 5; fr++) {
      if ((bac + fr + 1) > 5) continue;
      if ((bac + fr + 1) < 2) continue;
      if ((p - bac) < lstend) continue;
      if ((p + fr) >= N[p]) continue;
      if ((p + fr) < (p + ar[p] - 1)) continue;
      int tp = ok(lstend, p - bac - 1, a[P[p]], a[p]);
      if (tp) {
        int kk = lol(N[p], (p + fr - (p + ar[p] - 1)));
        if (kk == res) {
          f = 1;
          for (int i = p; i >= p - bac; i--) a[i] = a[p];
          for (int i = p; i <= p + fr; i++) a[i] = a[p];
          Fill(lstend, p - bac - 1, a[P[p]] + 1, a[p] - 1);
          path(N[p], (p + fr - (p + ar[p] - 1)));
          break;
        }
      }
    }
    if (f) break;
  }
  return;
}
int Nxt(int p) {
  int tot = 0;
  while (a[p] == a[p + tot]) {
    tot++;
  }
  return tot;
}
int Next(int p) {
  int tot = 0;
  while ((p + tot) <= n && (a[p] == a[p + tot] || !a[p + tot])) {
    tot++;
  }
  return p + tot;
}
int main() {
  n = in<int>();
  for (int i = 1; i < n + 1; i++) {
    a[i] = in<int>();
  }
  int pv = -1;
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      if (a[i] == pv) {
        for (int j = lst + 1; j < i + 1; j++) a[j] = a[i];
      }
      lst = i;
      pv = a[i];
    }
  }
  int f = 0;
  int fs = -1;
  for (int i = 1; i <= n;) {
    if (a[i]) {
      int tp = Nxt(i);
      if (tp > 5) {
        printf("-1\n");
        exit(0);
      }
      int tp1 = tp;
      ar[i] = tp;
      tp = Next(i);
      N[i] = tp;
      P[tp] = i;
      f = 1;
      if (fs == -1) {
        fs = i;
      }
      i += tp1;
    } else
      i++;
  }
  if (fs == -1) fs = n + 1;
  memset(dp, -1, sizeof(dp));
  int ans = lol(fs, 0);
  if (ans <= -2000000000) ans = -1;
  cout << ans << endl;
  if (ans == -1) exit(0);
  path(fs, 0);
  for (int i = 1; i < n + 1; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
