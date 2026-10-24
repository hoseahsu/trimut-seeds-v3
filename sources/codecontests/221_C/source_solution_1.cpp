#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> sorted(n);
  vector<int> other(n);
  for (int i = 0; i < n; i++) {
    cin >> sorted[i];
    other[i] = sorted[i];
  }
  sort(sorted.begin(), sorted.end());
  bool can = 1;
  for (int i = 0; i < n; i++) {
    if (sorted[i] != other[i]) {
      if (!can) {
        cout << "NO\n";
        return 0;
      }
      for (int j = n - 1; j > i; j--) {
        if (other[j] == sorted[i]) {
          swap(other[j], other[i]);
          break;
        }
      }
      can = 0;
    }
  }
  cout << "YES\n";
  return 0;
}
