#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string P[N];
bitset<26> bs[N];
int FindMax(int n, char c) {
  int l = P[n].length();
  int cnt = 0, mx = 0;
  int pre = -1, suff = -1;
  for (int i = 0; i < l; i++) {
    if (P[n][i] == c) {
      cnt++;
      mx = max(mx, cnt);
    } else {
      if (pre == -1) pre = cnt;
      cnt = 0;
    }
  }
  suff = cnt;
  if (n == 1) {
    return mx;
  }
  if (cnt == l) {
    int m = FindMax(n - 1, c);
    return (m + 1) * l + m;
  } else {
    int m = FindMax(n - 1, c);
    if (m) {
      mx = max(mx, suff + 1 + pre);
    }
    return mx;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> P[i];
  }
  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = max(ans, FindMax(n, c));
  }
  cout << ans << "\n";
  return 0;
}
