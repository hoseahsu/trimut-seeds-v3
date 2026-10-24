#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  int f = 1;
  char t = getchar();
  while (t < '0' || t > '9') {
    if (t == '-') f = -1;
    t = getchar();
  }
  x = 0;
  while (t >= '0' && t <= '9') {
    x = x * 10 + t - '0';
    t = getchar();
  }
  x *= f;
}
template <typename T>
inline void Write(T x) {
  static int output[20];
  int top = 0;
  if (x < 0) putchar('-'), x = -x;
  do {
    output[++top] = x % 10;
    x /= 10;
  } while (x > 0);
  while (top > 0) putchar('0' + output[top--]);
  putchar('\n');
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int maxn = 5005;
const int inf = 0x3f3f3f3f;
int n;
int m;
int fst[maxn];
int v[maxn], nxt[maxn];
int e_cn;
int dis[maxn][maxn];
pair<int, int> in[maxn][5];
pair<int, int> out[maxn][5];
void addedge(int x, int y) {
  e_cn++, v[e_cn] = y;
  nxt[e_cn] = fst[x], fst[x] = e_cn;
}
void input() {
  Read(n);
  Read(m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    Read(x);
    Read(y);
    addedge(x, y);
  }
}
void prepare() {
  static queue<int> q;
  static bool vis[maxn];
  memset(dis, inf, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    int *d = dis[i];
    d[i] = 0;
    vis[i] = true;
    q.push(i);
    while (!q.empty()) {
      int cn = q.front();
      q.pop();
      vis[cn] = false;
      for (int i = fst[cn]; i; i = nxt[i]) {
        if (d[v[i]] > d[cn] + 1) {
          d[v[i]] = d[cn] + 1;
          if (!vis[v[i]]) {
            vis[v[i]] = true;
            q.push(v[i]);
          }
        }
      }
    }
  }
  static int stamp[maxn];
  for (int i = 1; i <= n; i++) {
    static int counter;
    counter++;
    for (int k = 1; k <= 4; k++) {
      pair<int, int> mx = make_pair(-inf, 0);
      for (int j = 1; j <= n; j++) {
        if (stamp[j] == counter || dis[j][i] == inf || j == i) continue;
        chkmax(mx, make_pair(dis[j][i], j));
      }
      in[i][k] = mx;
      stamp[mx.second] = counter;
    }
    counter++;
    for (int k = 1; k <= 4; k++) {
      pair<int, int> mx = make_pair(-inf, 0);
      for (int j = 1; j <= n; j++) {
        if (stamp[j] == counter || dis[i][j] == inf || j == i) continue;
        chkmax(mx, make_pair(dis[i][j], j));
      }
      out[i][k] = mx;
      stamp[mx.second] = counter;
    }
  }
}
void solve() {
  static bool vis[maxn];
  int ans = 0;
  int a, b, c, d;
  for (int i = 1; i <= n; i++) {
    vis[i] = true;
    for (int j = 1; j <= n; j++) {
      if (i != j && dis[i][j] < inf) {
        vis[j] = true;
        for (int k = 1; k <= 4; k++) {
          if (!vis[in[i][k].second]) {
            int fr = in[i][k].second;
            vis[fr] = true;
            for (int p = 1; p <= 4; p++) {
              if (!vis[out[j][p].second]) {
                int to = out[j][p].second;
                vis[to] = true;
                if (dis[fr][i] < inf && dis[j][to] < inf) {
                  if (dis[fr][i] + dis[i][j] + dis[j][to] > ans) {
                    ans = dis[fr][i] + dis[i][j] + dis[j][to];
                    a = fr, b = i, c = j, d = to;
                  }
                }
                vis[to] = false;
                break;
              }
            }
            vis[fr] = false;
            break;
          }
        }
        for (int k = 1; k <= 4; k++) {
          if (!vis[out[j][k].second]) {
            int to = out[j][k].second;
            vis[to] = true;
            for (int p = 1; p <= 4; p++) {
              if (!vis[in[i][p].second]) {
                int fr = in[i][p].second;
                vis[fr] = true;
                if (dis[fr][i] < inf && dis[j][to] < inf) {
                  if (dis[fr][i] + dis[i][j] + dis[j][to] > ans) {
                    ans = dis[fr][i] + dis[i][j] + dis[j][to];
                    a = fr, b = i, c = j, d = to;
                  }
                }
                vis[fr] = false;
                break;
              }
            }
            vis[to] = false;
            break;
          }
        }
        vis[j] = false;
      }
    }
    vis[i] = false;
  }
  printf("%d %d %d %d\n", a, b, c, d);
}
int main() {
  input();
  prepare();
  solve();
  return 0;
}
