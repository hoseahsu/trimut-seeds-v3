#include <bits/stdc++.h>
using namespace std;
const int MX = 1000000 + 10;
int n, m, cp, cv[MX], in[MX];
vector<int> a[MX], ad[MX];
;
vector<pair<int, pair<int, int> > > xx[MX], yy[MX];
bool mark[MX];
int cmp[MX];
vector<int> adj[MX];
inline int num(int x, int y) { return x * m + y; }
void DSS(int v) {
  mark[v] = true;
  cmp[v] = cp;
  for (int i = 0; i < (int)ad[v].size(); i++) {
    if (!mark[ad[v][i]]) DSS(ad[v][i]);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0, x; j < m; j++) {
      cin >> x;
      a[i].push_back(x);
      xx[i].push_back(make_pair(x, make_pair(i, j)));
      yy[j].push_back(make_pair(x, make_pair(i, j)));
    }
  for (int i = 0; i < n; i++) {
    sort(xx[i].begin(), xx[i].end());
    for (int j = 0; j < m - 1; j++) {
      if (xx[i][j].first == xx[i][j + 1].first) {
        ad[num(xx[i][j].second.first, xx[i][j].second.second)].push_back(
            num(xx[i][j + 1].second.first, xx[i][j + 1].second.second));
        ad[num(xx[i][j + 1].second.first, xx[i][j + 1].second.second)]
            .push_back(num(xx[i][j].second.first, xx[i][j].second.second));
      }
    }
  }
  for (int j = 0; j < m; j++) {
    sort(yy[j].begin(), yy[j].end());
    for (int i = 0; i < n - 1; i++) {
      if (yy[j][i].first == yy[j][i + 1].first) {
        ad[num(yy[j][i].second.first, yy[j][i].second.second)].push_back(
            num(yy[j][i + 1].second.first, yy[j][i + 1].second.second));
        ad[num(yy[j][i + 1].second.first, yy[j][i + 1].second.second)]
            .push_back(num(yy[j][i].second.first, yy[j][i].second.second));
      }
    }
  }
  cp = 1;
  for (int i = 0; i < n * m; i++) {
    if (!mark[i]) DSS(i), cp++;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      if (xx[i][j].first != xx[i][j + 1].first) {
        int p = cmp[num(xx[i][j].second.first, xx[i][j].second.second)],
            q = cmp[num(xx[i][j + 1].second.first, xx[i][j + 1].second.second)];
        adj[p].push_back(q);
        in[q]++;
      }
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n - 1; i++)
      if (yy[j][i].first != yy[j][i + 1].first) {
        int p = cmp[num(yy[j][i].second.first, yy[j][i].second.second)],
            q = cmp[num(yy[j][i + 1].second.first, yy[j][i + 1].second.second)];
        adj[p].push_back(q);
        in[q]++;
      }
  memset(mark, false, sizeof(mark));
  queue<int> pros;
  for (int i = 0; i < n * m; i++) {
    if (in[cmp[i]] == 0 && !mark[cmp[i]])
      pros.push(cmp[i]), mark[cmp[i]] = true;
  }
  while (!pros.empty()) {
    int v = pros.front();
    if (cv[v] == 0) cv[v] = 1;
    for (int i = 0; i < (int)adj[v].size(); i++) {
      int u = adj[v][i];
      cv[u] = max(cv[u], cv[v] + 1);
      in[u]--;
      if (in[u] == 0) pros.push(u), in[u]--;
    }
    pros.pop();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << cv[cmp[num(i, j)]] << " ";
    }
    cout << endl;
  }
  return 0;
}
