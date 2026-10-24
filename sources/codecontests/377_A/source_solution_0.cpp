#include <bits/stdc++.h>
using namespace std;
const int M = 505;
struct Node {
  int x, y;
};
int cnt = 0, sum = 0;
int k, n, m;
bool book[M][M];
char mapp[M][M];
int mv[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
void bfs(int x, int y) {
  queue<Node> q;
  int xt, yt;
  Node tmp, next;
  tmp.x = x;
  tmp.y = y;
  book[x][y] = true;
  cnt = 1;
  q.push(tmp);
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      xt = tmp.x + mv[i][0];
      yt = tmp.y + mv[i][1];
      if (xt < 1 || xt > n || yt < 1 || yt > m) continue;
      if (!book[xt][yt] && mapp[xt][yt] == '.') {
        if (cnt == sum - k) return;
        book[xt][yt] = true;
        cnt++;
        next.x = xt;
        next.y = yt;
        q.push(next);
      }
    }
  }
}
int main() {
  int x = -1, y = -1;
  scanf("%d%d%d", &n, &m, &k);
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%c", &mapp[i][j]);
      if (mapp[i][j] == '.') {
        sum++;
        x = i;
        y = j;
      }
    }
    getchar();
  }
  if (x != -1 && y != -1) {
    bfs(x, y);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mapp[i][j] == '.' && book[i][j])
          printf(".");
        else if (mapp[i][j] == '.')
          printf("X");
        else
          printf("#");
      }
      printf("\n");
    }
  } else
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%c", mapp[i][j]);
      printf("\n");
    }
  return 0;
}
