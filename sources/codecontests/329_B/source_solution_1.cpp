#include <bits/stdc++.h>
using namespace std;
typedef struct point {
  int x, y;
} point;
int graph[1010][1010];
int known[1010][1010];
int dist[1010][1010];
int n, m;
vector<point> enemies;
vector<int> num_enemies;
point s, e;
void bfs(point start);
int main() {
  int i, j;
  n = ({
    int x;
    scanf("%d", &x);
    x;
  });
  m = ({
    int x;
    scanf("%d", &x);
    x;
  });
  char inp[1010];
  point temp;
  for (i = 0; i <= m + 1; i++) {
    graph[0][i] = 0;
    graph[n + 1][i] = 0;
  }
  for (i = 0; i <= n + 1; i++) {
    graph[i][0] = 0;
    graph[i][m + 1] = 0;
  }
  for (i = 1; i <= n; i++) {
    scanf("%s", inp);
    for (j = 0; j < m; j++) {
      if (inp[j] == 'T') {
        graph[i][j + 1] = 0;
      } else
        graph[i][j + 1] = 1;
      if (inp[j] == 'S') {
        s.x = i;
        s.y = j + 1;
      }
      if (inp[j] == 'E') {
        e.x = i;
        e.y = j + 1;
      }
      if (inp[j] >= '0' && inp[j] <= '9') {
        temp.x = i;
        temp.y = j + 1;
        enemies.push_back(temp);
        num_enemies.push_back(inp[j] - '0');
      }
    }
  }
  bfs(e);
  int x = enemies.size();
  int minn = dist[s.x][s.y];
  int ans = 0;
  for (i = 0; i < x; i++) {
    if (dist[enemies[i].x][enemies[i].y] <= minn) ans += num_enemies[i];
  }
  cout << ans << endl;
  return 0;
}
void bfs(point start) {
  int i, j;
  for (i = 0; i < n + 1; i++) {
    for (j = 0; j < m + 1; j++) {
      known[i][j] = 0;
      dist[i][j] = 1000000007;
    }
  }
  queue<point> q;
  q.push(start);
  known[start.x][start.y] = 1;
  dist[start.x][start.y] = 0;
  point current;
  point next;
  while (!q.empty()) {
    current = q.front();
    q.pop();
    next.x = current.x - 1;
    next.y = current.y;
    if (dist[next.x][next.y] > dist[current.x][current.y] + 1) {
      dist[next.x][next.y] = dist[current.x][current.y] + 1;
    }
    if (graph[next.x][next.y] == 1) {
      if (known[next.x][next.y] == 0) {
        known[next.x][next.y] = 1;
        q.push(next);
      }
    }
    next.x = current.x;
    next.y = current.y + 1;
    if (dist[next.x][next.y] > dist[current.x][current.y] + 1) {
      dist[next.x][next.y] = dist[current.x][current.y] + 1;
    }
    if (graph[next.x][next.y] == 1) {
      if (known[next.x][next.y] == 0) {
        known[next.x][next.y] = 1;
        q.push(next);
      }
    }
    next.x = current.x + 1;
    next.y = current.y;
    if (dist[next.x][next.y] > dist[current.x][current.y] + 1) {
      dist[next.x][next.y] = dist[current.x][current.y] + 1;
    }
    if (graph[next.x][next.y] == 1) {
      if (known[next.x][next.y] == 0) {
        known[next.x][next.y] = 1;
        q.push(next);
      }
    }
    next.x = current.x;
    next.y = current.y - 1;
    if (dist[next.x][next.y] > dist[current.x][current.y] + 1) {
      dist[next.x][next.y] = dist[current.x][current.y] + 1;
    }
    if (graph[next.x][next.y] == 1) {
      if (known[next.x][next.y] == 0) {
        known[next.x][next.y] = 1;
        q.push(next);
      }
    }
  }
}
