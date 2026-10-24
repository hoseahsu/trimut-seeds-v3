#include <bits/stdc++.h>
using namespace std;
bool ok[1000005];
int n;
int x[500000];
bool done[500000];
int main() {
  scanf("%d", &n);
  long long sum = 0;
  int s = 1000000;
  vector<int> ans;
  for (int i = 0; i < n; ++i) scanf("%d", x + i), sum += x[i], ok[x[i]] = 1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (ok[s - x[i] + 1] == 0)
      done[i] = 1, ans.push_back(s - x[i] + 1), ok[s - x[i] + 1] = 1;
    else
      cnt++;
  }
  cnt /= 2;
  for (int i = 1; i <= 500000; ++i)
    if (!ok[i] && cnt) ans.push_back(i), ans.push_back(s - i + 1), cnt--;
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
}
