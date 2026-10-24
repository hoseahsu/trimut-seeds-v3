#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 101000;
struct node {
  node *l, *r;
  char v;
  int pos;
} nd[N];
int n, Q, l, r;
char s[N];
int vr[N * 20], tot, cp;
int c[N], lt[N], fb[N], dig[N * 20][10];
void modify(int x, int w) {
  for (; x <= n + 2; x += x & -x) c[x] = min(c[x], w);
}
int query(int x) {
  int w = tot + 1;
  for (; x; x -= x & -x) w = min(w, c[x]);
  return w;
}
int main() {
  scanf("%d%d", &n, &Q);
  scanf("%s", s + 1);
  s[0] = 'S';
  s[n + 1] = 'E';
  for (int i = 0; i < n + 2; i++) nd[i].pos = i, nd[i].v = s[i];
  for (int i = 0; i < n + 1; i++) nd[i].r = nd + i + 1;
  for (int i = 1; i < n + 2; i++) nd[i].l = nd + i - 1;
  node *p = nd;
  int dir = 1;
  while (1) {
    vr[++tot] = p->pos;
    if (!fb[p->pos]) fb[p->pos] = tot;
    cp = max(cp, p->pos);
    if (p->v == 'E')
      break;
    else if (p->v == 'S')
      p = nd + cp + 1, dir = 1;
    else if (p->v == '<') {
      dir = 0;
      if (!isdigit(p->l->v)) p->l->r = p->r, p->r->l = p->l;
      p = p->l;
    } else if (p->v == '>') {
      dir = 1;
      if (!isdigit(p->r->v)) p->l->r = p->r, p->r->l = p->l;
      p = p->r;
    } else {
      dig[tot][p->v - '0']++;
      if (p->v == '0')
        p->l->r = p->r, p->r->l = p->l;
      else
        --p->v;
      if (dir)
        p = p->r;
      else
        p = p->l;
    }
  }
  for (int j = 1; j < n + 3; j++) c[j] = tot + 1;
  for (int j = tot + 1 - 1; j >= 1; j--) {
    if (fb[vr[j]] == j) lt[vr[j]] = query(vr[j]);
    modify(vr[j] + 1, j);
  }
  for (int j = 1; j < tot + 1; j++)
    for (int i = 0; i < 10; i++) dig[j][i] += dig[j - 1][i];
  for (int i = 0; i < Q; i++) {
    scanf("%d%d", &l, &r);
    int cl = fb[l], cr = min(lt[l], fb[r + 1]) - 1;
    for (int j = 0; j < 10; j++) printf("%d ", dig[cr][j] - dig[cl - 1][j]);
    puts("");
  }
}
