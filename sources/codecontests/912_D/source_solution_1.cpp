#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long n, m, k, r, T, v, u;
long long num_u, num_v;
struct node {
  long long x, y;
  friend bool operator<(node a, node b) { return a.x * a.y < b.x * b.y; }
};
map<pair<int, int>, int> vis;
long long cnt(long long i, long long j) {
  if (i == u && j == v)
    return num_u * num_v;
  else if (i == u)
    return 2 * num_u;
  else if (j == v)
    return 2 * num_v;
  else
    return 4;
}
long long min(long long a, long long b) { return a < b ? a : b; }
int main() {
  cin >> n >> m >> r >> k;
  u = min(r, n - r + 1);
  v = min(r, m - r + 1);
  num_u = (r >= n - r + 1) ? 2 * r - n : n - 2 * r + 2;
  num_v = (r >= m - r + 1) ? 2 * r - m : m - 2 * r + 2;
  long long ans = 0;
  priority_queue<node> que;
  node tmp;
  tmp.x = u, tmp.y = v;
  que.push(tmp);
  while (que.size() && k) {
    node p = que.top();
    que.pop();
    if (vis[pair<int, int>(p.x, p.y)]) continue;
    vis[pair<int, int>(p.x, p.y)] = 1;
    int time = min(k, cnt(p.x, p.y));
    k -= time;
    ans += (long long)time * p.x * p.y;
    if (1 <= p.x - 1 && p.x - 1 <= n && 1 <= p.y && p.y <= m) {
      tmp.x = p.x - 1, tmp.y = p.y;
      que.push(tmp);
    }
    if (1 <= p.x && p.x <= n && 1 <= p.y - 1 && p.y - 1 <= m) {
      tmp.x = p.x, tmp.y = p.y - 1;
      que.push(tmp);
    }
  }
  printf("%.10f\n", (double)ans / ((n - r + 1) * (m - r + 1)));
  return 0;
}
