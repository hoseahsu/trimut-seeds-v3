#include <bits/stdc++.h>
using namespace std;
struct songs {
  long long x, y;
} a[300010];
bool cmp(songs a, songs b) { return a.y > b.y; }
int main() {
  long long n, m;
  cin >> n >> m;
  priority_queue<long long, vector<long long>, greater<long long> > q;
  long long sum = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) {
    sum += a[i].x;
    q.push(a[i].x);
    if (q.size() > m) {
      sum -= q.top();
      q.pop();
    }
    if (sum * a[i].y > ans) ans = sum * a[i].y;
  }
  cout << ans << endl;
  return 0;
}
