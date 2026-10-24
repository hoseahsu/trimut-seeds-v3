#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int N = 10 + 1e5;
using namespace std;
void Ferrari() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  Ferrari();
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    vector<int> pos(c);
    for (int& i : pos) cin >> i;
    sort(pos.begin(), pos.end());
    bool f = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++)
        if (v[j] > v[j + 1]) {
          if (!binary_search(pos.begin(), pos.end(), j + 1)) {
            f = 0;
            break;
          }
          swap(v[j], v[j + 1]);
        }
      if (!f) break;
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
  return 0;
}
