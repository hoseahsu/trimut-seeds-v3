#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100, md = 1e9 + 7;
long long add[maxn * 4], seg[maxn * 4], lazy1[maxn * 4], lazy2[maxn * 4];
vector<int> adj[maxn];
int hgt[maxn], ftm[maxn], stm[maxn], n, type, tm, q;
void dfs(int v, int h) {
  stm[v] = tm++;
  hgt[v] = h;
  for (int i = 0; i < (int)adj[v].size(); i++) dfs(adj[v][i], h + 1);
  ftm[v] = tm;
}
void add_num(int fi, int se, long long val1, long long val2, int be, int en,
             int ind) {
  if (fi >= en || se <= be) return;
  if (fi <= be && en <= se) {
    lazy1[ind] = 1ll * (lazy1[ind] + val1) % md;
    lazy2[ind] = 1ll * (lazy2[ind] + val2) % md;
    return;
  }
  int mid = (be + en) / 2;
  add_num(fi, se, val1, val2, be, mid, ind * 2 + 1);
  add_num(fi, se, val1, val2, mid, en, ind * 2 + 2);
}
int get_ans(int id, int be, int en, int ind) {
  if (id < be || id >= en) return -1;
  if (en - be <= 1) {
    add[ind] = (add[ind] + lazy1[ind]) % md;
    lazy1[ind] = 0;
    seg[ind] = (seg[ind] + lazy2[ind]) % md;
    lazy2[ind] = 0;
    return ind;
  }
  int mid = (be + en) / 2;
  lazy1[ind * 2 + 1] += lazy1[ind];
  lazy1[ind * 2 + 2] += lazy1[ind];
  add[ind] += lazy1[ind];
  lazy1[ind] = 0;
  lazy2[ind * 2 + 1] += lazy2[ind];
  lazy2[ind * 2 + 2] += lazy2[ind];
  seg[ind] += lazy2[ind];
  lazy2[ind] = 0;
  lazy1[ind * 2 + 1] %= md;
  lazy1[ind * 2 + 2] %= md;
  add[ind] %= md;
  lazy2[ind * 2 + 1] %= md;
  lazy2[ind * 2 + 2] %= md;
  seg[ind] %= md;
  int ret1 = get_ans(id, be, mid, ind * 2 + 1);
  int ret2 = get_ans(id, mid, en, ind * 2 + 2);
  return max(ret1, ret2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int a, v, type;
  long long x, k;
  for (int i = 1; i < n; i++) {
    cin >> a;
    adj[--a].push_back(i);
  }
  dfs(0, 0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> type;
    if (type == 1) {
      cin >> v >> x >> k;
      v--;
      add_num(stm[v], ftm[v], 1ll * (x + (1ll * hgt[v] * k % md)) % md, k, 0,
              maxn, 0);
    }
    if (type == 2) {
      cin >> v;
      v--;
      int pl = get_ans(stm[v], 0, maxn, 0);
      cout << (1ll * (add[pl] + md) - ((1ll * hgt[v] * seg[pl]) % md)) % md
           << endl;
    }
  }
  return 0;
}
