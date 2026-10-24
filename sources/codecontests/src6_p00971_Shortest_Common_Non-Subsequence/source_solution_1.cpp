#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[4444], t[4444];
int sl, tl;
int nxs[4444][2], nxt[4444][2];
int dp[4444][4444];
int nx[4444][4444];

int solve(int a, int b, int c=0) {
  a = min(a, sl);
  b = min(b, tl);
  // printf("%d %d %d\n", a, b, c);
  if (a >= sl - 1 && b >= tl - 1) return 0;
  if (dp[a][b] >= 0) return dp[a][b];
  int p = solve(nxs[a][0], nxt[b][0], 0) + 1;
  int q = solve(nxs[a][1], nxt[b][1], 1) + 1;
  if (p == q || p < q) nx[a][b] = 0;
  else nx[a][b] = 1;
  int res = min(p, q);
  return dp[a][b] = res;
}

void gen(char *s, int l, int nx[4444][2]) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < 2; j++) {
      int k = i;
      if (s[k] == j + '0') nx[i][j] = k + 1;
      else {
        k += 1;
        while (s[k] && s[k] != j + '0') {
          ++k;
        }
        nx[i][j] = min(l, k + 1);
      }
    }
  }
  nx[l][0] = nx[l][1] = l;
}

int main(void) {
  scanf("%s%s", s, t);
  strcat(s, "10");
  strcat(t, "10");
  sl = strlen(s);
  tl = strlen(t);
  memset(dp, -1, sizeof(dp));
  memset(nx, -1, sizeof(nx));
  gen(s, sl, nxs);
  gen(t, tl, nxt);
  // printf("%d %d\n", nxs[0][0], nxt[0][0]);
  // printf("%d %d\n", nxs[0][1], nxt[0][1]);
  int res = solve(0, 0);
  int a = 0, b = 0;
  while(nx[a][b] >= 0) {
    int t = nx[a][b];
    printf("%d", t);
    a = nxs[a][t];
    b = nxt[b][t];
  }
  puts("");
  // printf("%d\n", res);
  return 0;
}

