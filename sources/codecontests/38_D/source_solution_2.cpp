#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
struct Brck {
  int x0, y0, x1, y1;
  Brck() {}
  Brck(int _x0, int _y0, int _x1, int _y1)
      : x0(_x0), y0(_y0), x1(_x1), y1(_y1) {
    if (x0 > x1) swap(x0, x1);
    if (y0 > y1) swap(y0, y1);
  }
  int side() { return x1 - x0; }
  int vol() {
    int a = side();
    return a * a * a;
  }
  double cx() { return (x0 + x1) * 0.5; }
  double cy() { return (y0 + y1) * 0.5; }
  bool inside(double x, double y) {
    return x0 <= x && x <= x1 && y0 <= y && y <= y1;
  }
};
Brck bs[MAX_N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x0, y0, x1, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    bs[i] = Brck(x0, y0, x1, y1);
  }
  int h;
  for (h = 1; h < n; h++) {
    int v = bs[h].vol();
    double vx = bs[h].cx() * v, vy = bs[h].cy() * v;
    bool stbl = true;
    for (int i = h - 1; i >= 0; i--) {
      if (!bs[i].inside(vx / v, vy / v)) {
        stbl = false;
        break;
      }
      int vi = bs[i].vol();
      v += vi;
      vx += bs[i].cx() * vi;
      vy += bs[i].cy() * vi;
    }
    if (!stbl) break;
  }
  printf("%d\n", h);
  return 0;
}
