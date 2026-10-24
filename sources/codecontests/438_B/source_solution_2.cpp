#include <bits/stdc++.h>
using namespace std;
int N, M, wei[110000];
int st[110000], en[110000], id[110000];
bool cmp(int u, int v) {
  return min(wei[st[u]], wei[en[u]]) > min(wei[st[v]], wei[en[v]]);
}
int rt[110000], sz[110000];
int find(int u) {
  if (rt[u] == u) return u;
  return rt[u] = find(rt[u]);
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", &wei[i]);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &st[i], &en[i]);
    st[i]--, en[i]--;
    id[i] = i;
  }
  sort(id, id + M, cmp);
  for (int i = 0; i < N; i++) rt[i] = i, sz[i] = 1;
  double ans = 0;
  for (int i = 0; i < M; i++) {
    int u = st[id[i]], v = en[id[i]];
    int ru = find(u), rv = find(v);
    if (ru == rv) continue;
    ans += 1.0 * sz[ru] * sz[rv] * min(wei[u], wei[v]);
    rt[ru] = rv;
    sz[rv] += sz[ru];
  }
  ans /= 1.0 * N * (N - 1) / 2;
  printf("%.10lf\n", ans);
  return 0;
}
