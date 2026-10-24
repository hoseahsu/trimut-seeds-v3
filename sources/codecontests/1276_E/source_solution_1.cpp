#include <bits/stdc++.h>
using namespace std;
long long a[4], b[4];
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void move(long long *a, vector<pair<long long, long long> > &A, int p, int q) {
  A.push_back(pair<long long, long long>(a[p], a[q]));
  a[p] = 2 * a[q] - a[p];
  sort(a, a + 4);
}
void undo(long long *a, pair<long long, long long> op,
          vector<pair<long long, long long> > &A, long long shf) {
  op.first += shf, op.second += shf;
  long long x = op.second * 2 - op.first, y = op.second;
  for (int i = 0; i < 4; i++)
    if (a[i] == x) {
      a[i] = op.first;
      break;
    }
  A.push_back(pair<long long, long long>(x, y));
  sort(a, a + 4);
}
long long shrink(long long *a, vector<pair<long long, long long> > &A) {
  while (a[3] - a[0] > 1) {
    long long dt = a[3] - a[0];
    long long l = a[0] + dt / 4, r = a[0] + 3 * dt / 4;
    if (l == a[0]) ++l;
    if (r == a[3]) --r;
    if (a[1] < l && a[2] < l) {
      while ((a[1] < l || a[1] > r) && (a[2] < l || a[2] > r)) {
        move(a, A, 1, 0);
        move(a, A, 0, 2);
      }
    } else if (a[1] > r && a[2] > r) {
      while ((a[1] < l || a[1] > r) && (a[2] < l || a[2] > r)) {
        move(a, A, 2, 3);
        move(a, A, 3, 1);
      }
    } else {
      while ((a[1] < l || a[1] > r) && (a[2] < l || a[2] > r)) {
        if (a[3] - a[2] > a[1] - a[0]) {
          move(a, A, 1, 2);
          move(a, A, 3, 2);
        } else {
          move(a, A, 2, 1);
          move(a, A, 0, 1);
        }
      }
    }
    if (l <= a[1] && a[1] <= r)
      move(a, A, 0, 1);
    else
      move(a, A, 0, 2);
  }
  while (a[0] & 1) {
    for (int i = 1; i < 4; i++)
      if (a[i] == a[0] + 1) {
        move(a, A, 0, i);
        break;
      }
  }
  return a[0];
}
int main() {
  for (int i = 0; i < 4; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < 4; i++) scanf("%lld", &b[i]);
  sort(a, a + 4), sort(b, b + 4);
  bool o = true;
  for (int i = 1; i < 4; i++) o &= a[i] == a[i - 1];
  if (o) {
    for (int i = 0; i < 4; i++)
      if (a[0] != b[i]) return puts("-1"), 0;
    return puts("0"), 0;
  }
  long long x = 0, y = 0;
  for (int i = 1; i < 4; i++)
    x = gcd(x, a[i] - a[i - 1]), y = gcd(y, b[i] - b[i - 1]);
  if (x != y) return puts("-1"), 0;
  long long p = a[0] % x, q = b[0] % x;
  if (p != q) return puts("-1"), 0;
  for (int i = 0; i < 4; i++) a[i] = (a[i] - p) / x, b[i] = (b[i] - p) / x;
  int ck = 0, dk = 0;
  for (int i = 0; i < 4; i++)
    ck += (a[i] & 1) - (b[i] & 1), dk += (a[i] & 1 ^ 1) - (b[i] & 1 ^ 1);
  if (ck || dk) return puts("-1"), 0;
  vector<pair<long long, long long> > A, B, C;
  long long L = shrink(a, A);
  long long R = shrink(b, B);
  if (L <= R) {
    long long d = (R - L) >> 1;
    vector<pair<long long, long long> > S;
    while (a[3] - a[0] < d)
      move(a, S, 2, 0), C.push_back(S.back()), move(a, S, 2, 3),
          C.push_back(S.back());
    long long dt = 0;
    while (d) {
      while (a[3] - a[0] > d) {
        undo(a, S.back(), C, dt);
        S.pop_back();
      }
      while (a[3] - a[0] <= d) {
        d -= a[3] - a[0];
        dt += (a[3] - a[0]) * 2;
        move(a, C, 1, 0);
        move(a, C, 0, 3);
        move(a, C, 1, 0);
        move(a, C, 0, 2);
        move(a, C, 0, 1);
        move(a, C, 0, 1);
      }
    }
    d = R - L;
    while (S.size()) undo(a, S.back(), C, dt), S.pop_back();
  } else {
    long long d = (L - R) >> 1;
    vector<pair<long long, long long> > S;
    while (a[3] - a[0] < d)
      move(a, S, 2, 0), C.push_back(S.back()), move(a, S, 2, 3),
          C.push_back(S.back());
    long long dt = 0;
    while (d) {
      while (a[3] - a[0] > d) {
        undo(a, S.back(), C, dt);
        S.pop_back();
      }
      while (a[3] - a[0] <= d) {
        d -= a[3] - a[0];
        dt -= (a[3] - a[0]) * 2;
        move(a, C, 2, 3);
        move(a, C, 3, 0);
        move(a, C, 2, 3);
        move(a, C, 3, 1);
        move(a, C, 3, 2);
        move(a, C, 3, 2);
      }
    }
    d = R - L;
    while (S.size()) undo(a, S.back(), C, dt), S.pop_back();
  }
  vector<pair<long long, long long> > ans;
  for (pair<long long, long long> z : A) ans.push_back(z);
  for (pair<long long, long long> z : C) ans.push_back(z);
  for (int z = B.size() - 1; ~z; z--) undo(a, B[z], ans, 0);
  vector<pair<long long, long long> > fx;
  for (pair<long long, long long> z : ans)
    if (z.first != z.second)
      fx.push_back(
          pair<long long, long long>(z.first * x + p, z.second * x + p));
  cout << fx.size() << '\n';
  for (pair<long long, long long> z : fx)
    cout << z.first << " " << z.second << '\n';
  return 0;
}
