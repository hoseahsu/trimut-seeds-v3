#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  bool atm = false;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < m && s[i] == t[j]) ++j;
    if (j == m) atm = true;
  }
  for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
  for (int i = 0; i < m; ++i) cnt[t[i] - 'a']--;
  bool arr = true;
  bool nt = true;
  for (int i = 0; i < 26; ++i) {
    arr &= cnt[i] == 0;
    nt &= cnt[i] >= 0;
  }
  if (atm)
    cout << "automaton" << endl;
  else if (arr)
    cout << "array" << endl;
  else if (nt)
    cout << "both" << endl;
  else
    cout << "need tree" << endl;
}
