#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
vector<pair<int, int> > v[maxn];
int n, m, k;
pair<int, int> stu[maxn];
int fro[maxn];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> stu[i].first;
  for (int i = 1; i <= n; ++i) cin >> stu[i].second;
  for (int i = 1; i <= n; ++i) {
    v[stu[i].second].push_back(make_pair(i, stu[i].first));
    fro[i] = stu[i].second;
  }
  for (int i = 1; i <= m; ++i) {
    sort(v[i].begin(), v[i].end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    });
  }
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    int t;
    cin >> t;
    if (v[fro[t]][0].first != t) ++ans;
  }
  cout << ans << endl;
}
