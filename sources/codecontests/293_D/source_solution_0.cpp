#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  Point operator+(Point rhs) { return Point(x + rhs.x, y + rhs.y); }
  Point operator-(Point rhs) { return Point(x - rhs.x, y - rhs.y); }
  long long Dot(Point rhs) { return 1LL * x * rhs.x + 1LL * y * rhs.y; }
  long long Crs(Point rhs) { return 1LL * x * rhs.y - 1LL * y * rhs.x; }
};
bool operator<(Point lhs, Point rhs) {
  return (lhs.x == rhs.x) ? (lhs.y < rhs.y) : (lhs.x < rhs.x);
}
const int MAXN = 100010;
int N;
Point p[MAXN];
vector<Point> H[2];
int pcx[2333333], pcy[2333333];
int *cx = pcx + 1233333, *cy = pcy + 1233333;
long long cip;
double Stat(int* e, int Min, int Max) {
  double ret = 0;
  double Count = 0, sumPlain = 0, sumSquare = 0;
  int i;
  for (i = Min; i <= Max; i++) {
    ret += e[i] * (Count * i * i + sumSquare - 2.0 * i * sumPlain);
    Count += e[i];
    sumPlain += e[i] * 1.0 * i;
    sumSquare += e[i] * 1.0 * i * i;
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  int i;
  for (i = 1; i <= N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = Point(x, y);
  }
  sort(p + 1, p + N + 1);
  int ml = 1;
  while ((ml < N) && (p[ml + 1].x == p[1].x)) ml++;
  H[0].clear();
  H[1].clear();
  H[0].push_back(p[1]);
  H[1].push_back(p[ml]);
  for (i = ml + 1; i <= N; i++) {
    while ((H[0].size() > 1) &&
           ((H[0].back() - H[0][H[0].size() - 2]).Crs(p[i] - H[0].back()) <= 0))
      H[0].pop_back();
    while ((H[1].size() > 1) &&
           ((H[1].back() - H[1][H[1].size() - 2]).Crs(p[i] - H[1].back()) >= 0))
      H[1].pop_back();
    H[0].push_back(p[i]);
    H[1].push_back(p[i]);
  }
  while ((H[0].size() > 1) && (H[0].back().x == H[0][H[0].size() - 2].x))
    H[0].pop_back();
  vector<Point>::iterator lit = H[0].begin(), rit = H[1].begin();
  int minX = p[1].x, maxX = p[N].x, minY = p[1].y, maxY = p[1].y;
  for (i = 2; i <= N; i++) {
    minY = min(minY, p[i].y);
    maxY = max(maxY, p[i].y);
  }
  for (i = minY; i <= maxY; i++) cy[i] = 0;
  cx[maxX] = H[1].back().y - H[0].back().y + 1;
  cy[H[1].back().y + 1]--;
  cy[H[0].back().y]++;
  for (i = minX; i <= maxX - 1; i++) {
    if ((lit + 1)->x <= i) lit++;
    if ((rit + 1)->x <= i) rit++;
    int ly = ceil(double((lit + 1)->y - lit->y) / ((lit + 1)->x - lit->x) *
                      (i - lit->x) +
                  lit->y - 1e-9);
    int ry = floor(double((rit + 1)->y - rit->y) / ((rit + 1)->x - rit->x) *
                       (i - rit->x) +
                   rit->y + 1e-9);
    cx[i] = ry - ly + 1;
    cy[ry + 1]--;
    cy[ly]++;
  }
  for (i = minY + 1; i <= maxY; i++) cy[i] += cy[i - 1];
  cip = 0;
  for (i = minX; i <= maxX; i++) cip += cx[i];
  double ans = Stat(cx, minX, maxX) + Stat(cy, minY, maxY);
  ans /= cip;
  ans /= cip - 1;
  printf("%.10f\n", ans);
}
