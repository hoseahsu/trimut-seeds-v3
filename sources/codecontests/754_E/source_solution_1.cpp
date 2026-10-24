#include <bits/stdc++.h>
using namespace std;
const int Maxn = 800 + 10;
int n, m, r, c, N, M;
char P[Maxn][Maxn], T[Maxn][Maxn];
bitset<Maxn> R[Maxn], G[26][Maxn];
bitset<Maxn> calc(const bitset<Maxn>& b, int len, int l) {
  return (b >> l) | (b << (len - l));
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", P[i]);
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; i++) scanf("%s", T[i]);
  for (int i = 0; i < n + r; i++)
    for (int j = 0; j < m + c; j++) P[i][j] = P[i % n][j % m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) R[i].set(j);
  for (int ch = 0; ch < 26; ch++)
    for (int i = 0; i < n + r; i++)
      for (int j = 0; j < m + c; j++)
        if (P[i][j] == ch + 'a') G[ch][i].set(j);
  for (int x = 0; x < r; x++)
    for (int y = 0; y < c; y++) {
      if (T[x][y] == '?') continue;
      for (int k = 0; k < n; k++)
        R[k] = R[k] & calc(G[T[x][y] - 'a'][(k + x) % n], m, y);
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) putchar(R[i][j] + '0');
    putchar('\n');
  }
}
int main() {
  solve();
  return 0;
}
