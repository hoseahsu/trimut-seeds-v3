#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 1e2 + 5;
unsigned long long a, z[101], vis[101], ok = 0;
vector<unsigned long long> ans;
void dfs(unsigned long long u, unsigned long long le) {
  if (u % 3 == 0) {
    for (unsigned long long i = 1; i <= a; i++) {
      if (z[i] == u / 3) {
        vis[i] = 1;
        dfs(z[i], le + 1);
      }
    }
  }
  for (unsigned long long i = 1; i <= a; i++) {
    if (u * 2 == z[i]) {
      vis[i] = 1;
      dfs(z[i], le + 1);
    }
  }
  if (le == a and ok == 0) {
    ans.push_back(u);
    ok = 1;
    ok = a - 1;
  }
  if (le == ok) {
    ok--;
    ans.push_back(u);
  }
}
int32_t main() {
  cin >> a;
  for (unsigned long long i = 1; i <= a; i++) {
    cin >> z[i];
  }
  for (unsigned long long i = 1; i <= a; i++) {
    memset(vis, 0LL, sizeof(vis));
    vis[i] = 1;
    dfs(z[i], 1);
  }
  reverse(ans.begin(), ans.end());
  for (unsigned long long it : ans) {
    cout << it << " ";
  }
}
