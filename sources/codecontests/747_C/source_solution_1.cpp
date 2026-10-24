#include <bits/stdc++.h>
using namespace std;
struct Server {
  bool is_free;
  int free_at;
  Server(int t, int d, bool isf) {
    is_free = isf;
    free_at = t + d;
  }
  Server() : Server(0, 0, true) {}
};
int n, q;
Server ss[105];
int read() {
  if (scanf("%d %d", &n, &q) < 2) {
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    ss[i] = Server();
  }
  return 1;
}
void solve() {
  int init_t, need_free, dur;
  for (int qq = 0; qq < q; qq++) {
    scanf("%d %d %d", &init_t, &need_free, &dur);
    int have_free = 0;
    for (int i = 1; i <= n; i++) {
      if (ss[i].is_free || ss[i].free_at <= init_t) have_free++;
    }
    if (need_free <= have_free) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        if (need_free > 0 && (ss[i].is_free || ss[i].free_at <= init_t)) {
          ss[i] = Server(init_t, dur, false);
          sum += i;
          need_free--;
        }
      }
      printf("%d\n", sum);
    } else {
      printf("-1\n");
    }
  }
}
int main(int argc, char *argv[]) {
  while (read()) {
    solve();
  }
}
