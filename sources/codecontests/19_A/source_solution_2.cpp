#include <bits/stdc++.h>
using namespace std;
const int low(int x) { return x & -x; }
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int maxn = 5e2 + 10;
int T, n, x, y;
int a[maxn], b[maxn], c[maxn], ans[maxn];
char name[maxn][maxn], s1[maxn], s2[maxn], s[maxn];
bool cmp1(const int &x, const int &y) {
  return a[x] == a[y] ? (b[x] - c[x]) == (b[y] - c[y])
                            ? b[x] > b[y]
                            : (b[x] - c[x]) > (b[y] - c[y])
                      : a[x] > a[y];
}
bool cmp2(const int &x, const int &y) { return strcmp(name[x], name[y]) < 0; }
int main() {
  while (scanf("%d", &n) != EOF) {
    map<string, int> M;
    for (int i = 1; i <= n; i++) {
      scanf("%s", name[i]);
      M[name[i]] = ans[i] = i;
      a[i] = b[i] = c[i] = 0;
    }
    for (int i = 1, j, k; i + i <= n * (n - 1); i++) {
      scanf("%s%d:%d", s, &x, &y);
      for (j = 0; s[j] != '-'; j++) s1[j] = s[j];
      s1[j++] = 0;
      for (k = j; s[k]; k++) s2[k - j] = s[k];
      s2[k - j] = 0;
      int fx = M[s1], fy = M[s2];
      b[fx] += x;
      c[fx] += y;
      b[fy] += y;
      c[fy] += x;
      if (x == y)
        a[fx]++, a[fy]++;
      else
        a[x > y ? fx : fy] += 3;
    }
    sort(ans + 1, ans + n + 1, cmp1);
    sort(ans + 1, ans + n / 2 + 1, cmp2);
    for (int i = 1; i + i <= n; i++) printf("%s\n", name[ans[i]]);
  }
  return 0;
}
