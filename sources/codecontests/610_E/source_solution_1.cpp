#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[200005], cnt[15][15], rk[15];
char ch[200005];
set<int> S;
set<int>::iterator split(int x) {
  set<int>::iterator it = S.lower_bound(x);
  if (*it == x) return it;
  int p = *--it;
  return a[x] = a[p], S.insert(x).first;
}
int main() {
  scanf("%d%d%d%s", &n, &m, &k, ch + 1);
  a[0] = a[n + 1] = 10;
  for (int i = 1; i <= n; i++)
    if ((a[i] = ch[i] - 'a') != a[i - 1]) S.insert(i);
  for (int i = 1; i < n; i++) cnt[a[i]][a[i + 1]]++;
  S.insert(0), S.insert(n + 1);
  for (int op, x, y; m--;) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%s", &x, &y, ch);
      int c = ch[0] - 'a';
      set<int>::iterator R = split(y + 1), L = split(x), pre, nxt;
      pre = L, cnt[a[*--pre]][a[*L]]--;
      for (; L != R; L = nxt)
        nxt = L, cnt[a[*L]][a[*L]] -= *++nxt - *L - 1, cnt[a[*L]][a[*nxt]]--,
        S.erase(L);
      cnt[a[*pre]][c]++, cnt[c][c] += y - x, cnt[c][a[*R]]++;
      S.insert(x), a[x] = c;
    } else {
      scanf("%s", ch);
      for (int i = 0; i < k; i++) rk[ch[i] - 'a'] = i;
      int ans = 0;
      for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
          if (rk[i] >= rk[j]) ans += cnt[i][j];
      printf("%d\n", ans + 1);
    }
  }
}
