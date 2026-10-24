#include <bits/stdc++.h>
const int maxn = 5E5 + 77;
const int log2maxn = 21;
const long long INF = 1E18 + 77;
struct EDGE {
  int to, next;
} edges[maxn * 2];
int cEdge = 1, head[maxn];
void addEdge(int from, int to) {
  edges[cEdge] = (EDGE){to, head[from]};
  head[from] = cEdge++;
}
long long W = 0;
int N, A[maxn], R = 1, Pa[maxn][log2maxn];
void dfs(int u, int f) {
  Pa[u][0] = f;
  for (int k = 1; k < log2maxn; ++k) Pa[u][k] = Pa[Pa[u][k - 1]][k - 1];
  if (u != R) {
    W += A[u];
    long long m = INF;
    for (int k = 0; k < log2maxn; ++k) {
      int p = Pa[u][k];
      if (!p) p = R;
      long long t = (k + 1) * (long long)A[p];
      m = std::min(m, t);
    }
    W += m;
  }
  for (int k = head[u]; k; k = edges[k].next) {
    int v = edges[k].to;
    if (v == f) continue;
    dfs(v, u);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", A + i);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  for (int i = 2; i <= N; ++i)
    if (A[i] < A[R]) R = i;
  dfs(R, 0);
  std::cout << W << std::endl;
}
