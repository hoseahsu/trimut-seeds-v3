#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, q, type, x, k, ans, cnt[N], num, mx, tmp;
pair<int, int> a[N];
queue<int> qu;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> type >> x;
    if (type == 1) {
      qu.push(x);
      cnt[x]++, ans++;
      a[x].first = ++num;
      if (a[x].second == 0) a[x].second = num;
    } else if (type == 2)
      ans -= cnt[x], cnt[x] = 0, a[x].first = a[x].second = 0;
    else if (type == 3 && x > mx) {
      tmp = mx + 1, mx = x;
      while (tmp <= x) {
        k = qu.front();
        qu.pop();
        if (a[k].second <= tmp && a[k].first >= tmp) cnt[k]--, ans--;
        if (tmp == a[k].first) a[k].second = a[k].first = 0;
        tmp++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
