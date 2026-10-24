#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
long long ans;
int n;
priority_queue<int> q1, q2;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int t1, t2, x;
  for (register int i = (1); i <= (n); ++i) {
    cin >> x;
    t1 = t2 = -1;
    if (q1.size() && (-q1.top()) < x) t1 = x - (-q1.top());
    if (q2.size() && (-q2.top()) < x) t2 = x - (-q2.top());
    if (t1 == -1 && t2 == -1) {
      q2.push(-x);
      continue;
    }
    if (t2 > t1) {
      ans += t2;
      q2.pop();
      q1.push(-x);
    } else {
      ans += t1;
      q2.push(q1.top());
      q1.pop();
      q1.push(-x);
    }
  }
  cout << ans << '\n';
  return 0;
}
