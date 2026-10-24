#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {
  int x, y;
  bool operator<(const Point a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
  bool operator>(const Point a) const {
    if (x == a.x) return y > a.y;
    return x > a.x;
  }
} s[200005];
bool cmp(Point a, Point b) { return a.x < b.x; }
int cnt;
set<Point> used;
void dp(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  dp(l, mid);
  dp(mid + 1, r);
  Point tmp;
  tmp.x = s[mid].x;
  for (int i = l; i <= r; ++i) {
    tmp.y = s[i].y;
    if (used.count(tmp) != 1) {
      used.insert(tmp);
      s[++cnt] = tmp;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i].x >> s[i].y;
    used.insert(s[i]);
  }
  sort(s + 1, s + 1 + n, cmp);
  cnt = n;
  dp(1, n);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) {
    printf("%d %d\n", s[i].x, s[i].y);
  }
}
