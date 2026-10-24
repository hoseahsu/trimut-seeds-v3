#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 50;
pair<int, int> p[nax];
double sqar(double a) { return a * a; }
int main() {
  double pi = acos(-1);
  int n, x0, y0;
  cin >> n >> x0 >> y0;
  double br = 0, sr = 1e18;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
    br = max(br, sqar(x - x0) + sqar(y - y0));
    sr = min(sr, sqar(x - x0) + sqar(y - y0));
  }
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    double x1 = p[i].first, y1 = p[i].second;
    double x2 = p[j].first, y2 = p[j].second;
    double l = sqar(x1 - x2) + sqar(y1 - y2);
    if (l == 0) continue;
    double t = ((x0 - x1) * (x2 - x1) + (y0 - y1) * (y2 - y1)) / l;
    t = max(0.0, min(1.0, t));
    double x = x1 + t * (x2 - x1);
    double y = y1 + t * (y2 - y1);
    double dis = sqar(x0 - x) + sqar(y0 - y);
    sr = min(sr, dis);
  }
  cout << setprecision(12);
  cout << pi * br - pi * sr << endl;
}
