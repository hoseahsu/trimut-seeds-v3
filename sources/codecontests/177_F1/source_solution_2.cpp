#include <bits/stdc++.h>
using namespace std;
vector<int> v[22], c[22];
int n, k, t;
struct node {
  int state;
  int val;
  int lst;
  int now;
  node(int a = 0, int b = 0, int c = 0, int d = 0) {
    state = a, val = b, lst = c, now = d;
  }
  void spread(priority_queue<node> &pq) {
    if (now == n) return;
    for (int i = 0; i < v[now].size(); i++) {
      int j = v[now][i];
      if ((1 << j) & state) continue;
      pq.push(node((1 << j) | state, val + c[now][i], 1, now + 1));
    }
    pq.push(node(state, val, 0, now + 1));
  }
};
bool operator<(node a, node b) { return a.val > b.val; }
priority_queue<node> pq;
int main() {
  scanf("%d%d%d", &n, &k, &t);
  while (k--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--, y--;
    v[x].push_back(y);
    c[x].push_back(w);
  }
  pq.push(node(0, 0, 1, 0));
  while (1) {
    node nr = pq.top();
    pq.pop();
    nr.spread(pq);
    t -= nr.lst;
    if (t == 0) {
      printf("%d\n", nr.val);
      return 0;
    }
  }
  puts("CYKA BLYAT!");
}
