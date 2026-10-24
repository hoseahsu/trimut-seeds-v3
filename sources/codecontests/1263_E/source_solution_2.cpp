#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int sum, max_sum, left_sum, right_sum;
  int op, cl;
};
vector<node> seg(4 * 1000005);
void assign(node &a, int val) {
  a.sum = a.max_sum = a.left_sum = a.right_sum = val;
  a.op = a.cl = 0;
  if (val > 0)
    a.op = 1;
  else if (val < 0)
    a.cl = 1;
}
node combine(node a, node b) {
  node c;
  c.sum = a.sum + b.sum;
  c.left_sum = max(a.left_sum, a.sum + b.left_sum);
  c.right_sum = max(a.right_sum + b.sum, b.right_sum);
  c.max_sum = max({a.max_sum, b.max_sum, a.right_sum + b.left_sum});
  int x = min(a.op, b.cl);
  c.op = a.op + b.op - x;
  c.cl = a.cl + b.cl - x;
  return c;
}
void build(int pos = 0, int l = 0, int r = n - 1) {
  if (l == r) {
    assign(seg[pos], (int)0);
    return;
  }
  int mid = (l + r) / 2;
  build(2 * pos + 1, l, mid);
  build(2 * pos + 2, mid + 1, r);
  seg[pos] = combine(seg[2 * pos + 1], seg[2 * pos + 2]);
}
void update(int x, int y, int v, int pos = 0, int l = 0, int r = n - 1) {
  if (x > r || y < l) return;
  if (x <= l && y >= r) {
    assign(seg[pos], v);
    return;
  }
  int mid = (l + r) / 2;
  update(x, y, v, 2 * pos + 1, l, mid);
  update(x, y, v, 2 * pos + 2, mid + 1, r);
  seg[pos] = combine(seg[2 * pos + 1], seg[2 * pos + 2]);
}
node query(int x, int y, int pos = 0, int l = 0, int r = n - 1) {
  if (x > r || y < l) return {0, 0, 0, 0, 0, 0};
  if (x <= l && y >= r) return seg[pos];
  int mid = (l + r) / 2;
  return combine(query(x, y, 2 * pos + 1, l, mid),
                 query(x, y, 2 * pos + 2, mid + 1, r));
}
void solve() {
  cin >> n;
  int a[n], prev = 0, ans = 0;
  memset(a, 0, sizeof(a));
  string str;
  cin >> str;
  int i, idx = 0;
  build();
  for (i = 0; i < n; i++) {
    bool change = false;
    if (str[i] == '(') {
      if (a[idx] != 1) update(idx, idx, (int)1), change = true, a[idx] = 1;
    } else if (str[i] == ')') {
      if (a[idx] != -1) update(idx, idx, (int)-1), change = true, a[idx] = -1;
    } else if (str[i] == 'R')
      idx++;
    else if (str[i] == 'L')
      idx = max((int)0, idx - 1);
    else {
      if (a[idx] != 0) update(idx, idx, (int)0), change = true, a[idx] = 0;
    }
    ans = prev;
    if (change) {
      node x = query(0, n - 1);
      if (x.sum == 0 && x.op + x.cl == 0)
        ans = x.max_sum;
      else
        ans = -1;
    }
    prev = ans;
    cout << ans << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
