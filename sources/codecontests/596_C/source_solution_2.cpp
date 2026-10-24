#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
template <typename T>
void print(T v) {
  for (auto i = v.begin(); i != v.end(); i++) cout << setw(2) << *i << " ";
  cout << endl;
}
template <typename T>
void print_vv(T v, bool same_line = true) {
  for (auto i = 0; i < v.size(); i++) {
    cout << "{";
    for (auto j = 0; j != v[i].size(); j++) {
      cout << setw(3) << v[i][j] << ",";
    }
    cout << "},";
    if (same_line) cout << endl;
  }
  cout << endl;
}
int main() {
  int n;
  while (cin >> n) {
    map<int, vector<pair<int, int>>> queues;
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      queues[y - x].push_back({x, y});
    }
    for (auto &q : queues) {
      sort(queues[q.first].rbegin(), queues[q.first].rend());
    }
    vector<pair<int, int>> ans(n);
    int w;
    for (int i = 0; i < n; i++) {
      cin >> w;
      if (queues.find(w) == queues.end() || queues[w].empty()) {
        cout << "NO\n";
        return 0;
      }
      ans[i] = queues[w].back();
      queues[w].pop_back();
    }
    for (int i = 1; i < n; i++) {
      if (ans[i].first <= ans[i - 1].first &&
          ans[i].second <= ans[i - 1].second) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < int(n); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  return 0;
}
