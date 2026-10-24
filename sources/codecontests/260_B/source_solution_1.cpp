#include <bits/stdc++.h>
using namespace std;
int occ[40][20][10];
bool isNumber(char c) { return (48 <= int(c) && int(c) <= 57); }
int sti(string s) {
  int ans = 0;
  for (int i = 0; i < s.length(); i++) ans = ans * 10 + int(s[i]) - 48;
  return ans;
}
int date[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isDate(string s, int &d, int &m, int &y) {
  if (isNumber(s[0]) && isNumber(s[1]) && s[2] == '-' && isNumber(s[3]) &&
      isNumber(s[4]) && s[5] == '-' && s[6] == '2' && s[7] == '0' &&
      s[8] == '1' && isNumber(s[9])) {
    d = sti(s.substr(0, 2));
    m = sti(s.substr(3, 2));
    y = sti(s.substr(6, 4));
    if (2013 <= y && y <= 2015 && 1 <= m && m <= 12 && 1 <= d && d <= date[m])
      return true;
  }
  return false;
}
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length() - 9; i++) {
    int d, m, y;
    if (isDate(s.substr(i, 10), d, m, y)) {
      occ[d][m][y - 2013]++;
    }
  }
  int Max = 0, yans, dans, mans;
  for (int y = 0; y <= 2; y++)
    for (int m = 1; m <= 12; m++)
      for (int d = 1; d <= date[m]; d++)
        if (occ[d][m][y] > Max) {
          Max = occ[d][m][y];
          yans = y;
          mans = m;
          dans = d;
        }
  if (dans < 10) cout << 0;
  cout << dans << "-";
  if (mans < 10) cout << 0;
  cout << mans << "-";
  cout << yans + 2013 << endl;
}
