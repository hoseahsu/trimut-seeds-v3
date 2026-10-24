#include <bits/stdc++.h>
using namespace std;
int n;
int nxt[26];
int deg[26];
int was[26];
int main() {
  cin >> n;
  for (int i = 0; i < 26; ++i) nxt[i] = -1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j < s.size(); ++j) {
      nxt[s[j - 1] - 'a'] = s[j] - 'a';
      deg[s[j] - 'a']++;
    }
    for (auto j : s) was[j - 'a'] = 1;
  }
  for (int i = 0; i < 26; ++i) {
    if (!was[i]) continue;
    if (deg[i] == 0) {
      int cur = i;
      while (cur >= 0) {
        cout << (char)(cur + 'a');
        cur = nxt[cur];
      }
    }
  }
  cout << endl;
  return 0;
}
