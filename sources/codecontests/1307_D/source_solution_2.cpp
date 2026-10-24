#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
int n, m, k;
vector<bool> S;
vector<vector<int> > G;
int shortst_path(vector<vector<int> >& G, int a, int b) {
  vector<bool> visited(n, false);
  queue<pii> Q;
  Q.push({a, 0});
  visited[a] = true;
  while (1) {
    auto c = Q.front();
    Q.pop();
    for (auto v : G[c.first]) {
      if (!visited[v]) {
        if (v == b) {
          return c.second + 1;
        }
        Q.push({v, c.second + 1});
        visited[v] = true;
      }
    }
  }
}
void get_distances(int s, vector<pii>& D) {
  queue<pii> Q;
  Q.push({s, 0});
  vector<bool> visited(n, false);
  visited[s] = true;
  if (S[s]) {
    D.push_back({0, s});
  }
  while (!Q.empty()) {
    auto c = Q.front();
    int node = c.first;
    int distance = c.second + 1;
    Q.pop();
    for (auto v : G[node]) {
      if (!visited[v]) {
        Q.push({v, distance});
        if (S[v]) {
          D.push_back({distance, v});
        }
        visited[v] = true;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> m >> k;
  S.resize(n, false);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    x--;
    S[x] = true;
  }
  G.resize(n, vector<int>());
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<pii> A, B;
  get_distances(0, A);
  get_distances(n - 1, B);
  vector<int> BB(n);
  for (auto b : B) {
    BB[b.second] = b.first;
  }
  int b = BB[A[k - 1].second];
  int result = 1;
  for (int i = k - 2; i >= 0; --i) {
    result = max(result, A[i].first + b + 1);
    b = max(b, BB[A[i].second]);
  }
  cout << min(shortst_path(G, 0, n - 1), result) << endl;
  return 0;
}
