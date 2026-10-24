#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[200010];
int dist1[200010];
int dist2[200010];
int dist3[200010];
void dfs(int node, int p, int dist[], int d) {
  dist[node] = d;
  for (int i = 0; i < adjList[node].size(); i++) {
    int nxt = adjList[node][i];
    if (nxt == p) continue;
    dfs(nxt, node, dist, d + 1);
  }
}
int len[200010];
void fold(int node, int p = -1) {
  set<int> s;
  for (int i = 0; i < adjList[node].size(); i++) {
    int nxt = adjList[node][i];
    if (nxt == p) continue;
    fold(nxt, node);
    if (len[nxt] == -1) {
      len[node] = -1;
      return;
    }
    s.insert(len[nxt]);
  }
  if (p == -1) {
    if ((int)s.size() > 2)
      len[node] = -1;
    else {
      int sum = 0;
      for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        sum += *it;
      }
      len[node] = sum + (int)s.size();
    }
  } else {
    if ((int)s.size() > 1) {
      len[node] = -1;
    } else if (s.empty()) {
      len[node] = 0;
    } else
      len[node] = *(s.begin()) + 1;
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int fr, to;
    scanf("%d", &fr);
    scanf("%d", &to);
    fr--, to--;
    adjList[fr].push_back(to);
    adjList[to].push_back(fr);
  }
  memset(dist1, 0, sizeof(dist1));
  dfs(0, -1, dist1, 0);
  int maxidx = 0;
  int rem;
  for (int i = 0; i < n; i++) {
    if (dist1[maxidx] < dist1[i]) maxidx = i;
  }
  rem = maxidx;
  memset(dist2, 0, sizeof(dist2));
  dfs(maxidx, -1, dist2, 0);
  int maxdist = 0;
  for (int i = 0; i < n; i++) {
    if (dist2[maxidx] < dist2[i]) maxidx = i;
    maxdist = max(maxdist, dist2[i]);
  }
  memset(dist3, 0, sizeof(dist3));
  dfs(maxidx, -1, dist3, 0);
  int ctr = maxidx;
  for (int i = 0; i < n; i++) {
    if (dist2[i] + dist3[i] == dist3[rem] &&
        min(dist3[i], dist2[i]) > min(dist3[ctr], dist2[ctr])) {
      ctr = i;
    }
  }
  memset(len, 0, sizeof(len));
  fold(ctr);
  if (len[ctr] == -1)
    printf("-1");
  else {
    while (len[ctr] % 2 == 0 && len[ctr] != 0) len[ctr] /= 2;
    printf("%d", len[ctr]);
  }
  return 0;
}
