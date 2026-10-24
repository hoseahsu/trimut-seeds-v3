#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void chkmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
inline void chkmax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
inline T add(T x, T y) {
  return (x + y) % 1000000007;
}
template <typename T>
inline T mul(T x, T y) {
  return 1LL * x * y % 1000000007;
}
template <typename T>
inline T qp(T x, T n) {
  T ans = 1;
  do {
    if (n & 1) ans = mul(ans, x);
    x = mul(x, x);
  } while (n >>= 1);
  return ans;
}
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
inline long long read() {
  long long x = 0;
  int f = 1,
      c = (++pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos);
  for (; !isdigit(c);
       c = (++pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos))
    if (c == '-') f = -f;
  for (; isdigit(c);
       c = (++pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos))
    x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
int n, m;
int k;
int a[105][105];
int dis[205][205];
int prvv[205][205];
int dp[205][1 << 7];
pair<pair<int, int>, pair<pair<int, int>, pair<int, int> > > prv[205][1 << 7];
int xx[15], yy[15];
char anss[105][105];
void print_path(int sx, int sy, int ex, int ey) {
  while (ex != sx || ey != sy) {
    anss[ex][ey] = 'X';
    int xxx = prvv[sx * m + sy][ex * m + ey];
    ex = xxx / m, ey = xxx % m;
  }
  anss[ex][ey] = 'X';
}
void printans(int xy, int msk) {
  int x = xy / m, y = xy % m;
  if (__builtin_popcount(msk) == 1) {
    int lst = __builtin_ctz(msk);
    print_path(x, y, xx[lst], yy[lst]);
    return;
  }
  print_path(prv[xy][msk].second.first.first, prv[xy][msk].second.first.second,
             prv[xy][msk].second.second.first,
             prv[xy][msk].second.second.second);
  printans(
      prv[xy][msk].second.first.first * m + prv[xy][msk].second.first.second,
      prv[xy][msk].first.first);
  printans(
      prv[xy][msk].second.second.first * m + prv[xy][msk].second.second.second,
      prv[xy][msk].first.second);
}
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int main() {
  n = read(), m = read(), k = read();
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) a[i][j] = read();
  for (int i = 0; i < (int)(k); ++i) xx[i] = read() - 1, yy[i] = read() - 1;
  memset(dis, 0x3f, sizeof dis);
  for (int sx = 0; sx < (int)(n); ++sx)
    for (int sy = 0; sy < (int)(m); ++sy) {
      priority_queue<pair<int, pair<int, int> >,
                     vector<pair<int, pair<int, int> > >,
                     greater<pair<int, pair<int, int> > > >
          pq;
      pq.push(make_pair(a[sx][sy], make_pair(sx, sy)));
      dis[sx * m + sy][sx * m + sy] = a[sx][sy];
      while (!pq.empty()) {
        pair<int, pair<int, int> > p = pq.top();
        pq.pop();
        int x = p.second.first, y = p.second.second;
        for (int i = 0; i < (int)(4); ++i) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (dis[sx * m + sy][nx * m + ny] >
              dis[sx * m + sy][x * m + y] + a[nx][ny]) {
            dis[sx * m + sy][nx * m + ny] =
                dis[sx * m + sy][x * m + y] + a[nx][ny];
            prvv[sx * m + sy][nx * m + ny] = x * m + y;
            pq.push(
                make_pair(dis[sx * m + sy][nx * m + ny], make_pair(nx, ny)));
          }
        }
      }
    }
  memset(dp, 0x3f, sizeof dp);
  for (int ij = 0; ij < (int)(n * m); ++ij)
    for (int l = 0; l < (int)(k); ++l)
      dp[ij][1 << l] = dis[ij][xx[l] * m + yy[l]];
  for (int msk = 0; msk < (int)(1 << k); ++msk)
    if (__builtin_popcount(msk) > 1) {
      for (int i = 0; i < (int)(n * m); ++i) {
        for (int msk1 = (msk - 1) & msk; msk1; msk1 = (msk1 - 1) & msk) {
          int msk2 = msk ^ msk1;
          for (int j = 0; j < (int)(n * m); ++j) {
            if (dp[i][msk] > dp[i][msk1] + dp[j][msk2] + dis[i][j] -
                                 a[i / m][i % m] - a[j / m][j % m]) {
              dp[i][msk] = dp[i][msk1] + dp[j][msk2] + dis[i][j] -
                           a[i / m][i % m] - a[j / m][j % m];
              prv[i][msk] = make_pair(
                  make_pair(msk1, msk2),
                  make_pair(make_pair(i / m, i % m), make_pair(j / m, j % m)));
            }
            if (dp[i][msk] > dp[j][msk1] + dp[i][msk2] + dis[i][j] -
                                 a[i / m][i % m] - a[j / m][j % m]) {
              dp[i][msk] = dp[j][msk1] + dp[i][msk2] + dis[i][j] -
                           a[i / m][i % m] - a[j / m][j % m];
              prv[i][msk] = make_pair(
                  make_pair(msk1, msk2),
                  make_pair(make_pair(j / m, j % m), make_pair(i / m, i % m)));
            }
          }
        }
      }
    }
  int ans = 1e9;
  int ansxy;
  for (int i = 0; i < (int)(n * m); ++i)
    if (dp[i][(1 << k) - 1] < ans) ans = dp[i][(1 << k) - 1], ansxy = i;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) anss[i][j] = '.';
  printf("%d\n", ans);
  printans(ansxy, (1 << k) - 1);
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) {
      printf("%c", anss[i][j]);
      if (j + 1 == m) puts("");
    }
  return 0;
}
