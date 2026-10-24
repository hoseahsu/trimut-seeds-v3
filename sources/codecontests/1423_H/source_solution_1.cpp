#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<pair<int, int> > vec[N * 4];
int fa[N], siz[N];
int finds(int x) { return x == fa[x] ? x : finds(fa[x]); }
void merge(int x, int y, stack<pair<int, int> >& st) {
  int fax = finds(x), fay = finds(y);
  if (fax == fay) return;
  if (siz[fax] < siz[fay]) swap(fax, fay);
  siz[fax] += siz[fay];
  fa[fay] = fax;
  st.push({fax, fay});
}
void del(stack<pair<int, int> >& st) {
  while (!st.empty()) {
    int fax = st.top().first, fay = st.top().second;
    st.pop();
    siz[fax] -= siz[fay];
    fa[fay] = fay;
  }
}
void update(int l, int r, int root, int ql, int qr, pair<int, int> v) {
  if (l >= ql && r <= qr) {
    vec[root].push_back(v);
    return;
  }
  int mid = l + r >> 1;
  if (mid >= ql) update(l, mid, root << 1, ql, qr, v);
  if (mid < qr) update(mid + 1, r, root << 1 | 1, ql, qr, v);
}
struct node {
  int op, x, y;
} q[N];
int ans[N];
void dfs(int l, int r, int root) {
  stack<pair<int, int> > st;
  for (auto i : vec[root]) merge(i.first, i.second, st);
  if (l == r) {
    if (q[l].op == 2) printf("%d\n", siz[finds(q[l].x)]);
    del(st);
    return;
  }
  int mid = l + r >> 1;
  dfs(l, mid, root << 1);
  dfs(mid + 1, r, root << 1 | 1);
  del(st);
}
int en[N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  int d = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &q[i].op);
    if (q[i].op == 1)
      scanf("%d%d", &q[i].x, &q[i].y);
    else if (q[i].op == 2)
      scanf("%d", &q[i].x);
    else
      d++;
    en[d] = i;
  }
  int now = 1;
  for (int i = 1; i <= m; i++) {
    if (q[i].op == 1)
      update(1, m, 1, i, en[min(d, now + k - 1)], {q[i].x, q[i].y});
    else if (q[i].op == 3)
      now++;
  }
  dfs(1, m, 1);
  return 0;
}
