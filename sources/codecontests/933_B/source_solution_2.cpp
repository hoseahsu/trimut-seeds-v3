#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 2e3 + 5;
long long p;
int k;
vector<int> ans;
void solve(long long r) {
  if (r < k && r > 0) {
    ans.push_back(r);
    return;
  }
  long long s = ((r < 0) * (k - 1) + abs(r)) / k;
  if (r > 0) s = -s;
  int y = r + s * k;
  ans.push_back(y);
  solve(s);
}
int main() {
  scanf("%lld %d", &p, &k);
  solve(p);
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d ", i);
  return 0;
}
