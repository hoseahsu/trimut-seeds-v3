#include <bits/stdc++.h>
const int H = 600000;
char s0[H], *s1 = s0, *s2 = s1;
inline int read() {
  register int x = 0, c, f = 0;
  while (isspace(
      c = (s1 == s2 && (s2 = (s1 = s0) + fread(s0, 1, H, stdin), s1 == s2)
               ? 32
               : *s1++)))
    ;
  if (c == '-')
    f = 1;
  else
    x = x * 10 + c - 48;
  while (isdigit(
      c = (s1 == s2 && (s2 = (s1 = s0) + fread(s0, 1, H, stdin), s1 == s2)
               ? 32
               : *s1++)))
    x = x * 10 + c - 48;
  return (f ? -x : x);
}
using namespace std;
int n;
struct node {
  int x, y, t, i;
} L[20010];
node O;
int ansi[20010];
int ci[20010];
int compc(int a, int b) {
  return ((L[a].x - O.x) * (L[b].y - O.y) - (L[b].x - O.x) * (L[a].y - O.y)) <
         0;
}
int comp(node a, node b) {
  return ((a.x - O.x) * (b.y - O.y) - (b.x - O.x) * (a.y - O.y)) < 0;
}
void solve(int l, int r) {
  if (l > r) return;
  for (int i = l + 1; i <= r; ++i)
    if (L[ci[i]].y < L[ci[l]].y) swap(ci[i], ci[l]);
  O = L[ci[l]];
  sort(ci + l + 1, ci + r + 1, compc);
  int np = l + 1;
  for (int i = l + 1, k = 0; i < r; ++i) {
    k += L[ci[i]].t;
    if (k == 0) {
      solve(np, i);
      np = i + 1;
    }
  }
  if (L[ci[l]].t > 0)
    ansi[L[ci[l]].i] = L[ci[np]].i;
  else
    ansi[L[ci[np]].i] = L[ci[l]].i;
  solve(np + 1, r);
}
int compi(node a, node b) {
  if (a.t != b.t)
    return a.t > b.t;
  else
    return a.i < b.i;
}
int checker() {
  sort(L + 1, L + n * 2 + 1, compi);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) {
        O = L[i];
        int a =
            comp(L[ansi[i] + n], L[j]) ^ comp(L[ansi[i] + n], L[ansi[j] + n]);
        O = L[j];
        int b =
            comp(L[ansi[j] + n], L[i]) ^ comp(L[ansi[j] + n], L[ansi[i] + n]);
        if (a && b) return 1;
      }
  return 0;
}
int main() {
  n = read();
  for (int i = 1; i <= 2 * n; ++i) ci[i] = i;
  for (int i = 1; i <= n; ++i) {
    L[i].x = read();
    L[i].y = read();
    L[i].t = 1;
    L[i].i = i;
  }
  for (int i = 1; i <= n; ++i) {
    L[i + n].x = read();
    L[i + n].y = read();
    L[i + n].t = -1;
    L[i + n].i = i;
  }
  solve(1, n * 2);
  for (int i = 1; i <= n; ++i) printf("%d\n", ansi[i]);
}
