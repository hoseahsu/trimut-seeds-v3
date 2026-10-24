#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
pair<int, int> dp[1002][1002];
pair<int, int> d[1002][1002];
map<int, int> m;
vector<int> vec;
int binary(int e) {
  int l = 0;
  int r = vec.size();
  int ans = 0;
  int mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (vec[mid] == e) {
      ans = mid;
      break;
    } else if (vec[mid] > e)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int main() {
  int n, k;
  int i, j, e;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      scanf("%d", &e);
      a[i][j] = e;
    }
  }
  pair<int, int> p, q;
  int ii, jj;
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      if (m.count(a[i][j]) == 0)
        m[a[i][j]] = 1;
      else
        m[a[i][j]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      vec.push_back(it->first);
    }
    p.first = m.size();
    for (j = 0; j < k; j++) {
      ii = binary(a[i][j]);
      p.second = ii;
      dp[i][j] = p;
    }
    m.clear();
    vec.clear();
  }
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      if (m.count(a[j][i]) == 0)
        m[a[j][i]] = 1;
      else
        m[a[j][i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      vec.push_back(it->first);
    }
    p.first = m.size();
    for (j = 0; j < n; j++) {
      ii = binary(a[j][i]);
      p.second = ii;
      d[j][i] = p;
    }
    m.clear();
    vec.clear();
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      if (dp[i][j].second >= d[i][j].second) {
        printf("%d ", max(dp[i][j].first,
                          d[i][j].first + dp[i][j].second - d[i][j].second));
      } else
        printf("%d ", max(d[i][j].first,
                          dp[i][j].first + d[i][j].second - dp[i][j].second));
    }
    printf("\n");
  }
  return 0;
}
