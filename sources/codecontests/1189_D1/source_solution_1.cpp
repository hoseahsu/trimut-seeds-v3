#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ind[n];
  memset(ind, 0, sizeof(ind));
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    ind[u]++;
    ind[v]++;
  }
  bool f = 1;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (ind[i] == 2) {
      return cout << "NO", 0;
    }
  }
  cout << "YES";
}
