#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = int(1e9) + 7;
inline int add(const int a, const int b, const int mod = MOD) {
  return (a + b >= mod) ? (a + b - mod) : (a + b);
}
inline int sub(const int a, const int b, const int mod = MOD) {
  return (a - b < 0) ? (a - b + mod) : (a - b);
}
inline void inc(int &a, const int b, const int mod = MOD) {
  a = add(a, b, mod);
}
inline int negate(const int a, const int mod = MOD) { return mod - a; }
inline int mul(const int a, const int b, const int mod = MOD) {
  return (a * 1ll * b) % mod;
}
int binPow(int b, int p, const int mod = MOD) {
  int r = 1;
  while (p) {
    if (p & 1) r = mul(r, b, mod);
    b = mul(b, b, mod);
    p >>= 1;
  }
  return r;
}
int inv(const int a, const int mod = MOD) {
  int res = binPow(a, mod - 2, mod);
  return res;
}
inline int dvd(const int a, const int b, const int mod = MOD) {
  return mul(a, inv(b, mod), mod);
}
inline int convert(int x, const int mod = MOD) {
  int tx = x % mod + mod;
  return tx > mod ? tx - mod : tx;
};
struct mNum {
  int x;
  mNum(int _x) : x(convert(_x)) {}
  mNum(long long _x) : x(convert(_x)) {}
};
mNum operator+(mNum a, mNum b) { return mNum(add(a.x, b.x)); }
mNum operator-(mNum a, mNum b) { return mNum(sub(a.x, b.x)); }
mNum operator*(mNum a, mNum b) { return mNum(mul(a.x, b.x)); }
mNum operator/(mNum a, mNum b) { return mNum(dvd(a.x, b.x)); }
mNum operator+(long long x, mNum b) { return mNum(add(convert(x), b.x)); }
mNum operator-(long long x, mNum b) { return mNum(sub(convert(x), b.x)); }
mNum operator*(long long x, mNum b) { return mNum(mul(convert(x), b.x)); }
mNum operator/(long long x, mNum b) { return mNum(dvd(convert(x), b.x)); }
mNum operator+(mNum a, long long x) { return mNum(add(a.x, convert(x))); }
mNum operator-(mNum a, long long x) { return mNum(sub(a.x, convert(x))); }
mNum operator*(mNum a, long long x) { return mNum(mul(a.x, convert(x))); }
mNum operator/(mNum a, long long x) { return mNum(dvd(a.x, convert(x))); }
const int MAX = 80;
char s[MAX];
int n;
map<int, int> dp[MAX][MAX];
int num[MAX][MAX] = {0};
set<int> validSets;
const int MAXNUM = 20;
int sz[MAXNUM + 1] = {0};
int needLen[1 << MAXNUM];
void clear() {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++) dp[i][j].clear();
  validSets.clear();
  int tSet = 1;
  for (int i = 1; i <= 20; i++) {
    validSets.insert(tSet);
    tSet = tSet * 2 + 1;
  }
}
int getNum(int l, int r) {
  int len = r - l + 1;
  int res = 0;
  for (int i = l; i < r; i++) {
    res = res * 2 + s[i] - '0';
    if (res > 20) return -1;
  }
  return res;
}
int enable(const int s, int b) { return s | (1 << b - 1); }
int getSz(int x) {
  int res = 0;
  while (x) res++, x >>= 1;
  return res;
}
unsigned int numbits(unsigned int i) {
  const unsigned int MASK1 = 0x55555555;
  const unsigned int MASK2 = 0x33333333;
  const unsigned int MASK4 = 0x0f0f0f0f;
  const unsigned int MASK8 = 0x00ff00ff;
  const unsigned int MASK16 = 0x0000ffff;
  i = (i & MASK1) + (i >> 1 & MASK1);
  i = (i & MASK2) + (i >> 2 & MASK2);
  i = (i & MASK4) + (i >> 4 & MASK4);
  i = (i & MASK8) + (i >> 8 & MASK8);
  i = (i & MASK16) + (i >> 16 & MASK16);
  return i;
}
void solve() {
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n + 1; j++) num[i][j] = getNum(i, j);
  for (int num = 1; num <= MAXNUM; num++) sz[num] = getSz(num);
  for (int s = 1; s < 1 << MAXNUM; s++) {
    needLen[s] = 0;
    int maxNum = 1;
    for (int num = 1; num <= MAXNUM; num++)
      if (s >> (num - 1) & 1) maxNum = num;
    for (int num = 1; num <= maxNum; num++)
      if ((s >> (num - 1) & 1) == 0) needLen[s] += sz[num];
  }
  for (int len = 0; len < n; len++) dp[len][1][0] = 1;
  for (int cuts = 1; cuts <= n; cuts++)
    for (int len = 0; len < n; len++)
      for (auto &p : dp[len][cuts]) {
        int numSet = p.first, count = p.second;
        for (int r = len + 1; r <= n; r++) {
          int tNum = num[len][r];
          if (tNum <= 0) continue;
          int tCuts = cuts + 1, tLen = r, tNumSet = enable(numSet, tNum);
          if (needLen[tNumSet] > n - r) continue;
          dp[tLen][tCuts][tNumSet] = add(dp[tLen][tCuts][tNumSet], count);
        }
      }
  int res = 0;
  for (int nCuts = 2; nCuts <= n + 1; nCuts++) {
    int cutRes = 0;
    for (int len = 1; len <= n; len++) {
      int tres = 0;
      for (auto &p : dp[len][nCuts])
        if (numbits(p.first + 1) == 1) tres = add(tres, p.second);
      cutRes = add(cutRes, tres);
      cutRes = cutRes;
    }
    res = add(res, cutRes);
  }
  printf("%d\n", res);
}
int main() {
  while (scanf("%d", &n) == 1) {
    clear();
    solve();
    return 0;
  }
  return 0;
}
