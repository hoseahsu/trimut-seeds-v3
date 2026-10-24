#include <bits/stdc++.h>
using namespace std;
set<int> st;
priority_queue<pair<long long, int> > q;
int l[10000], c[10000];
int n;
vector<int> cur;
inline int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) q.push(make_pair(-c[i], l[i]));
  while (!q.empty()) {
    long long cost = -q.top().first;
    int res = q.top().second;
    q.pop();
    if (st.find(res) != st.end()) continue;
    st.insert(res);
    if (res == 1) {
      cout << cost << endl;
      return 0;
    }
    for (int i = 0; i < cur.size(); i++) {
      int nres = gcd(l[cur[i]], res);
      long long ncost = cost + c[cur[i]];
      q.push(make_pair(-ncost, nres));
    }
    l[n] = res;
    c[n] = cost;
    cur.push_back(n);
    n++;
  }
  cout << -1 << endl;
  return 0;
}
