#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
long double PI = 3.14159265358979323846264338327950;
const int N = 101, M = 1e7;
string virus, s, ss;
int memo[N][N][N];
int fail[N];
void updateLen(char c, int &len) {
  while (len && c != virus[len]) {
    len = fail[len - 1];
  }
  if (c == virus[len]) len++;
}
void getFailure() {
  int len = 0;
  for (int i = 1; i < (int)virus.size(); i++) {
    updateLen(virus[i], len);
    fail[i] = len;
  }
}
int solve(int i, int j, int curLen) {
  if (i == (int)s.size() || j == (int)ss.size()) {
    return 0;
  }
  int &ret = memo[i][j][curLen];
  if (~ret) {
    return ret;
  }
  ret = solve(i + 1, j, curLen);
  ret = max(ret, solve(i, j + 1, curLen));
  if (s[i] == ss[j]) {
    updateLen(s[i], curLen);
    if (curLen < (int)virus.size()) {
      ret = max(ret, solve(i + 1, j + 1, curLen) + 1);
    }
  }
  return ret;
}
void printPath(int i, int j, int curLen) {
  if (i == (int)s.size() || j == (int)ss.size()) {
    return;
  }
  int &ret = memo[i][j][curLen];
  if (solve(i + 1, j, curLen) == ret) {
    return printPath(i + 1, j, curLen);
  }
  if (solve(i, j + 1, curLen) == ret) {
    return printPath(i, j + 1, curLen);
  }
  cout << s[i];
  if (s[i] == ss[j]) {
    updateLen(s[i], curLen);
    if (curLen < (int)virus.size()) {
      if (solve(i + 1, j + 1, curLen) + 1 == ret) {
        return printPath(i + 1, j + 1, curLen);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> ss >> virus;
  getFailure();
  memset(memo, -1, sizeof memo);
  if (solve(0, 0, 0)) {
    printPath(0, 0, 0);
  } else
    cout << 0;
}
