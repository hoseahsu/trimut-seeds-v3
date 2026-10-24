#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 10;
struct bkn {
  int to, next;
} e[maxn * 2];
int n, m;
int c[maxn], head[maxn], tot, vis[maxn][2], in[maxn];
int ans[maxn], cnt, h, win;
void add(int a, int b) {
  e[++tot].to = b;
  e[tot].next = head[a], head[a] = tot;
}
void dfs(int x, int now) {
  if (!c[x] && now == 1) {
    win = 1;
    ans[++cnt] = x;
    return;
  }
  in[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (in[y]) h = 1;
    if (vis[y][now ^ 1]) continue;
    vis[y][now ^ 1] = 1;
    dfs(y, now ^ 1);
    if (win) {
      ans[++cnt] = x;
      return;
    }
  }
  in[x] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int ok = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    if (!c[i]) ok = 1;
    for (int j = 1; j <= c[i]; j++) {
      int x;
      scanf("%d", &x);
      add(i, x);
    }
  }
  int s;
  scanf("%d", &s);
  if (!ok) {
    printf("Draw\n");
    return 0;
  }
  dfs(s, 0);
  if (win) {
    printf("Win\n");
    for (int i = cnt; i >= 1; i--) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else if (h) {
    printf("Draw\n");
  } else
    printf("Lose\n");
}
