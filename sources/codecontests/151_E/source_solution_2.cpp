#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
long long c, n, m;
double x[MAXN];
double p[MAXN], a[MAXN], b[MAXN];
struct node {
  double mx, pre, suf, sum;
  node(double mx, double pre, double suf, double sum) {
    this->mx = mx;
    this->pre = pre;
    this->suf = suf;
    this->sum = sum;
  }
  node() {}
} tree[MAXN * 4];
node mrg(node lc, node rc) {
  node nd = {-1e9, -1e9, -1e9, 0};
  nd.sum = lc.sum + rc.sum;
  nd.mx = max({lc.mx, rc.mx, lc.suf + rc.pre});
  nd.pre = max({lc.pre, lc.sum + rc.pre});
  nd.suf = max({lc.suf + rc.sum, rc.suf});
  return nd;
}
double profit[MAXN];
void build(int pos, int st, int ed) {
  if (st == ed) {
    tree[pos] = node(profit[st], profit[st], profit[st], profit[st]);
    return;
  }
  build(pos * 2, st, (st + ed) / 2);
  build(pos * 2 + 1, (st + ed) / 2 + 1, ed);
  tree[pos] = mrg(tree[pos * 2], tree[pos * 2 + 1]);
}
node query(int pos, int st, int ed, int l, int r) {
  if (st > r || ed < l) return {-1e9, -1e9, -1e9, 0};
  if (st >= l && ed <= r) return tree[pos];
  auto L = query(pos * 2, st, (st + ed) / 2, l, r);
  auto R = query(pos * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
  return mrg(L, R);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n - 1; i++) cin >> p[i];
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= n - 1; i++) {
    double prob = p[i] / 100.0;
    double cst = prob * c;
    double diff = (x[i + 1] - x[i]) / 2.0;
    profit[i] = diff - cst;
  }
  build(1, 1, n - 1);
  cout << fixed << setprecision(11);
  double ans = 0.0;
  for (int i = 1; i <= m; i++) {
    double ret = query(1, 1, n - 1, a[i], b[i] - 1).mx;
    ans += max(ret, 0.0);
  }
  cout << ans;
  return 0;
}
