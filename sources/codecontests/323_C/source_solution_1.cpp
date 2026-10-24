#include <bits/stdc++.h>
using namespace std;
int arr[1 << 20];
int it[22][1 << 20];
int pos[1 << 20];
int LOW, UP;
void makeTree(int l, int r, int lvl) {
  if (l == r) {
    it[lvl][l] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  makeTree(l, mid, lvl + 1);
  makeTree(mid + 1, r, lvl + 1);
  merge(it[lvl + 1] + l, it[lvl + 1] + mid + 1, it[lvl + 1] + mid + 1,
        it[lvl + 1] + r + 1, it[lvl] + l);
}
int query(int l, int r, int lvl, int f, int t) {
  if (l > t || r < f) return 0;
  if (l >= f && r <= t) {
    int *lw = lower_bound(it[lvl] + l, it[lvl] + r + 1, LOW);
    int *up = upper_bound(it[lvl] + l, it[lvl] + r + 1, UP);
    return up - lw;
  }
  int mid = (l + r) / 2;
  return query(l, mid, lvl + 1, f, t) + query(mid + 1, r, lvl + 1, f, t);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pos[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = pos[arr[i]];
  }
  makeTree(1, n, 0);
  x = 0;
  int q;
  cin >> q;
  int a, b, c, d;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c >> d;
    a = (a - 1 + x) % n + 1;
    b = (b - 1 + x) % n + 1;
    if (a > b) swap(a, b);
    c = (c - 1 + x) % n + 1;
    d = (d - 1 + x) % n + 1;
    if (c > d) swap(c, d);
    LOW = a;
    UP = b;
    x = query(1, n, 0, c, d);
    cout << x << endl;
    x++;
  }
  return 0;
}
