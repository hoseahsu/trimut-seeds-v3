#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 2 * 1000 * 1000 * 1000;
const double EPS = 1e-9;
bool exist[30];
int side[8][3];
int dis(int id1, int id2, int c) { return side[id1][c] - side[id2][c]; }
long long mul(int a) { return (long long)a * (long long)a; }
long long getDis(int id1, int id2) {
  return mul(dis(id1, id2, 0)) + mul(dis(id1, id2, 1)) + mul(dis(id1, id2, 2));
}
int OK(int idx, long long number) {
  int mini[3] = {};
  for (int i = 0; i < 8; i++) {
    if (i == idx) {
      continue;
    }
    long long curDis = getDis(idx, i);
    if (curDis < number) {
      return -1;
    }
    if (curDis == number) {
      mini[0]++;
    } else {
      if (curDis == (long long)2 * number) {
        mini[1]++;
      } else {
        if (curDis == (long long)3 * number) {
          mini[2]++;
        } else {
          return -1;
        }
      }
    }
  }
  if (mini[0] != 3 || mini[1] != 3 || mini[2] != 1) {
    return -1;
  }
  return 1;
}
bool calcAns(int i) {
  if (i == 8) {
    long long mini = (1ll) << 60;
    for (int i = 1; i < 8; i++) {
      mini = min(mini, getDis(0, i));
    }
    if (mini == 0) {
      return false;
    }
    bool reach = true;
    for (int i = 0; i < 8; i++) {
      int cur = OK(i, mini);
      if (cur == -1) {
        reach = false;
        break;
      }
    }
    return reach;
  }
  do {
    if (calcAns(i + 1)) {
      return true;
    }
  } while (next_permutation(side[i], side[i] + 3));
  return false;
}
int main() {
  for (int i = 0; i < 8; i++) {
    cin >> side[i][0] >> side[i][1] >> side[i][2];
    sort(side[i], side[i] + 3);
  }
  bool succes = calcAns(0);
  if (succes) {
    cout << "YES" << endl;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 3; j++) {
        cout << side[i][j] << ' ';
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
