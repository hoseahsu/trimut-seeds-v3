#include <bits/stdc++.h>
using namespace std;
inline int Getlen(int x) {
  int res = 0;
  while (x) {
    res++;
    x /= 10;
  }
  return res;
}
int PP[5];
int a[51], len[51], n, p;
int id[51];
int res[51], tot;
inline void dfs(int now, int Gmod, int Gxor) {
  if (Gmod == 0 && Gxor == 0 && tot > 0) {
    puts("Yes");
    cout << tot << endl;
    for (int i = 0; i < tot; i++) cout << res[i] << ' ';
    exit(0);
  }
  if (now > n) return;
  dfs(now + 1, Gmod, Gxor);
  res[tot++] = id[now];
  dfs(now + 1, (Gmod * PP[len[now]] + a[now]) % p, Gxor ^ a[now]);
  tot--;
}
int main() {
  rand();
  rand();
  rand();
  rand();
  rand();
  rand();
  int tmpp;
  tmpp = 0;
  tmpp++;
  tmpp++;
  srand(time(NULL));
  tot = 0;
  PP[0] = 1;
  for (int i = 1; i <= 3; i++) PP[i] = PP[i - 1] * 10;
  scanf("%d%d", &n, &p);
  int now = 0, tmp;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    if (tmp <= 31) a[++now] = tmp, len[now] = Getlen(a[now]), id[now] = i;
  }
  n = now;
  dfs(1, 0, 0);
  puts("No");
}
