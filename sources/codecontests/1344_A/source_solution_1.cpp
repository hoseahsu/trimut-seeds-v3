#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int q;
  cin >> q;
  for (int k = 0; k < q; k++) {
    int n;
    cin >> n;
    vector<int> v(n), live(n, 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      live[i]--;
      long long to = i + v[i];
      if (to < 0) to += (long long)n * (-1 * to / n + 1);
      to %= n;
      live[to]++;
    }
    bool flag = 1;
    for (int i = 0; i < n; i++) {
      if (live[i] != 1) {
        cout << "NO\n";
        flag = 0;
        break;
      }
    }
    if (flag) cout << "YES\n";
  }
}
