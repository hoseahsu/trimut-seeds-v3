#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, vector<vector<char>> &v) {
  if (y <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x][y + i] == 'x') {
        cnt0++;
      } else if (v[x][y + i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y] == 'x') {
        cnt0++;
      } else if (v[x + i][y] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1 && y <= 1) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y + i] == 'x') {
        cnt0++;
      } else if (v[x + i][y + i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  if (x <= 1 && y >= 2) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (v[x + i][y - i] == 'x') {
        cnt0++;
      } else if (v[x + i][y - i] == 'o') {
        cnt1++;
      }
    }
    if (cnt0 == 2 && cnt1 == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  vector<vector<char>> v(4, vector<char>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check(i, j, v)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
