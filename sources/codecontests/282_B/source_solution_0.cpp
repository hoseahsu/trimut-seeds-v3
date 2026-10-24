#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> dp[3][1000005];
int A[1000005], B[1000005];
int ma[3][1000005];
int main() {
  int n, x;
  pair<int, int> e1;
  pair<int, int> e2;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &A[i], &B[i]);
  dp[0][0] = make_pair(A[0], 0);
  dp[1][0] = make_pair(0, B[0]);
  for (int i = 1; i < n; i++) {
    e1 = dp[0][i - 1];
    e2 = dp[1][i - 1];
    if (abs((e1.first + A[i]) - e1.second) <=
        abs((e2.first + A[i]) - e2.second)) {
      dp[0][i] = make_pair((e1.first + A[i]), e1.second);
      ma[0][i] = 1;
    } else {
      dp[0][i] = make_pair(e2.first + A[i], e2.second);
      ma[0][i] = 2;
    }
    if (abs((e1.second + B[i]) - e1.first) <=
        abs((e2.second + B[i]) - e2.first)) {
      dp[1][i] = make_pair(e1.first, e1.second + B[i]);
      ma[1][i] = 1;
    } else {
      dp[1][i] = make_pair(e2.first, e2.second + B[i]);
      ma[1][i] = 2;
    }
  }
  if (abs(dp[0][n - 1].first - dp[0][n - 1].second) > 500 &&
      abs(dp[1][n - 1].first - dp[1][n - 1].second) > 500) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> l;
  int idx = n - 1, padre;
  if (abs(dp[0][n - 1].first - dp[0][n - 1].second) <= 500) {
    padre = 1;
    while (idx > 0) {
      l.push_back(padre);
      padre = ma[padre - 1][idx--];
    }
    l.push_back(padre);
  } else {
    padre = 2;
    while (idx > 0) {
      l.push_back(padre);
      padre = ma[padre - 1][idx--];
    }
    l.push_back(padre);
  }
  for (int i = n - 1; i >= 0; i--)
    if (l[i] == 1)
      cout << "A";
    else
      cout << "G";
  cout << endl;
  return 0;
}
