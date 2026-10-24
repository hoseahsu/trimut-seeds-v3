#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
unordered_map<int, vector<pair<int, int> > > rows;
unordered_map<int, vector<pair<int, int> > > cols;
int n, m;
int cnum;
map<pair<int, int>, int> id;
map<pair<int, int>, vector<pair<int, int> > > adj1;
unordered_map<int, vector<int> > adj2;
int dp[MAXN];
void fgreat(const vector<pair<int, int> >& v, int row, int col) {
  int sz = v.size();
  for (int i = 0; i < (sz - 1); ++i)
    if (v[i].first < v[i + 1].first) {
      if (row == -1) {
        adj2[id[make_pair(v[i + 1].second, col)]].push_back(
            id[make_pair(v[i].second, col)]);
      } else {
        adj2[id[{row, v[i + 1].second}]].push_back(
            id[make_pair(row, v[i].second)]);
      }
    }
}
void fequal(const vector<pair<int, int> >& v, int row, int col) {
  int sz = v.size();
  for (int i = 0; i < (sz - 1); ++i)
    if (v[i].first == v[i + 1].first) {
      if (row == -1) {
        adj1[{v[i].second, col}].push_back(make_pair(v[i + 1].second, col));
        adj1[{v[i + 1].second, col}].push_back(make_pair(v[i].second, col));
      } else {
        adj1[{row, v[i].second}].push_back(make_pair(row, v[i + 1].second));
        adj1[{row, v[i + 1].second}].push_back(make_pair(row, v[i].second));
      }
    }
}
void dfs(int sx, int sy) {
  id[{sx, sy}] = cnum;
  const auto& v = adj1[{sx, sy}];
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    if (!id.count(*it)) {
      dfs(it->first, it->second);
    }
}
int solve(int id) {
  int& ans = dp[id];
  if (ans != -1) return ans;
  ans = 0;
  const auto& v = adj2[id];
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    ans = max(ans, solve(*it));
  return ++ans;
}
int main() {
  scanf(" %d %d", &(n), &(m));
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      int x;
      scanf(" %d", &(x));
      rows[i].push_back(make_pair(x, j));
      cols[j].push_back(make_pair(x, i));
    }
  for (__typeof((rows).begin()) it = (rows).begin(); it != (rows).end(); ++it) {
    auto& v = it->second;
    sort(v.begin(), v.end());
  }
  for (__typeof((cols).begin()) it = (cols).begin(); it != (cols).end(); ++it) {
    auto& v = it->second;
    sort(v.begin(), v.end());
  }
  for (__typeof((rows).begin()) it = (rows).begin(); it != (rows).end(); ++it) {
    fequal(it->second, it->first, -1);
  }
  for (__typeof((cols).begin()) it = (cols).begin(); it != (cols).end(); ++it) {
    fequal(it->second, -1, it->first);
  }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      if (!id.count({i, j})) {
        dfs(i, j);
        ++cnum;
      }
  for (__typeof((rows).begin()) it = (rows).begin(); it != (rows).end(); ++it) {
    fgreat(it->second, it->first, -1);
  }
  for (__typeof((cols).begin()) it = (cols).begin(); it != (cols).end(); ++it) {
    fgreat(it->second, -1, it->first);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      if (j) printf(" ");
      printf("%d", solve(id[{i, j}]));
    }
    printf("\n");
  }
  return 0;
}
