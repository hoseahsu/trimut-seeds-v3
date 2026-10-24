#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
long long a, b, c, s;
long long gao(long long a, long long b, long long xl, long long xr) {
  if (xl > xr) return 0;
  if (a * xl + b < 0 && a * xr + b < 0) return 0;
  double key = -b * 1.0 / a;
  long long keyx;
  if (a > 0) {
    keyx = (key - EPS);
    keyx++;
  } else {
    keyx = (key + EPS);
  }
  if (a * xl + b < 0) {
    xl = keyx;
  }
  if (a * xr + b < 0) {
    xr = keyx;
  }
  long long ans = b * (xr - xl + 1);
  long long tmp = (xr + xl) * (xr - xl + 1) / 2;
  ans += tmp * a;
  return ans;
}
long long first_old(long long a, long long b, long long c) {
  long long ans = 0;
  long long i1, i2;
  long long jl, jr;
  long long tmp, oldAns;
  for (long long x = 0; x <= s; x++) {
    tmp = 0;
    oldAns = ans;
    long long keyi = min(a + x - b, s - x);
    if (keyi < 0) continue;
    i1 = a + x + 1 - b - c;
    i2 = s - 2 * x - a + c;
    i1 = min(keyi, i1);
    i2 = min(keyi, i2);
    if (i1 < 0 && i2 < 0) {
      jl = 0;
      jr = keyi;
      ans += gao(-1, s - x + 1, jl, jr);
    } else if (i1 < 0) {
      jl = 0;
      jr = i2;
      ans += gao(0, a + x - c + 1, jl, jr);
      jl = i2 + 1;
      jr = keyi;
      ans += gao(-1, s - x + 1, jl, jr);
    } else if (i2 < 0) {
      jl = 0;
      jr = i1;
      ans += gao(0, s - 2 * x - a - 1 + b + c + 1, jl, jr);
      jl = i1 + 1;
      jr = keyi;
      ans += gao(-1, s - x + 1, jl, jr);
    } else {
      if (i1 == i2) {
        jl = 0;
        jr = i1;
        ans += gao(1, b - 1 + 1, jl, jr);
        jl = i1 + 1;
        jr = keyi;
        ans += gao(-1, s - x + 1, jl, jr);
      } else if (i1 < i2) {
        jl = 0;
        jr = i1;
        ans += gao(1, b - 1 + 1, jl, jr);
        jl = i1 + 1;
        jr = i2;
        ans += gao(0, a + x - c + 1, jl, jr);
        jl = i2 + 1;
        jr = keyi;
        ans += gao(-1, s - x + 1, jl, jr);
      } else {
        jl = 0;
        jr = i2;
        ans += gao(1, b - 1 + 1, jl, jr);
        jl = i2 + 1;
        jr = i1;
        ans += gao(0, s - 2 * x - a - 1 + b + c + 1, jl, jr);
        jl = i1 + 1;
        jr = keyi;
        ans += gao(-1, s - x + 1, jl, jr);
      }
    }
  }
  return ans;
}
long long first(long long a, long long b, long long c) {
  long long ans = 0;
  for (long long x = 0; x <= s; x++) {
    if (b > a + x || c > a + x) continue;
    long long tmp = (s - x + 2) * (s - x + 1) / 2;
    if (s - x - (a + x + 1 - b) >= 0)
      tmp -= (s - x - (a + x + 1 - b) + 2) * (s - x - (a + x + 1 - b) + 1) / 2;
    if (s - x - (a + x + 1 - c) >= 0)
      tmp -= (s - x - (a + x + 1 - c) + 2) * (s - x - (a + x + 1 - c) + 1) / 2;
    if (s - x - (a + x + 1 - b) - (a + x + 1 - c) >= 0) {
      tmp += (s - x - (a + x + 1 - b) - (a + x + 1 - c) + 2) *
             (s - x - (a + x + 1 - b) - (a + x + 1 - c) + 1) / 2;
    }
    long long sum = a + x - b - c;
    if (sum >= 0) {
      sum = min(sum, s - x);
      tmp -= (sum + 2) * (sum + 1) / 2;
    }
    ans += tmp;
  }
  return ans;
}
long long second(long long a, long long b, long long c) {
  long long ans = 0;
  for (long long i = max(a, b);; i++) {
    if (i < c) continue;
    long long t = i - a + i - b;
    t = s - t;
    if (t < 0) break;
    if (c + t > i) {
      ans += i - c + 1;
    } else {
      ans += t + 1;
    }
  }
  return ans;
}
long long third(long long a, long long b, long long c) {
  long long ans = 0;
  long long t = max(a, b);
  t = max(t, c);
  for (long long i = t;; i++) {
    long long used = 3 * i - a - b - c;
    if (used > s) break;
    ans++;
  }
  return ans;
}
void solve() {
  long long ans = 0;
  ans += first(a, b, c);
  ans += first(b, a, c);
  ans += first(c, a, b);
  ans -= second(a, b, c);
  ans -= second(b, c, a);
  ans -= second(a, c, b);
  ans += third(a, b, c);
  printf("%I64d\n", ans);
}
int main() {
  while (scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &s) != EOF) {
    solve();
  }
  return 0;
}
