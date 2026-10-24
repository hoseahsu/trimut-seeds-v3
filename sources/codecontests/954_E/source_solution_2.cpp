#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, T;
long long tot;
double ans;
struct data {
  long long a, t;
} dat[N];
int getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
bool cmp(data a, data b) { return a.t < b.t; }
void solve_big() {
  for (int i = n; i >= 1; --i) {
    if (tot - dat[i].a * dat[i].t > 0)
      tot -= dat[i].a * dat[i].t, ans -= dat[i].a;
    else {
      ans -= (double)tot / dat[i].t;
      break;
    }
  }
  printf("%.10lf\n", ans);
}
void solve_small() {
  for (int i = 1; i <= n; ++i) {
    if (tot - dat[i].a * dat[i].t < 0)
      tot -= dat[i].a * dat[i].t, ans -= dat[i].a;
    else {
      ans -= (double)tot / dat[i].t;
      break;
    }
  }
  printf("%.10lf\n", ans);
}
int main() {
  n = getint(), T = getint();
  for (int i = 1; i <= n; ++i) ans += (dat[i].a = getint());
  for (int i = 1; i <= n; ++i) dat[i].t = getint() - T;
  bool jdg = 0;
  for (int i = 1; i <= n; ++i)
    if (dat[i].t >= 0) {
      jdg = 1;
      break;
    }
  if (!jdg) return puts("0"), 0;
  jdg = 0;
  for (int i = 1; i <= n; ++i)
    if (dat[i].t <= 0) {
      jdg = 1;
      break;
    }
  if (!jdg) return puts("0"), 0;
  for (int i = 1; i <= n; ++i) tot += dat[i].a * dat[i].t;
  sort(dat + 1, dat + 1 + n, cmp);
  if (tot == 0) return printf("%.10lf\n", ans), 0;
  if (tot > 0)
    solve_big();
  else
    solve_small();
  return 0;
}
