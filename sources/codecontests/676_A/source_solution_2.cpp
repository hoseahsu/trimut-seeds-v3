#include <bits/stdc++.h>
using namespace std;
int isP(long int hj) {
  long int op;
  for (op = 2; op <= sqrt(hj); op++) {
    if (hj % op == 0) return 0;
  }
  return 1;
}
void swap(long long int *p, long long int *q) {
  long long int tmp = *p;
  *p = *q;
  *q = tmp;
}
void tog(int *p) {
  if (*p == 1)
    *p = 0;
  else
    *p = 1;
}
string fdi(int hi) {
  switch (hi) {
    case 0:
      return "zero";
    case 1:
      return "one";
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6:
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
  }
  return "";
}
string rdx(int hi) {
  switch (hi) {
    case 2:
      return "twenty";
    case 3:
      return "thirty";
    case 4:
      return "forty";
    case 5:
      return "fifty";
    case 6:
      return "sixty";
    case 7:
      return "seventy";
    case 8:
      return "eighty";
    case 9:
      return "ninety";
  }
  return "";
}
long long int bd(long long int mk, long long int nk) {
  long long int i;
  for (i = min(mk, nk); i >= 1; i--) {
    if (mk % i == 0 && nk % i == 0) return i;
  }
  return 0;
}
int dsm(long long int pkk) {
  if (pkk < 0) pkk *= -1;
  while (pkk > 0) {
    if (pkk % 10 == 8) return 1;
    pkk /= 10;
  }
  return 0;
}
int main() {
  long long int nk, pl, lmin, rmax, np, odI, l, evI, r, a1, a2, amt, maxu, y3,
      sx, sy, bsm, fsm, bu, cp, bf, pr, res, lastm, c, r1, r2, x1, x2, y1, y2,
      maxN, m1, m2, prev, prc, cost, ind, ans, g, p, inc, cap, sm, d, nxt, mn,
      t, up, a, b, lc, la, e, preI, t2, brk, clbp, clb, et, jmp, u, l1, l2, sq,
      nd, maxi, li, ri, tr, mp, og, lt1, lt2, n1, n2, c1, c2, minI, min1, p2,
      p3, ze, fst, lst, min2, s, sm1, sm2, sm3, sr, sl, ln, rz, rn, car, eq,
      shr, ng, v, curr, spl, fl, z, ev, od, m, ct, j, q, k, maxI, max1, max2,
      lt, md, f, n, xP, xN, w, h, d2, d1, u1, u2, i, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a == n) p = i;
    if (a == 1) q = i;
  }
  if ((n - 1) - max(p, q) >= min(p, q) - 0)
    ans = n - 1 - min(p, q);
  else
    ans = max(p, q);
  cout << ans;
  return 0;
}
