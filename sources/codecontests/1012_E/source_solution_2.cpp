#include <bits/stdc++.h>
using namespace std;
template <class BidirIt>
BidirIt prev(BidirIt it,
             typename iterator_traits<BidirIt>::difference_type n = 1) {
  advance(it, -n);
  return it;
}
template <class ForwardIt>
ForwardIt next(ForwardIt it,
               typename iterator_traits<ForwardIt>::difference_type n = 1) {
  advance(it, n);
  return it;
}
const double EPS = 1e-9;
const double PI = 3.141592653589793238462;
template <typename T>
inline T sq(T a) {
  return a * a;
}
const int MAXN = 4e5 + 5;
int ar[MAXN], sor[MAXN];
map<int, int> dummy;
bool visit[MAXN], proc[MAXN];
int nxt[MAXN];
vector<int> gr[MAXN];
vector<int> cur, tour[MAXN];
vector<vector<int> > cycles;
void addEdge(int u, int v) { gr[u].push_back(v); }
void dfs(int u) {
  visit[u] = true;
  cur.push_back(u);
  while (nxt[u] < (int)gr[u].size()) {
    int v = gr[u][nxt[u]];
    nxt[u]++;
    dfs(v);
  }
  if (cur.size() > 0) {
    if (!tour[u].empty()) assert(false);
    tour[u] = cur;
    cur.clear();
  }
}
void getcycle(int u, vector<int> &vec) {
  proc[u] = true;
  for (auto it : tour[u]) {
    vec.push_back(it);
    if (!proc[it]) getcycle(it, vec);
  }
}
int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    sor[i] = ar[i];
  }
  sort(sor + 1, sor + n + 1);
  for (int i = 1; i <= n; i++) {
    if (ar[i] != sor[i]) dummy[ar[i]] = 0;
  }
  int cnt = 0;
  for (auto &it : dummy) it.second = n + (++cnt);
  for (int i = 1; i <= n; i++) {
    if (ar[i] == sor[i]) continue;
    addEdge(dummy[sor[i]], i);
    addEdge(i, dummy[ar[i]]);
  }
  for (int i = 1; i <= n + cnt; i++) {
    if ((i > n || ar[i] != sor[i]) && !visit[i]) {
      dfs(i);
      vector<int> vec;
      getcycle(i, vec);
      vector<int> res;
      for (auto it : vec)
        if (it <= n) res.push_back(it);
      res.pop_back();
      cycles.push_back(res);
      s -= (int)res.size();
    }
  }
  for (int i = 1; i <= n + cnt; i++)
    if (i > n || ar[i] != sor[i]) assert(proc[i]);
  if (s < 0) {
    puts("-1");
    return 0;
  }
  int pos = 0;
  if (s > 1 && cycles.size() > 1) {
    printf("%d\n", max(2, (int)cycles.size() - s + 2));
    int sum = 0;
    while (s > 0 && pos < (int)cycles.size()) {
      s--;
      sum += (int)cycles[pos].size();
      pos++;
    }
    printf("%d\n", sum);
    vector<int> vec;
    for (int i = 0; i < pos; i++) {
      for (auto it : cycles[i]) printf("%d ", it);
      vec.push_back(cycles[i][0]);
    }
    puts("");
    reverse((vec).begin(), (vec).end());
    printf("%d\n", (int)vec.size());
    for (auto it : vec) printf("%d ", it);
    puts("");
  } else {
    printf("%d\n", (int)cycles.size());
  }
  for (int i = pos; i < (int)cycles.size(); i++) {
    printf("%d\n", (int)cycles[i].size());
    for (auto it : cycles[i]) printf("%d ", it);
    puts("");
  }
  return 0;
}
