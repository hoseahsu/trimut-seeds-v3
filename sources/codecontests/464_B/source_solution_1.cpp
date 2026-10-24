#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int B = 8, M = 1 << B;
int ord[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                 {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
struct P {
  int x, y, z;
  bool operator==(const P &rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
  }
  P operator-(const P &rhs) { return P{x - rhs.x, y - rhs.y, z - rhs.z}; }
  void s() {
    if (x > y) swap(x, y);
    if (x > z) swap(x, z);
    if (y > z) swap(y, z);
  }
} ps[8], pa[8];
P perm(const P &p, int id) {
  int c[3] = {p.x, p.y, p.z};
  return {c[ord[id][0]], c[ord[id][1]], c[ord[id][2]]};
}
LL inner_product(const P &p1, const P &p2) {
  return (LL)p1.x * p2.x + (LL)p1.y * p2.y + (LL)p1.z * p2.z;
}
int pop_count(int v) {
  int c = 0;
  while (v) {
    ++c;
    v = v & (v - 1);
  }
  return c;
}
bool find_it(P *pc, P pr, bool *used) {
  pr.s();
  for (int i = 0; i < 5; i++) {
    if (used[i]) continue;
    if (pc[i] == pr) {
      used[i] = true;
      return true;
    }
  }
  return false;
}
bool solve(int ma) {
  int c1 = 0, c2 = 0;
  P pb[3], po[5];
  for (int i = 0; i < B; i++) {
    if (ma & (1 << i))
      pb[c1++] = ps[i];
    else
      po[c2++] = ps[i];
  }
  for (int i1 = 0; i1 < 6; i1++) {
    P p1 = perm(pb[0], i1);
    for (int i2 = 0; i2 < 6; i2++) {
      P p2 = perm(pb[1], i2);
      if (p1 == p2) continue;
      LL l = inner_product(p2 - p1, p2 - p1);
      for (int i3 = 0; i3 < 6; i3++) {
        P p3 = perm(pb[2], i3);
        if (inner_product(p3 - p2, p3 - p2) != l ||
            inner_product(p3 - p2, p2 - p1) != 0)
          continue;
        bool used[5] = {false};
        P p4 = {p1.x + p3.x - p2.x, p1.y + p3.y - p2.y, p1.z + p3.z - p2.z};
        if (!find_it(po, p4, used)) continue;
        for (int i5 = 0; i5 < 5; i5++) {
          if (used[i5]) continue;
          for (int o5 = 0; o5 < 6; o5++) {
            P p5 = perm(ps[i5], o5);
            if (p5 == p1 || inner_product(p5 - p1, p2 - p1) != 0 ||
                inner_product(p5 - p1, p3 - p1) != 0 ||
                inner_product(p5 - p1, p5 - p1) != l)
              continue;
            int dx = p5.x - p1.x, dy = p5.y - p1.y, dz = p5.z - p1.z;
            P p6 = {p2.x + dx, p2.y + dy, p2.z + dz};
            P p7 = {p3.x + dx, p3.y + dy, p3.z + dz};
            P p8 = {p4.x + dx, p4.y + dy, p4.z + dz};
            if (find_it(po, p5, used) && find_it(po, p6, used) &&
                find_it(po, p7, used) && find_it(po, p8, used)) {
              pa[0] = p1;
              pa[1] = p2;
              pa[2] = p3;
              pa[3] = p4;
              pa[4] = p5;
              pa[5] = p6;
              pa[6] = p7;
              pa[7] = p8;
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}
void reorder() {
  for (int i = 0; i < 8; i++) {
    for (int j = i; j < 8; j++) {
      P p = pa[j];
      p.s();
      if (ps[i] == p) {
        swap(pa[i], pa[j]);
        break;
      }
    }
  }
}
int main() {
  for (int i = 0; i < B; i++) {
    scanf("%d%d%d", &ps[i].x, &ps[i].y, &ps[i].z);
    ps[i].s();
  }
  bool found = false;
  for (int i = 0; i < M; i++) {
    if (pop_count(i) == 3 && solve(i)) {
      found = true;
      break;
    }
  }
  if (!found)
    puts("NO");
  else {
    puts("YES");
    reorder();
    for (int i = 0; i < 8; i++) {
      printf("%d %d %d\n", pa[i].x, pa[i].y, pa[i].z);
    }
  }
}
