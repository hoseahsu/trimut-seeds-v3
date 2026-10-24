#include <bits/stdc++.h>
using namespace std;
int getShortestDominate(int n, vector<int> a) {
  vector<int> m[n + 1];
  for (int i = 0; i < n; i++) m[a[i]].push_back(i);
  const int FAIL = n + 9;
  int ans = FAIL;
  for (int v = 1; v <= n; v++) {
    for (int i = 0; i + 1 < m[v].size(); i++) {
      ans = min(ans, m[v][i + 1] - m[v][i] + 1);
    }
  }
  if (ans == FAIL) return -1;
  return ans;
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = getShortestDominate(n, a);
    printf("%d\n", ans);
  }
  return 0;
}
