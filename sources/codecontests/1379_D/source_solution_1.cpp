#include <bits/stdc++.h>
using namespace std;
const int N = 200000, INF = (1 << 30) - 1;
int n, m, sk, a[N + 9];
struct thing {
  int t, id;
  thing(int T = 0, int Id = 0) {
    t = T;
    id = Id;
  }
};
vector<thing> ord;
void into() {
  int x;
  scanf("%d%d%d%d", &n, &x, &sk, &m);
  sk >>= 1;
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d%d", &x, &t);
    t %= sk;
    ord.emplace_back(t, i);
    ord.emplace_back(t + sk, i);
  }
}
int ans, val;
void Get_ans() {
  sort(ord.begin(), ord.end(), [&](const thing &a, const thing &b) {
    return a.t < b.t || a.t == b.t && a.id < b.id;
  });
  val = INF;
  for (int i = 0, j = 0; i < n << 1; ++i) {
    for (; ord[j].t + m <= ord[i].t; ++j)
      ;
    if (i >= n && i - j < val) ans = ord[i].t, val = i - j;
  }
}
void work() { Get_ans(); }
void outo() {
  printf("%d %d\n", val, ans % sk);
  for (int i = 0; i < n << 1; ++i) {
    int l = ans - m, r = ans;
    if (l < ord[i].t && ord[i].t < r) printf("%d ", ord[i].id);
  }
  puts("");
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
