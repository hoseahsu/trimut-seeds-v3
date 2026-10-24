#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> q[100005];
int f, t;
int p[100005];
bool r;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &f, &t);
    q[f].push_back(i), q[t].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (q[i].size() >= 3) {
      r = 1;
      for (int j = 0; j <= 2; j++) {
        p[q[i][j]] = j + 1;
      }
      break;
    }
  }
  if (r == 0) {
    for (int i = 0; i < n - 1; i++) {
      cout << i << endl;
    }
    return 0;
  }
  int cnt = 2;
  for (int i = 1; i <= n - 1; i++) {
    if (p[i] == 3) cout << 0 << endl;
    if (p[i] == 1) cout << 1 << endl;
    if (p[i] == 2) cout << 2 << endl;
    if (p[i] == 0) cout << ++cnt << endl;
  }
}
