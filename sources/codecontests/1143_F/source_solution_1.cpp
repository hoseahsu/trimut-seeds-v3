#include <bits/stdc++.h>
using namespace std;
struct pt {
  long long x, y;
  int id;
  pt(long long x_ = 0, long long y_ = 0, int id_ = 0) {
    x = x_, y = y_;
    id = id_;
  }
  bool operator<(const pt &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y, id); }
};
long long cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
vector<pt> p;
void convexHull(vector<pt> &p) {
  sort(p.begin(), p.end());
  int n = p.size();
  vector<pt> h(2 * n);
  int k = 0;
  h[k++] = p[0];
  for (int i = 1; i < n; i++) {
    while (k >= 2 && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) >= 0) k--;
    h[k++] = p[i];
  }
  printf("%d\n", k - 1);
}
int n;
int main() {
  scanf("%d", &n);
  map<long long, long long> mp;
  for (int i = 1; i <= n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (!mp.count(x)) mp[x] = y;
    mp[x] = max(mp[x], y);
  }
  int id = 0;
  for (auto o : mp) {
    long long x = o.first;
    long long y = o.second;
    p.push_back(pt(x, y - x * x, ++id));
  }
  convexHull(p);
  return 0;
}
