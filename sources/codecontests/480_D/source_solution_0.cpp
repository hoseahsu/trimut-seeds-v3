#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int maxn = 1100;
const long long inf = 2020202020202020202LL;
struct box {
  int in, out, w, s, v;
};
int dp[1100][1100], n, s, subdp[1100];
vector<box> nice;
bool cmp(const box& a, const box& b) {
  return a.in < b.in || a.in == b.in && a.out > b.out;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    box j;
    cin >> j.in >> j.out >> j.w >> j.s >> j.v;
    j.in++;
    j.out++;
    nice.push_back(j);
  }
  box jj = {0, 1002, 0, s, md};
  nice.push_back(jj);
  sort(nice.begin(), nice.end(), &cmp);
  for (int i = n; i >= 0; i--) {
    for (int pr = 0; pr < s + 1; pr++) {
      int prn = min(nice[i].s, pr - nice[i].w);
      if (prn >= 0) dp[i][pr] += nice[i].v;
      if (prn >= 0) {
        for (int it = nice[i].in; it <= nice[i].out; it++) subdp[it] = 0;
        int curr = 0;
        for (int u = n; u > i; u--) {
          if ((nice[i].in <= nice[u].in) && (nice[i].out >= nice[u].out)) {
            int x = subdp[nice[u].out] + dp[u][prn];
            if (x > curr) curr = x;
            subdp[nice[u].in] = curr;
          }
          int y = nice[u].in;
          while (nice[u - 1].in <= y) {
            subdp[y] = curr;
            y--;
          }
        }
        dp[i][pr] += subdp[nice[i].in];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < s + 1; i++) ans = max(ans, dp[0][i]);
  cout << ans - md;
  return 0;
}
