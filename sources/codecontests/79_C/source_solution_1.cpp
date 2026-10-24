#include <bits/stdc++.h>
using namespace std;
int len[111111];
set<int> nxt;
string s;
string bad[11];
int n;
int main() {
  cin >> s;
  cin >> n;
  for (int(i) = 0; (i) < ((int)s.size()); ++(i)) len[i] = 1000000000;
  for (int(i) = 0; (i) < (n); ++(i)) cin >> bad[i];
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < ((int)s.size() - (int)bad[i].size() + 1); ++(j)) {
      int pos = 0;
      while (pos < (int)bad[i].size() && s[j + pos] == bad[i][pos]) ++pos;
      if (pos == (int)bad[i].size()) {
        len[j] = min(len[j], pos);
        nxt.insert(j);
      }
    }
  len[(int)s.size() + 1] = 0;
  nxt.insert((int)s.size() + 1);
  int mx = 0;
  int ps = 0;
  for (int(i) = 0; (i) < ((int)s.size()); ++(i)) {
    int up = *nxt.lower_bound(i);
    int fin = up + len[up];
    for (int pos = up + 1; pos < fin && pos < (int)s.size(); ++pos)
      fin = min(fin, pos + len[pos]);
    if (fin - i - 1 > mx) {
      mx = fin - i - 1;
      ps = i;
    }
  }
  cout << mx << " " << ps << endl;
}
