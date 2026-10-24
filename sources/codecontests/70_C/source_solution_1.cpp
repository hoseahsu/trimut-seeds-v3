#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, vector<int> > M;
map<pair<int, int>, int> Mcnt;
const long long inf = (long long)1E16;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int rev(int x) {
  int y = 0;
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
  }
  return y;
}
int main() {
  int mx, my, need, i, j, d, tx, ty;
  while (~scanf("%d%d%d", &mx, &my, &need)) {
    int cur = 0, cx = 1, cy = my;
    M.clear();
    Mcnt.clear();
    for (i = 1; i <= my; i++) {
      j = rev(i);
      int x = i, y = j;
      d = gcd(x, y);
      x /= d, y /= d;
      M[make_pair(x, y)].push_back(i);
    }
    long long res = inf;
    int rx = -1, ry = -1;
    for (; cx <= mx; cx++) {
      ty = cx, tx = rev(cx);
      d = gcd(tx, ty);
      tx /= d, ty /= d;
      cur += M[make_pair(tx, ty)].size();
      Mcnt[make_pair(tx, ty)]++;
      while (cy > 1 && cur >= need) {
        int x = cy, y = rev(cy);
        d = gcd(x, y);
        x /= d, y /= d;
        int dd = Mcnt[make_pair(x, y)];
        if (cur - dd < need) break;
        cur -= dd;
        M[make_pair(x, y)].pop_back();
        --cy;
      }
      if (cur >= need) {
        long long r0 = (long long)cx * (long long)cy;
        if (res > r0) {
          res = r0;
          rx = cx, ry = cy;
        }
      }
    }
    if (res == inf)
      printf("-1\n");
    else
      printf("%d %d\n", rx, ry);
  }
  return 0;
}
