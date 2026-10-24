#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxN = 700 + 10;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
const long double pi = acos(-1.0);
int dp[maxN][maxN][3][3];
int n;
int acc[maxN];
char s[maxN];
int solve(int l, int r, int colLeft, int colRight) {
  if (l > r) return 1;
  if (dp[l][r][colLeft][colRight] != -1) {
    return dp[l][r][colLeft][colRight];
  }
  int &temp = dp[l][r][colLeft][colRight];
  temp = 0;
  int idx = acc[l];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i != 0 && i == colLeft) continue;
      if (idx == r && j == colRight && j != 0) continue;
      if (i != 0 && j == 0) {
        temp += (solve(l + 1, idx - 1, i, j) * 1LL *
                 solve(idx + 1, r, j, colRight)) %
                mod;
      }
      if (i == 0 && j != 0) {
        temp += (solve(l + 1, idx - 1, i, j) * 1LL *
                 solve(idx + 1, r, j, colRight)) %
                mod;
      }
      temp %= mod;
    }
  }
  return temp;
}
int main() {
  memset(dp, -1, sizeof dp);
  gets(s + 1);
  n = strlen(s + 1);
  stack<int> st;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == ')') {
      acc[i] = st.top();
      acc[st.top()] = i;
      st.pop();
    } else {
      st.push(i);
    }
  }
  cout << solve(1, n, 0, 0) << '\n';
  return 0;
}
