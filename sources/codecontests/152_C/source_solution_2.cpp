#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  int i, j, k;
  string s;
  set<char> numAlphabets[m];
  for (i = 0; i < n; i++) {
    cin >> s;
    for (k = 0; k < m; k++) {
      numAlphabets[k].insert(s[k]);
    }
  }
  long long int ans = 1;
  for (i = 0; i < m; i++) {
    ans = (ans * numAlphabets[i].size()) % 1000000007;
  }
  cout << ans;
}
