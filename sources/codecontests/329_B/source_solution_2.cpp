#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct point {
  int visited;
  int moster;
  int type;
  int dist;
  int x, y;

 public:
  point() {
    this->visited = false;
    this->moster = 0;
    this->type = 2;
    this->dist = 0x7fffffff;
  }
};
point p[1000][1000];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  point *start, *end;
  for (int y = 0; y < n; y++) {
    char s[1024];
    scanf("%s", s);
    for (int x = 0; x < m; x++) {
      p[y][x].x = x;
      p[y][x].y = y;
      if (s[x] == 'T')
        p[y][x].type = 1;
      else if (s[x] == 'S')
        start = &p[y][x];
      else if (s[x] == 'E')
        end = &p[y][x];
      else
        p[y][x].moster = (int)(s[x] - '0');
    }
  }
  queue<point *> q;
  end->visited = true;
  end->dist = 0;
  q.push(end);
  while (!q.empty()) {
    point *t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = t->x + dx[i];
      int y = t->y + dy[i];
      if (y >= n || x >= m || y < 0 || x < 0) continue;
      if (p[y][x].visited || p[y][x].type == 1) continue;
      p[y][x].visited = true;
      p[y][x].dist = t->dist + 1;
      q.push(&p[y][x]);
    }
  }
  int cnt = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (p[y][x].moster > 0 && p[y][x].dist <= start->dist)
        cnt += p[y][x].moster;
  printf("%d\n", cnt);
  return 0;
}
