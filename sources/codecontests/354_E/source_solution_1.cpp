#include <bits/stdc++.h>
using namespace std;
int D[3] = {0, 4, 7};
string S;
vector<int> way[50];
int dp[20][10];
int nxt[20][10];
int getdp(int x, int y) {
  int &ref = dp[x][y];
  if (ref != -1) {
    return ref;
  }
  if (x == S.size()) {
    return ref = (y == 0);
  }
  int mod10 = ((S[x] - '0') - y + 20) % 10;
  for (int i = mod10; i < 50; i += 10) {
    if (way[i].empty()) {
      continue;
    }
    if (getdp(x + 1, (i + y) / 10)) {
      nxt[x][y] = i;
      return ref = 1;
    }
  }
  return ref = 0;
}
void go() {
  cin >> S;
  reverse((S).begin(), (S).end());
  memset((dp), (-1), sizeof(dp));
  if (getdp(0, 0)) {
    string ans[6] = {"", "", "", "", "", ""};
    int s = 0;
    for (int i = 0; i < S.size(); i++) {
      int nx = nxt[i][s];
      for (int j = 0; j < 6; j++) {
        ans[j] += char('0' + way[nx][j]);
      }
      s = (s + nx) / 10;
    }
    for (string s : ans) {
      reverse((s).begin(), (s).end());
      stringstream ss(s);
      long long x;
      ss >> x;
      cout << x << ' ';
    }
    cout << '\n';
  } else {
    cout << "-1\n";
  }
}
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }
  ios::sync_with_stdio(false);
  for (int i1 : D) {
    for (int i2 : D) {
      for (int i3 : D) {
        for (int i4 : D) {
          for (int i5 : D) {
            for (int i6 : D) {
              way[i1 + i2 + i3 + i4 + i5 + i6] = {i1, i2, i3, i4, i5, i6};
            }
          }
        }
      }
    }
  }
  int nq;
  for (cin >> nq; nq--;) {
    go();
  }
}
