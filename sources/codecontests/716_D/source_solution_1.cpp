#include <bits/stdc++.h>
using namespace std;
struct node {
  long long toit, next, from;
  long long cap;
} road[200010];
long long q[3000010], n, m, s, t, cnt = 1;
long long l;
long long dis1[20010], dis2[20010];
long long listt[20010], vis[20010], in[20010];
inline void add(long long u, long long v, long long w) {
  road[++cnt].toit = v;
  road[cnt].next = listt[u];
  listt[u] = cnt;
  road[cnt].cap = w;
  road[cnt].from = u;
}
inline void spfa(int s) {
  dis1[s] = 0;
  long long head = 0, tail = 1;
  q[tail] = s;
  in[s] = 1;
  while (head < tail) {
    int u = q[++head];
    for (int w = listt[u]; w > 0; w = road[w].next) {
      int v = road[w].toit;
      if (dis1[v] <= dis1[u] + road[w].cap) continue;
      dis1[v] = dis1[u] + road[w].cap;
      if (in[v]) continue;
      in[v] = 1;
      q[++tail] = v;
    }
    in[u] = 0;
  }
}
inline void SPFA(long long s) {
  dis2[s] = 0;
  long long head = 0, tail = 1;
  q[tail] = s;
  in[s] = 1;
  while (head < tail) {
    int u = q[++head];
    for (int w = listt[u]; w > 0; w = road[w].next) {
      int v = road[w].toit;
      if (vis[w])
        road[w xor 1].cap = road[w].cap =
            max(road[w].cap, l - dis1[v] - dis2[u]);
      if (dis2[v] <= dis2[u] + road[w].cap) continue;
      dis2[v] = dis2[u] + road[w].cap;
      if (in[v] == 1) continue;
      in[v] = 1;
      q[++tail] = v;
    }
    in[u] = 0;
  }
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &m, &l, &s, &t);
  for (long long i = 0; i <= n; i++) vis[i] = 0;
  for (long long i = 0; i <= n; i++) dis1[i] = 1e15;
  for (long long i = 0; i <= n; i++) dis2[i] = 1e15;
  long long a, b, c;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &a, &b, &c);
    if (c == 0) vis[cnt + 1] = 1, vis[cnt + 2] = 1, c = 1;
    add(a, b, c);
    add(b, a, c);
  }
  for (long long i = 0; i <= n; i++) in[i] = 0;
  spfa(t);
  for (long long i = 0; i <= n; i++) in[i] = 0;
  SPFA(s);
  if (dis2[t] != l) {
    printf("NO");
    return 0;
  }
  printf("YES\n");
  for (int i = 2; i <= m * 2; i++)
    if (!(i & 1))
      printf("%lld %lld %lld\n", road[i].from, road[i].toit, road[i].cap);
  return 0;
}
