#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Block {
  Block() : xl(0), xr(0), m(0), mg(0) {}

  int xl, xr;
  int m, mg;
};

void check(Block &b, vector<vector<char> > &q,
           int y, int x, char n, int ly) {
  if (q[y][x] == '.') {
    return;
  }

  if ((q[y][x] & 191) != n && ly == y + 1) {
    b.xl = min(x, b.xl);
    b.xr = max(x, b.xr);
    return;
  }

  if (q[y][x] & 64) {
    return;
  }

  if (q[y][x] != n && ly == y - 1) {
    Block c;
    c.xl = c.xr = x;
    check(c, q, y, x, q[y][x], y);

    double g = (double)c.mg / c.m - 0.5;
    if (g <= c.xl - 1 || g >= c.xr) {
      throw -1;
    }

    b.m += c.m;
    b.mg += c.mg;

    return;
  }

  if (q[y][x] != n) {
    return;
  }

  b.m++;
  b.mg += x;
  q[y][x] |= 64;

  check(b, q, y, x - 1, n, y);
  check(b, q, y, x + 1, n, y);
  check(b, q, y - 1, x, n, y);
  check(b, q, y + 1, x, n, y);
}

int main() {
  int w, h;
  while (cin >> w >> h, w != 0) {
    vector<vector<char> > q(h + 2);

    for (int i = 0; i < h + 2; i++) {
      q[i].resize(w + 2);
      fill(q[i].begin(), q[i].end(), '.');
    }

    for (int x = 1; x <= w; x++) {
      q[0][x] |= 64;
    }

    for (int y = h; y >= 1; y--) {
      for (int x = 1; x <= w; x++) {
        cin >> q[y][x];
      }
    }

    Block dummy;
    for (int x = 1; x <= w; x++) {
      if (q[1][x] != '.') {
        try {
          check(dummy, q, 1, x, '-', 0);
          cout << "STABLE" << endl;
        } catch (int i) {
          cout << "UNSTABLE" << endl;
        }
        break;
      }
    }
  }

  return 0;
}