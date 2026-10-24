#include <bits/stdc++.h>
using namespace std;
int r, c, N;
pair<int, int> link[3010][6010];
int go[8][2] = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
pair<int, int> Find(pair<int, int> k) {
  if (link[k.first][k.second] == k) return link[k.first][k.second];
  link[k.first][k.second] = Find(link[k.first][k.second]);
  return link[k.first][k.second];
}
int main() {
  int Ans = 0;
  cin >> r >> c >> N;
  if (c == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= r; i++)
    for (int j = c << 1; j >= 1; j--) link[i][j] = pair<int, int>(-1, -1);
  for (int i = 1; i <= N; i++) {
    int X, Y;
    scanf("%d%d", &X, &Y);
    pair<int, int> t[17];
    for (int j = 1; j <= 16; j++) t[j].first = -1, t[j].second = -1;
    int cnt = 0;
    for (int j = 0; j <= 1; j++) {
      Y += j * c;
      for (int p = 0; p < 8; p++) {
        cnt++;
        int xx = X + go[p][0], yy = Y + go[p][1];
        if (xx < 1 || xx > r) continue;
        if (yy < 1) yy += c << 1;
        if (yy > (c << 1)) yy -= c << 1;
        if (link[xx][yy] == pair<int, int>(-1, -1)) continue;
        t[cnt] = Find(pair<int, int>(xx, yy));
      }
    }
    for (int p = 1; p <= 8; p++) {
      if (t[p] == pair<int, int>(-1, -1)) continue;
      for (int q = 9; q <= 16; q++) {
        if (t[q] == pair<int, int>(-1, -1)) continue;
        if (t[p] == t[q]) goto Break;
      }
    }
    Ans++;
    Y -= c;
    link[X][Y] = pair<int, int>(X, Y);
    for (int j = 1; j <= 8; j++) {
      if (t[j] == pair<int, int>(-1, -1)) continue;
      link[t[j].first][t[j].second] = link[X][Y];
    }
    Y += c;
    link[X][Y] = pair<int, int>(X, Y);
    for (int j = 9; j <= 16; j++) {
      if (t[j] == pair<int, int>(-1, -1)) continue;
      link[t[j].first][t[j].second] = link[X][Y];
    }
  Break:;
  }
  cout << Ans << endl;
  return 0;
}
