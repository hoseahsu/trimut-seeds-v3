#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 100;
int n, m, mp[Maxn];
vector<pair<long long, int>> v;
int qcc(int p, int r) {
  int a = int(upper_bound(v.begin(), v.end(), make_pair(v[p].first + r, Maxn)) -
              v.begin() - 1);
  if (a == p)
    return int(lower_bound(v.begin(), v.end(), make_pair(v[p].first - r, 0)) -
               v.begin());
  else
    return a;
}
int main() {
  ios::sync_with_stdio(0);
  int i;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(make_pair(tmp, i));
  }
  sort(v.begin(), v.end());
  for (vector<pair<long long, int>>::iterator it = v.begin(); it != v.end();
       it++) {
    mp[it->second] = int(it - v.begin());
  }
  for (i = 0; i < m; i++) {
    int a, l;
    cin >> a >> l;
    int u = mp[a], tmp;
    while ((tmp = qcc(u, l)) != u) {
      if (qcc(tmp, l - int(v[tmp].first > v[u].first
                               ? (v[tmp].first - v[u].first)
                               : (v[u].first - v[tmp].first))) == u)
        l %= 2 * int(v[tmp].first > v[u].first ? (v[tmp].first - v[u].first)
                                               : (v[u].first - v[tmp].first));
      else {
        l -= int(v[tmp].first > v[u].first ? (v[tmp].first - v[u].first)
                                           : (v[u].first - v[tmp].first));
        u = tmp;
      }
    }
    cout << v[u].second << endl;
  }
  return 0;
}
