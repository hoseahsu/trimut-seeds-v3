#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
string s[maxn];
int nxt[30];
int pre[30];
bool vis[30];
bool exist[30];
void dfs(int x) {
  vis[x] = true;
  cout << (char)('a' + x - 1);
  if (nxt[x] == 0) {
    return;
  }
  dfs(nxt[x]);
}
bool flag = true;
void dfs2(int x) {
  if (vis[x] || flag == false) {
    flag = false;
    return;
  }
  vis[x] = true;
  if (nxt[x] == 0) {
    return;
  }
  dfs2(nxt[x]);
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (size_t j = 0; j < s[i].length(); j++) {
      exist[s[i][j] - 'a' + 1] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    for (size_t j = 0; j < s[i].length() - 1; j++) {
      if (nxt[s[i][j] - 'a' + 1] == 0 && pre[s[i][j + 1] - 'a' + 1] == 0) {
        nxt[s[i][j] - 'a' + 1] = s[i][j + 1] - 'a' + 1;
        pre[s[i][j + 1] - 'a' + 1] = s[i][j] - 'a' + 1;
      } else if (nxt[s[i][j] - 'a' + 1] == s[i][j + 1] - 'a' + 1 &&
                 pre[s[i][j + 1] - 'a' + 1] == s[i][j] - 'a' + 1) {
        continue;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= 26; i++) {
    if (exist[i] && !vis[i] && pre[i] == 0) {
      cnt++;
      dfs2(i);
    }
  }
  for (int i = 1; i <= 26; i++) {
    if (exist[i] && !vis[i]) {
      flag = false;
      break;
    }
  }
  if (flag == false || cnt == 0) {
    cout << "NO";
    return 0;
  }
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= 26; i++) {
    if (exist[i] && !vis[i] && pre[i] == 0) {
      dfs(i);
    }
  }
  return 0;
}
