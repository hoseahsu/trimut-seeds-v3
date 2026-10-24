#include <bits/stdc++.h>
using namespace std;
typedef struct cpx {
  long long x, y;
  cpx() {}
  cpx(int a, int b) {
    x = a;
    y = b;
  }
} cpx;
cpx add(cpx a, cpx b) { return cpx(a.x + b.x, a.y + b.y); }
cpx sub(cpx a, cpx b) { return cpx(a.x - b.x, a.y - b.y); }
cpx mul(cpx a, cpx b) {
  return cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
cpx un(0, 1);
long long gcd(long long a, long long b) { return b > 0 ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long is(long long xc, long long yc, long long xd, long long yd) {
  if (xc == 0 && yc == 0) {
    if (xd == 0 && yd == 0) {
      return 1;
    }
  } else if (xc == 0) {
    if (xd % yc == 0 && yd % yc == 0) {
      return 1;
    }
  } else if (yc == 0) {
    if (xd % xc == 0 && yd % xc == 0) {
      return 1;
    }
  } else {
    long long l = lcm(xc, yc);
    long long b;
    b = (xc * yd - yc * xd) / (yc * yc + xc * xc);
    if ((xc * yd - yc * xd) % (yc * yc + xc * xc) || (xd + b * yc) % xc)
      return 0;
    return 1;
  }
  return 0;
}
int main() {
  long long x, y;
  cpx a, b, c;
  int i;
  scanf("%I64d%I64d", &x, &y);
  a = cpx(x, y);
  scanf("%I64d%I64d", &x, &y);
  b = cpx(x, y);
  scanf("%I64d%I64d", &x, &y);
  c = cpx(x, y);
  cpx d;
  long long xc, yc, xd, yd;
  d = sub(b, mul(un, a));
  xc = c.x;
  yc = c.y;
  xd = d.x;
  yd = d.y;
  if (is(xc, yc, xd, yd)) {
    printf("YES");
    return 0;
  }
  d = add(b, mul(un, a));
  xd = d.x;
  yd = d.y;
  if (is(xc, yc, xd, yd)) {
    printf("YES");
    return 0;
  }
  d = add(b, a);
  xd = d.x;
  yd = d.y;
  if (is(xc, yc, xd, yd)) {
    printf("YES");
    return 0;
  }
  d = sub(b, a);
  xd = d.x;
  yd = d.y;
  if (is(xc, yc, xd, yd)) {
    printf("YES");
    return 0;
  }
  printf("NO");
  return 0;
}
