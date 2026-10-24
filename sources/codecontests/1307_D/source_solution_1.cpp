#include <bits/stdc++.h>
using namespace std;
class trio {
 public:
  long long first, second, third;
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m, k, u, v;
  cin >> n >> m >> k;
  long long arr[k];
  for (long long i = 0; i < k; ++i) {
    cin >> arr[i];
  }
  list<long long> adj[n + 1];
  for (long long i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long dp1[n + 1], dp2[n + 1], temp;
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  queue<long long> q;
  q.push(1);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    for (auto it : adj[temp]) {
      if (it != 1 && dp1[it] == 0) {
        dp1[it] = dp1[temp] + 1;
        q.push(it);
      }
    }
  }
  q.push(n);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    for (auto it : adj[temp]) {
      if (it != n && dp2[it] == 0) {
        dp2[it] = dp2[temp] + 1;
        q.push(it);
      }
    }
  }
  vector<pair<long long, long long> > d;
  for (long long i = 0; i < k; ++i) {
    d.push_back({dp1[arr[i]], arr[i]});
  }
  sort(d.begin(), d.end());
  temp = 0;
  for (long long i = 0; i < k - 1; ++i) {
    temp = max(temp, dp1[d[i].second] + dp2[d[i + 1].second] + 1);
  }
  cout << min(dp1[n], temp);
  return 0;
}
