#include <bits/stdc++.h>
using namespace std;
string s, cur;
int cnt[26];
char grid[2][13];
void construct(int x) {
  int row = 0, col = x;
  for (int i = 0; i <= (26) - 1; i++) {
    grid[row][col] = cur[i];
    if (!row && col == 12)
      row = 1;
    else if (row == 1 && !col)
      row = 0;
    else if (row)
      col--;
    else
      col++;
  }
}
bool ok(int x) {
  int row = 0;
  int col = x;
  int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
  for (int i = 1; i <= 26; i++) {
    bool flag = false;
    for (int dd = 0; dd <= (8) - 1; dd++) {
      int newr = row + dr[dd];
      int newc = col + dc[dd];
      if (newr >= 0 && newc >= 0 && newr < 2 && newc < 13) {
        if (grid[newr][newc] == s[i]) {
          row = newr;
          col = newc;
          flag = true;
          break;
        }
      }
    }
    if (!flag) return false;
  }
  return true;
}
void f() {
  for (int i = 0; i <= (2) - 1; i++) {
    for (int j = 0; j <= (13) - 1; j++) cout << grid[i][j];
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i <= (26) - 1; i++)
    if (s[i] == s[i + 1]) {
      cout << "Impossible";
      return 0;
    }
  cur = "";
  for (char c : s) {
    if (!cnt[c - 'A']) {
      cnt[c - 'A'] = 1;
      cur += c;
    }
  }
  for (int i = 0; i <= (13) - 1; i++) {
    construct(i);
    if (ok(i)) {
      f();
      return 0;
    }
  }
  cout << "Impossible";
}
