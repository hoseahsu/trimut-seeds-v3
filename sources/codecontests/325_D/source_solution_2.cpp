#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 998244353;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
int r, c, n;
int fa[18000005];
inline int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
inline int tr(int R, int C) { return (R - 1) * c * 2 + C; }
bool del[3005][6005];
int Xx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Yy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline void ck(int& C) {
  if (C == c * 2 + 1) C = 1;
  if (C == 0) C = c * 2;
}
inline bool check(int R, int C) {
  for (int i = 0; i < 8; i++) {
    int Xr = R + Xx[i], Xc = C + Yy[i];
    if (Xr <= 0 || Xr > r) continue;
    ck(Xc);
    if (del[Xr][Xc] == 0) continue;
    for (int j = 0; j < 8; j++) {
      int Yr = R + Xx[j], Yc = C + c + Yy[j];
      if (Yr <= 0 || Yr > r) continue;
      ck(Yc);
      if (del[Yr][Yc] == 0) continue;
      int fat = find(tr(Xr, Xc)), fbt = find(tr(Yr, Yc));
      if (fat == fbt) return 0;
    }
  }
  return 1;
}
inline void merge(int R, int C) {
  for (int i = 0; i < 8; i++) {
    int Xr = R + Xx[i], Xc = C + Yy[i];
    if (Xr <= 0 || Xr > r) continue;
    ck(Xc);
    if (del[Xr][Xc] == 0) continue;
    int fat = find(tr(Xr, Xc)), fbt = find(tr(R, C));
    if (fat == fbt) continue;
    fa[fat] = fbt;
  }
}
int main() {
  read(r, c, n);
  if (c == 1) return printf("0\n"), 0;
  for (int i = 1; i <= r * c * 2; i++) fa[i] = i;
  int ans = 0;
  while (n--) {
    int R, C;
    read(R, C);
    if (check(R, C) == 0) continue;
    del[R][C] = del[R][C + c] = 1;
    merge(R, C);
    merge(R, C + c);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
