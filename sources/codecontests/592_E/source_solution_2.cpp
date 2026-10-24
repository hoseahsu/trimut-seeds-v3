#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};
int quadrant(point p) {
  if (p.y >= 0 && p.x > 0) return 1;
  if (p.y > 0 && p.x <= 0) return 2;
  if (p.y <= 0 && p.x < 0) return 3;
  return 4;
}
bool operator<(point l, point r) {
  int ql = quadrant(l);
  int qr = quadrant(r);
  if (ql != qr) return ql < qr;
  return 1ll * l.y * r.x < 1ll * r.y * l.x;
}
int n, c, d;
point p[400010];
long long rr[400010];
long long ans, cur;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) {
    int r, w;
    cin >> r >> w;
    p[i] = point(r - c, w - d);
  }
  sort(p, p + n);
  for (int l = 0, r = 0; l < n; l++) {
    if (quadrant(p[l]) > 2) r = n;
    point nl = point(-p[l].x, -p[l].y);
    while (r < n && p[r] < nl) r++;
    rr[l] = r - 1;
  }
  for (int l = 0, r = 0; l < n && quadrant(p[l]) <= 2; l++) {
    point nl = point(-p[l].x, -p[l].y);
    while (r < n && p[r] < nl) {
      cur += rr[r];
      r++;
    }
    ans += cur - rr[l] * (rr[l] - l + 1);
    int num_greater = rr[l] - (upper_bound(p, p + n, p[l]) - p - 1);
    int num_opposite = upper_bound(p, p + n, nl) - lower_bound(p, p + n, nl);
    ans -= 1ll * num_greater * num_opposite;
    cur -= rr[l];
  }
  cout << ans << '\n';
}
