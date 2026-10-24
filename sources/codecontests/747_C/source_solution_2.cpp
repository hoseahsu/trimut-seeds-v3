#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> servers;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < n; i++) {
    servers.push(i + 1);
  }
  int q, t, k, d;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t >> k >> d;
    while (pq.empty() == false) {
      pair<int, int> top = pq.top();
      if (top.first < t) {
        servers.push(top.second);
        pq.pop();
      } else {
        break;
      }
    }
    if (servers.size() >= k) {
      int total = 0, serverId;
      int endTime = t + d - 1;
      for (int j = 0; j < k; j++) {
        serverId = servers.top();
        servers.pop();
        total += serverId;
        pq.push(make_pair(endTime, serverId));
      }
      cout << total << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
