#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dfs(int cur, const vector<int>& ks, vector<int>& step) {
  if (ks[cur] == -1) {
    return 0;
  }
  if (step[cur] != -1) {
    return step[cur];
  }
  return step[cur] = dfs(ks[cur], ks, step) + 1;
}
int main() {
  int n;
  cin >> n;
  vector<int> ns(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ns[i]);
  }
  vector<int> ks(n, -1);
  vector<int> step(n, 0);
  for (int i = 1; i < n; i++) {
    bool flag = true;
    int cur = i - 1;
    int maxi = 0;
    while (cur >= 0 && ns[cur] < ns[i]) {
      if (ks[cur] == -1) {
        flag = false;
        break;
      }
      maxi = max(maxi, step[cur]);
      cur = ks[cur];
    }
    if (flag) {
      step[i] = maxi + 1;
    }
    ks[i] = cur;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, step[i]);
  }
  cout << ans << endl;
  return 0;
}
