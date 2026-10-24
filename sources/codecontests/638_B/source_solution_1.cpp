#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, n, m, a_end, b_end, finish = 0, i_a, i_b;
  bool vis[26] = {0}, was[100] = {0};
  vector<vector<int> > v;
  string s[100], tmp, ready = "";
  cin >> n;
  v.resize(100);
  for (i = 0; i < n; i++) {
    cin >> s[i];
    v[i].resize(26);
    for (j = 0; j < 26; j++) {
      c = s[i].find(char(j + 'a'));
      v[i][j] = c;
    }
  }
  ready = s[0];
  was[0] = true;
  finish = n;
  while (finish > 1) {
    for (i = 0; i < finish; i++) {
      for (j = i + 1; j < finish; j++) {
        for (int k = 0; k < 26; k++) {
          string tmp1 = s[i];
          string tmp2 = s[j];
          a = tmp1.find(char('a' + k));
          b = tmp2.find(char('a' + k));
          if (a != -1 && b != -1) {
            a_end = tmp1.size() - a;
            b_end = tmp2.size() - b;
            ready = tmp1;
            if (a < b) {
              ready = tmp2.substr(0, b - a) + ready;
            }
            if (a_end < b_end) {
              ready +=
                  tmp2.substr(tmp2.size() - (b_end - a_end), b_end - a_end);
            }
            s[i] = ready;
            swap(s[j], s[finish - 1]);
            goto step;
          }
        }
      }
    }
    for (i = 1; i < finish; i++) {
      s[0] += s[i];
    }
  step:
    finish--;
  }
  cout << s[0] << endl;
  return 0;
}
