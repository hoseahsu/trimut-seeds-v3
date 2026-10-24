#include <bits/stdc++.h>
using namespace std;
vector<int> place[100100];
int x, i, j, kj, n, m, k, ans;
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> x;
    place[x].push_back(i);
  }
  for (i = 1; i <= m; i++) {
    j = 0;
    for (kj = 0; kj < place[i].size(); kj++) {
      while (j < place[i].size() && place[i][j] - place[i][kj] <= k + (j - kj))
        j++;
      ans = max(ans, j - kj);
    }
  }
  cout << ans;
  return 0;
}
