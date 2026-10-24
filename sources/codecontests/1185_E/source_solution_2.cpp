#include <bits/stdc++.h>
using namespace std;
vector<int> modeVec;
vector<pair<int, int>> vec[30];
vector<pair<pair<int, int>, pair<int, int>>> result;
int t, n, m, Last, rflag;
char zone[2005][2005], tzone[2005][2005];
int arrX[5] = {1, 0};
int arrY[5] = {0, 1};
void init() {
  rflag = 0;
  Last = -1;
  modeVec.clear();
  result.clear();
  for (int i = 0; i < 26; i++) {
    vec[i].clear();
  }
}
int main() {
  scanf("%d", &t);
  for (int tc = 0; tc < t; tc++) {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf(" %c", &zone[i][j]);
        if (zone[i][j] != '.') {
          vec[zone[i][j] - 'a'].push_back({j, i});
          Last = max(Last, zone[i][j] - 'a');
        }
      }
    }
    for (int i = 0; i <= Last; i++) {
      int count = 0, flag = 0;
      for (int j = 0; j < vec[i].size(); j++) {
        if (vec[i][0].first == vec[i][j].first) count++;
      }
      if (count == vec[i].size()) {
        modeVec.push_back(1);
        flag = 1;
        continue;
      }
      count = 0;
      for (int j = 0; j < vec[i].size(); j++) {
        if (vec[i][0].second == vec[i][j].second) count++;
      }
      if (count == vec[i].size()) {
        modeVec.push_back(0);
        flag = 1;
      }
      if (flag == 0) rflag = 1;
    }
    if (rflag == 1) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i <= Last; i++) {
      int tx, ty, mode, ex, ey;
      if (vec[i].size() == 0) {
        result.push_back(
            {{vec[Last].begin()->first, vec[Last].begin()->second},
             {vec[Last].rbegin()->first, vec[Last].rbegin()->second}});
        continue;
      }
      tx = vec[i][0].first;
      ty = vec[i][0].second;
      mode = modeVec[i];
      ex = vec[i].rbegin()->first;
      ey = vec[i].rbegin()->second;
      while (tx <= ex && ty <= ey) {
        if (zone[ty][tx] == '.') rflag = 1;
        tzone[ty][tx] = 'a' + i;
        tx += arrX[mode];
        ty += arrY[mode];
      }
      result.push_back({{vec[i][0].first, vec[i][0].second}, {ex, ey}});
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (zone[i][j] != '.' && zone[i][j] != tzone[i][j]) rflag = 1;
      }
    }
    if (rflag == 1) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    printf("%d\n", result.size());
    for (int i = 0; i < result.size(); i++) {
      printf("%d %d %d %d\n", result[i].first.second + 1,
             result[i].first.first + 1, result[i].second.second + 1,
             result[i].second.first + 1);
    }
  }
}
