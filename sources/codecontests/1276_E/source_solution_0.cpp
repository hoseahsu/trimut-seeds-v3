#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v1, v2, v3;
long long a[5], b[5], d;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void op(long long *a, vector<pair<long long, long long> > &mov, long long p1,
        long long p2) {
  mov.push_back(make_pair(a[p1], a[p2]));
  a[p1] = a[p2] * 2 - a[p1];
}
void solve(long long *a, vector<pair<long long, long long> > &mov) {
  while (true) {
    sort(a + 1, a + 5);
    if (a[1] + 1 == a[4]) break;
    while (min(a[2] - a[1], a[4] - a[2]) * 4 < a[4] - a[1] &&
           min(a[3] - a[1], a[4] - a[3]) * 4 < a[4] - a[1]) {
      long long p, q, q1, q2;
      if (min(a[2] - a[1], a[4] - a[2]) < min(a[3] - a[1], a[4] - a[3]))
        p = 2, q = 3;
      else
        p = 3, q = 2;
      if (a[q] - a[1] < a[4] - a[q])
        q1 = 1, q2 = q;
      else
        q1 = q, q2 = 4;
      if (a[p] - a[1] < a[4] - a[p])
        op(a, mov, p, q1), op(a, mov, p, q2);
      else
        op(a, mov, p, q2), op(a, mov, p, q1);
    }
    sort(a + 1, a + 5);
    if (min(a[2] - a[1], a[4] - a[2]) * 4 >= a[4] - a[1]) {
      if (a[2] - a[1] < a[4] - a[2])
        op(a, mov, 1, 2);
      else
        op(a, mov, 3, 2), op(a, mov, 4, 2);
    } else {
      if (a[3] - a[1] < a[4] - a[3])
        op(a, mov, 1, 3), op(a, mov, 2, 3);
      else
        op(a, mov, 4, 3);
    }
  }
  sort(a + 1, a + 5);
  if (a[1] & 1)
    for (long long i = 1; i <= 3; i++)
      if (a[i] < a[4]) op(a, mov, i, 4);
  sort(a + 1, a + 5);
}
void shift() {
  sort(a + 1, a + 5);
  if ((a[4] - a[1]) * 3 < abs(d)) {
    op(a, v3, 3, 1);
    op(a, v3, 2, 4);
    shift();
    sort(a + 1, a + 5);
    op(a, v3, 1, 2);
    op(a, v3, 4, 3);
  }
  sort(a + 1, a + 5);
  while (a[4] - a[1] <= abs(d)) {
    if (d > 0) {
      d -= a[4] - a[1];
      op(a, v3, 2, 1);
      op(a, v3, 2, 4);
      op(a, v3, 3, 1);
      op(a, v3, 3, 4);
      op(a, v3, 1, 4);
      op(a, v3, 4, 1);
    } else {
      d += a[4] - a[1];
      op(a, v3, 2, 4);
      op(a, v3, 2, 1);
      op(a, v3, 3, 4);
      op(a, v3, 3, 1);
      op(a, v3, 4, 1);
      op(a, v3, 1, 4);
    }
    sort(a + 1, a + 5);
  }
}
void purify(vector<pair<long long, long long> > &vec) {
  vector<pair<long long, long long> > tmp;
  for (pair<long long, long long> p : vec)
    if (p.first != p.second) tmp.push_back(p);
  vec = tmp;
}
signed main() {
  for (long long i = 1; i <= 4; i++) cin >> a[i];
  sort(a + 1, a + 5);
  for (long long i = 1; i <= 4; i++) cin >> b[i];
  sort(b + 1, b + 5);
  long long g = gcd(gcd(a[2] - a[1], a[3] - a[1]), a[4] - a[1]);
  if (gcd(gcd(b[2] - b[1], b[3] - b[1]), b[4] - b[1]) != g) {
    cout << -1;
    return 0;
  }
  bool e1 = a[1] == a[2] && a[2] == a[3] && a[3] == a[4],
       e2 = b[1] == b[2] && b[2] == b[3] && b[3] == b[4];
  if (e1 && e2) {
    if (a[1] != b[1])
      cout << -1;
    else
      cout << 0;
    return 0;
  }
  if (e1 || e2) {
    cout << -1;
    return 0;
  }
  if ((a[1] % g + g) % g != (b[1] % g + g) % g) {
    cout << -1;
    return 0;
  }
  long long delta = (a[1] % g + g) % g;
  for (long long i = 1; i <= 4; i++)
    a[i] = (a[i] - delta) / g, b[i] = (b[i] - delta) / g;
  long long c1[2] = {0}, c2[2] = {0};
  for (long long i = 1; i <= 4; i++) c1[abs(a[i]) & 1]++, c2[abs(b[i]) & 1]++;
  if (c1[0] != c2[0] || c1[1] != c2[1]) {
    cout << -1;
    return 0;
  }
  solve(a, v1);
  solve(b, v2);
  d = (b[1] - a[1]) / 2;
  shift();
  purify(v1);
  purify(v2);
  purify(v3);
  cout << v1.size() + v2.size() + v3.size() << '\n';
  for (pair<long long, long long> p : v1)
    cout << p.first * g + delta << ' ' << p.second * g + delta << '\n';
  for (pair<long long, long long> p : v3)
    cout << p.first * g + delta << ' ' << p.second * g + delta << '\n';
  long long siz = v2.size();
  for (long long i = siz - 1; i >= 0; i--)
    cout << (2 * v2[i].second - v2[i].first) * g + delta << ' '
         << v2[i].second * g + delta << '\n';
  return 0;
}
