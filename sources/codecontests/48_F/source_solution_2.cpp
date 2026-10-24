#include <bits/stdc++.h>
using namespace std;
int n, m, w;
const int MAXN = 500010;
struct Snow {
  int w, c, a;
  long double per_cost;
} snow[MAXN];
int Sort(int left, int right, int num) {
  if (left >= right) return 0;
  int l = left, r = right;
  long double midc = snow[(l + r) / 2].per_cost;
  while (l <= r) {
    while (snow[l].per_cost < midc) l++;
    while (snow[r].per_cost > midc) r--;
    if (l <= r) swap(snow[l++], snow[r--]);
  }
  int tmp = num;
  for (int i = left; i < l && tmp >= 0; i++) tmp -= snow[i].w;
  if (tmp < 0)
    Sort(left, l - 1, num);
  else if (tmp > 0)
    Sort(l, right, tmp);
  return 0;
}
long long ansll = 0;
long double ansd = 0;
inline long double Dec(long double a) { return a - (long long)a; }
int main() {
  scanf("%d %d %d", &n, &m, &w);
  for (int i = 0; i < m; i++) scanf("%d", &snow[i].w);
  for (int i = 0; i < m; i++) scanf("%d", &snow[i].c);
  for (int i = 0; i < m; i++) scanf("%d", &snow[i].a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      snow[j].per_cost = (long double)snow[j].c / snow[j].w;
    Sort(0, m - 1, w);
    for (int now = w, pos = 0; now > 0 && pos < m; pos++) {
      if (snow[pos].w > now) {
        ansll += (long long)snow[pos].per_cost * now;
        long double dd = Dec(snow[pos].per_cost) * now;
        ansll += (long long)dd;
        dd -= (long long)dd;
        ansd += dd;
        ansll += (long long)ansd;
        ansd -= (long long)ansd;
        now = 0;
      } else {
        ansll += snow[pos].c;
        now -= snow[pos].w;
      }
    }
    for (int j = 0; j < m; j++) snow[j].c -= snow[j].a;
  }
  ansd += ansll % 10;
  ansll /= 10;
  if (ansll > 0) cout << ansll;
  double tmp = (double)ansd;
  printf("%.15f\n", tmp);
  return 0;
}
