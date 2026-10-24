#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> towns(n), cells(m);
  for (int &t : towns) {
    cin >> t;
  }
  for (int &c : cells) {
    cin >> c;
  }
  auto town = towns.begin(), cell = cells.begin();
  int ans = 0;
  for (int currdist = numeric_limits<int>::max();;) {
    currdist = min(currdist, abs(*town - *cell));
    if (*cell >= *town) {
      ans = max(ans, currdist);
      if (town != towns.end() - 1) {
        ++town;
        currdist = abs(*town - *(cell - (cell != cells.begin())));
      } else {
        break;
      }
    } else {
      if (cell != cells.end() - 1) {
        ++cell;
      } else {
        ans = max(ans, abs(towns.back() - *cell));
        break;
      }
    }
  }
  cout << ans;
}
