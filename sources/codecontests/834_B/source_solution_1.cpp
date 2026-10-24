#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, n, m, cnt = 0, ar[2][26];
  for (i = 0; i < 26; i++) {
    ar[0][i] = 10000000;
    ar[1][i] = -1;
  }
  map<char, int> ma;
  cin >> n >> k;
  string second;
  cin >> second;
  n = second.size();
  for (i = 0; i < n; i++) {
    ar[0][second[i] - 'A'] = min(ar[0][second[i] - 'A'], i);
    ar[1][second[i] - 'A'] = max(ar[1][second[i] - 'A'], i);
  }
  int fl = 1;
  for (i = 0; i < n && fl; i++) {
    if (ar[0][second[i] - 'A'] == i) {
      if (k)
        k--;
      else
        fl = 0;
    }
    if (ar[1][second[i] - 'A'] == i) k++;
  }
  if (fl)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
