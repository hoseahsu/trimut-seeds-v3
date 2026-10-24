#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<pair<ll, pl>> v;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    vl a(n);
    for (auto &j : a) cin >> j;
    ll sum = accumulate(begin(a), end(a), 0LL);
    for (int j = 0; j < n; j++) {
      v.push_back({sum - a[j], {i + 1, j + 1}});
    }
  }
  sort(begin(v), end(v));
  int cnt = 0;
  int N = (int)(v).size();
  for (int i = 0; i < N - 1; i++) {
    if (v[i].first == v[i + 1].first &&
        v[i].second.first != v[i + 1].second.first) {
      cout << "YES" << '\n';
      cout << v[i].second.first << " " << v[i].second.second << '\n';
      cout << v[i + 1].second.first << " " << v[i + 1].second.second << '\n';
      cnt++;
      break;
    }
  }
  if (!cnt) cout << "NO";
  return 0;
}
