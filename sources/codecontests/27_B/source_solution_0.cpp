#include <bits/stdc++.h>
using namespace std;
bool solve(const vector<vector<int> > &v, bool *visited, int s, int q) {
  if (visited[s]) return false;
  visited[s] = true;
  for (int i = 1; i <= v.size(); i++) {
    if (v[s][i] == 1) {
      if (i == q) return true;
      if (solve(v, visited, i, q)) return true;
    }
  }
  return false;
}
int solve(const vector<vector<int> > &v, int s, int q) {
  bool visited[v.size() + 1];
  for (int i = 0; i < v.size() + 1; i++) visited[i] = false;
  if (solve(v, visited, s, q)) return 1;
  return -1;
}
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int> > v(n + 1);
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) v[i].push_back(0);
  }
  for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a][b] = (1);
    v[b][a] = (-1);
  }
  for (int i = 1; i <= n; i++) {
    bool haveIt = false;
    int j;
    for (j = 1; j <= n; j++) {
      if (i != j && v[i][j] == 0) {
        if (solve(v, i, j) == 1) {
          cout << i << " " << j << endl;
        } else {
          cout << j << " " << i << endl;
        }
        goto out;
      }
    }
  }
out:
  return 0;
}
