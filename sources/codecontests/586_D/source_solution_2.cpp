#include <bits/stdc++.h>
using namespace std;
void gt(int &a, int b) {
  if (a < b) a = b;
}
string n2s(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
string getKey(int v, int h) { return n2s(v) + "-" + n2s(h); }
int a[5][1000], h = 3, n, w, visit[5][1000]{0};
bool checkPath(vector<pair<int, int> > cells) {
  for (auto cell : cells) {
    bool valid = cell.first >= 1 && cell.first <= h && cell.second >= 1 &&
                 cell.second <= w && a[cell.first][cell.second];
    if (!valid) return false;
  }
  return true;
}
bool bfs(int si, int sj) {
  vector<pair<int, int> > cells;
  queue<pair<int, int> > q;
  memset(visit, 0, sizeof(visit));
  q.push({si, sj});
  visit[si][sj] = 1;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    if (j >= n) return true;
    vector<pair<int, int> > nexts;
    cells.clear();
    cells.push_back({i, j + 1});
    cells.push_back({i, j + 2});
    cells.push_back({i, j + 3});
    if (checkPath(cells)) nexts.push_back({i, j + 3});
    cells.clear();
    cells.push_back({i, j + 1});
    cells.push_back({i + 1, j + 1});
    cells.push_back({i + 1, j + 2});
    cells.push_back({i + 1, j + 3});
    if (checkPath(cells)) nexts.push_back({i + 1, j + 3});
    cells.clear();
    cells.push_back({i, j + 1});
    cells.push_back({i - 1, j + 1});
    cells.push_back({i - 1, j + 2});
    cells.push_back({i - 1, j + 3});
    if (checkPath(cells)) nexts.push_back({i - 1, j + 3});
    for (auto next : nexts)
      if (!visit[next.first][next.second]) {
        q.push(next);
        visit[next.first][next.second] = 1;
      }
  }
  return false;
}
int main() {
  int t, k, si = 0, sj = 0;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= n; j++) {
        char ch;
        cin >> ch;
        if (ch == '.') a[i][j] = 1;
        if (ch == 's') si = i, sj = j;
      }
    w = 3 * n + 1;
    for (int i = 1; i <= 3; i++)
      for (int j = n + 1; j <= w; j++) a[i][j] = 1;
    if (bfs(si, sj))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
