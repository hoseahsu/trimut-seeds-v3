#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n, l, r;
  cin >> n >> l >> r;
  l--, r--;
  int64_t cnt = 0;
  int64_t start = 1;
  int64_t num = n - 1;
  while (start < n) {
    if (l < cnt + 2 * num && r >= cnt) {
      for (int64_t i = 0; i < 2 * num; i++) {
        if (l <= cnt + i && cnt + i <= r) {
          if (i & 1)
            cout << start + (i + 1) / 2 << ' ';
          else
            cout << start << ' ';
        }
      }
    }
    cnt += 2 * num;
    num--;
    start++;
  }
  if (r == cnt) cout << 1;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
