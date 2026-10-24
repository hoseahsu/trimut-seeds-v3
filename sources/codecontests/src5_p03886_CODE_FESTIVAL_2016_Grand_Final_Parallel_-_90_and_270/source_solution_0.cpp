/**
 *    author:  tourist
 *    created: 27.11.2019 08:48:17       
**/
#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

void MoveX(vector<Point>& p, int x) {
  for (auto& q : p) {
    if (q.x >= x) {
      ++q.x;
    }
  }
}

void MoveY(vector<Point>& p, int y) {
  for (auto& q : p) {
    if (q.y >= y) {
      ++q.y;
    }
  }
}

int Signum(int x) {
  return (x > 0 ? 1 : (x < 0 ? -1 : 0));
}

vector<Point> Solve(const vector<int>& a) {
  if (a.size() == 4) {
    return {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  }
  int n = (int) a.size();
  for (int i = 0; i < n - 1; i++) {
    if (a[i] + a[i + 1] == 360) {
      vector<int> b = a;
      b.erase(b.begin() + i, b.begin() + i + 2);
      auto p = Solve(b);
      int pr = (i == 0 ? n - 3 : i - 1);
      int ne = (i == n - 2 ? 0 : i);
      MoveX(p, p[pr].x + 1);
      MoveX(p, p[pr].x);
      MoveY(p, p[pr].y + 1);
      MoveY(p, p[pr].y);
      Point u = p[pr];
      Point v = p[ne];
      if (u.x == v.x) {
        int dy = (u.y > v.y ? -1 : 1);
        int dx = Signum(p[(pr + n - 3) % (n - 2)].x - u.x);
        if (b[pr] != a[i]) {
          dx *= -1;
        }
        p[ne].x += dx;
        p.insert(p.begin() + i, {u.x, u.y + dy});
        p.insert(p.begin() + i + 1, {u.x + dx, u.y + dy});
      } else {
        int dx = (u.x > v.x ? -1 : 1);
        int dy = Signum(p[(pr + n - 3) % (n - 2)].y - u.y);
        if (b[pr] != a[i]) {
          dy *= -1;
        }
        p[ne].y += dy;
        p.insert(p.begin() + i, {u.x + dx, u.y});
        p.insert(p.begin() + i + 1, {u.x + dx, u.y + dy});
      }
      return p;
    }
  }
  assert(false);
  return {};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (n % 2 == 1 || sum != 180 * (n - 2)) {
    cout << -1 << '\n';
    return 0;
  }
  auto res = Solve(a);
  for (auto& p : res) {
    cout << p.x << " " << p.y << '\n';
  }
  return 0;
}
