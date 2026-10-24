#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[200005], a[200005];
bool gone[200005], vis[200005];
vector<int> ppl[200005];
pair<int, int> xy[200005];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    ppl[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    xy[i] = make_pair(x, y);
    a[xy[i].first]++;
    a[xy[i].second]++;
    ppl[x].push_back(i);
    ppl[y].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (a[i])
      pq.push(make_pair(max(0, a[i] - w[i]), i));
    else
      gone[i] = 1;
  }
  vector<int> ret;
  while (pq.size()) {
    pair<int, int> tp = pq.top();
    pq.pop();
    if (tp.first != max(0, a[tp.second] - w[tp.second])) continue;
    if (tp.first > 0) {
      cout << "DEAD" << endl;
      return 0;
    }
    int ind = tp.second;
    vector<int> rem;
    for (int q : ppl[ind]) {
      if (vis[q]) continue;
      vis[q] = 1;
      ret.push_back(q);
      int at = xy[q].first;
      int ot = xy[q].second;
      if (xy[q].first != ind) {
        int tmp = at;
        at = ot;
        ot = tmp;
      }
      if (!gone[ot]) {
        rem.push_back(ot);
      }
    }
    sort(rem.begin(), rem.end());
    for (int i = 0; i < rem.size(); i++) {
      a[rem[i]]--;
      if ((i == rem.size() - 1 || rem[i] != rem[i + 1]) && a[rem[i]]) {
        if (max(0, a[rem[i]] - w[rem[i]]) == 0) gone[rem[i]] = 1;
        pq.push(make_pair(max(0, a[rem[i]] - w[rem[i]]), rem[i]));
      }
    }
  }
  cout << "ALIVE" << endl;
  reverse(ret.begin(), ret.end());
  for (int q : ret) {
    cout << q + 1 << " ";
  }
  cout << endl;
}
