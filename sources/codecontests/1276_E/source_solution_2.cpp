#include <bits/stdc++.h>
using namespace std;
struct Ans {
  long long a[1001][2];
  int tot;
  void add(long long x, long long y) {
    if (x == y) return;
    ++tot;
    a[tot][0] = x;
    a[tot][1] = y;
  }
} A, B;
long long a[4], b[4], d, g;
int i, j, k, l;
long long gcd(long long x, long long y) {
  long long r = x % y;
  while (r) x = y, y = r, r = x % y;
  return y;
}
long long turn(long long t) { return t * g + d; }
void Turn(long long *a) {
  for (i = 0; i <= 3; i++) a[i] = (a[i] - d) / g;
}
void jump(long long &x, long long &y) { x = y * 2 - x; }
void work(long long *a, Ans &b) {
  long long d;
  while (a[3] - a[0] > 1) {
    d = (a[3] - a[0] + 2) / 4;
    if (a[0] + d <= a[1] && a[1] <= a[3] - d) {
      if (a[1] * 2 - a[0] <= a[3])
        b.add(a[0], a[1]), jump(a[0], a[1]);
      else
        b.add(a[3], a[1]), jump(a[3], a[1]);
    } else if (a[0] + d <= a[2] && a[2] <= a[3] - d) {
      if (a[2] * 2 - a[0] <= a[3])
        b.add(a[0], a[2]), jump(a[0], a[2]);
      else
        b.add(a[3], a[2]), jump(a[3], a[2]);
    } else {
      while (!(a[0] + d <= a[1] && a[1] <= a[3] - d) &&
             !(a[0] + d <= a[2] && a[2] <= a[3] - d)) {
        if (a[1] < a[0] + d && a[3] - d < a[2]) {
          if (a[1] - a[0] < a[3] - a[2])
            b.add(a[1], a[2]), jump(a[1], a[2]), b.add(a[1], a[3]),
                jump(a[1], a[3]);
          else
            b.add(a[2], a[1]), jump(a[2], a[1]), b.add(a[2], a[0]),
                jump(a[2], a[0]);
        } else if (a[3] - d < a[1])
          b.add(a[3], a[1]), jump(a[3], a[1]);
        else
          b.add(a[0], a[2]), jump(a[0], a[2]);
        sort(a, a + 4);
      }
    }
    sort(a, a + 4);
  }
}
void kuo() {
  A.add(a[2], a[0]), jump(a[2], a[0]);
  A.add(a[1], a[3]), jump(a[1], a[3]);
  sort(a, a + 4);
}
void suo() {
  A.add(a[0], a[1]), jump(a[0], a[1]);
  A.add(a[3], a[2]), jump(a[3], a[2]);
  sort(a, a + 4);
}
void Work() {
  long long d, l;
  if (a[3] <= b[0]) {
    while (!(a[3] - a[0] == 1 && a[0] == b[0])) {
      if (a[0] == 999999998) i = i;
      d = b[3] - a[3], l = a[3] - a[0];
      if (l >= d) {
        while (l > max(d, b[3] - b[0])) suo(), d = b[3] - a[3], l = a[3] - a[0];
        if (a[0] != b[0] || a[3] != b[3])
          for (i = 0; i <= 2; i++) A.add(a[i], a[3]), jump(a[i], a[3]);
      } else {
        while (l < d) kuo(), d = b[3] - a[3], l = a[3] - a[0];
      }
      sort(a, a + 4);
    }
  } else if (b[3] <= a[0]) {
    while (!(a[3] - a[0] == 1 && a[0] == b[0])) {
      d = a[0] - b[0], l = a[3] - a[0];
      if (l >= d) {
        while (l > max(d, b[3] - b[0])) suo(), d = a[0] - b[0], l = a[3] - a[0];
        if (a[0] != b[0] || a[3] != b[3])
          for (i = 3; i >= 1; i--) A.add(a[i], a[0]), jump(a[i], a[0]);
      } else {
        while (l < d) kuo(), d = a[0] - b[0], l = a[3] - a[0];
      }
      sort(a, a + 4);
    }
  }
}
int main() {
  for (i = 0; i <= 3; i++) scanf("%lld", &a[i]);
  sort(a, a + 4);
  for (i = 0; i <= 3; i++) scanf("%lld", &b[i]);
  sort(b, b + 4);
  if (a[3] == a[0] || b[3] == b[0]) {
    if (a[3] == a[0] && b[3] == b[0] && b[0] == a[0])
      printf("0\n");
    else
      printf("-1\n");
    return 0;
  }
  g = a[3] - a[0];
  for (i = 1; i <= 2; i++)
    if (a[i] > a[0]) g = gcd(g, a[i] - a[0]);
  d = ((a[0] % g) + g) % g;
  Turn(a);
  l = b[3] - b[0];
  for (i = 1; i <= 2; i++)
    if (b[i] > b[0]) l = gcd(l, b[i] - b[0]);
  if (l != g) {
    printf("-1\n");
    return 0;
  }
  for (i = 0; i <= 3; i++)
    if ((b[i] % g + g) % g != d) {
      printf("-1\n");
      return 0;
    }
  Turn(b);
  k = l = 0;
  for (i = 0; i <= 3; i++)
    if (a[i] & 1)
      ++k;
    else
      ++l;
  for (i = 0; i <= 3; i++)
    if (b[i] & 1)
      --k;
    else
      --l;
  if (k && l) {
    printf("-1\n");
    return 0;
  }
  work(a, A), work(b, B);
  Work();
  printf("%d\n", A.tot + B.tot);
  for (i = 1; i <= A.tot; i++)
    printf("%I64d %I64d\n", turn(A.a[i][0]), turn(A.a[i][1]));
  for (i = B.tot; i >= 1; i--)
    printf("%I64d %I64d\n", turn(B.a[i][1] * 2 - B.a[i][0]), turn(B.a[i][1]));
  fclose(stdin);
  fclose(stdout);
  return 0;
}
