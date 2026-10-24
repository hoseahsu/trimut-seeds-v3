#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<int> pasa;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pasa.push_back(x);
    }
    if (*min_element(pasa.begin(), pasa.end()) ==
        *max_element(pasa.begin(), pasa.end())) {
      cout << -1 << "\n";
      continue;
    }
    int w = *max_element(pasa.begin(), pasa.end());
    for (int i = 0; i < n; i++) {
      if (pasa[i] == w) {
        if (i == 0) {
          if (pasa[i + 1] < pasa[i]) {
            cout << i + 1 << "\n";
            break;
          }
        } else if (i == n - 1) {
          if (pasa[i - 1] < pasa[i]) {
            cout << i + 1 << "\n";
            break;
          }
        } else {
          if (pasa[i - 1] < pasa[i] || pasa[i + 1] < pasa[i]) {
            cout << i + 1 << "\n";
            break;
          }
        }
      }
    }
  }
  return 0;
}
