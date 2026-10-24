#include <bits/stdc++.h>
using namespace std;
int online[150001], friend_val[150001];
int main() {
  int i, n, k, q, t, type, val, curr;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  scanf("%d%d%d", &n, &k, &q);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &t);
    friend_val[i] = t;
  }
  for (i = 1; i <= q; ++i) {
    scanf("%d%d", &type, &val);
    if (type == 1) {
      pq.push(pair<int, int>(friend_val[val], val));
      online[val] = 1;
      if ((int)pq.size() - 1 >= k) {
        curr = pq.top().second;
        pq.pop();
        online[curr] = 0;
      }
    } else {
      if (online[val] == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
