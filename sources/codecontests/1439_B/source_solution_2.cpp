#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const int N = 100005;
int n, m, k;
unordered_set<int> adj[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 1; i < n + 1; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].insert(y);
      adj[y].insert(x);
    }
    set<pair<int, int>> S;
    vector<int> clique;
    for (int i = 1; i < n + 1; i++) S.insert({adj[i].size(), i});
    while (!S.empty() && S.begin()->first < k) {
      int x = S.begin()->second;
      S.erase(S.begin());
      if (adj[x].size() == k - 1 && k * (k - 1) / 2 <= m) {
        vector<int> v;
        for (auto it : adj[x]) v.push_back(it);
        v.push_back(x);
        bool possible = true;
        for (auto it : v) {
          for (auto it1 : v) {
            if (it == it1) continue;
            if (adj[it].find(it1) == adj[it].end()) {
              possible = false;
              break;
            }
          }
        }
        if (possible) {
          clique = v;
          break;
        }
      }
      for (auto y : adj[x]) {
        if (S.find({adj[y].size(), y}) != S.end()) {
          auto it = S.find({adj[y].size(), y});
          adj[y].erase(x);
          S.erase(it);
          S.insert({adj[y].size(), y});
        }
      }
      adj[x].clear();
    }
    if (!clique.empty()) {
      cout << 2 << '\n';
      for (auto it : clique) cout << it << ' ';
      cout << '\n';
    } else if (!S.empty()) {
      cout << 1 << ' ' << S.size() << '\n';
      for (auto it : S) cout << it.second << ' ';
      cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
