#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 1000010;
int fa[MAXN], dp[MAXN], Mx1[MAXN], Mx2[MAXN];
int N;
int main() {
  N = read() + 1;
  for (int i = 2; i <= N; i++) fa[i] = read();
  for (int i = 2; i <= N; i++) {
    for (int x = i; x; x = fa[x]) {
      int y = max(Mx1[x], Mx2[x] + 1);
      if (y <= dp[x]) break;
      dp[x] = y;
      if (y > Mx1[fa[x]])
        Mx1[fa[x]] = y;
      else if (y > Mx2[fa[x]])
        Mx2[fa[x]] = y;
    }
    printf("%d ", max(Mx1[1], Mx2[1]));
    if (i == N) printf("\n");
  }
  return 0;
}
