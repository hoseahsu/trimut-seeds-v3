#include <bits/stdc++.h>
using namespace std;
struct Node {
  int vals[11][11];
  pair<int, int> lazy, va;
  void reset() {
    memset(vals, 0, sizeof(vals));
    lazy = pair<int, int>(-1, 0);
  }
};
Node tree[200000 * 3], empt;
bool present[11][11];
Node sum(Node l, Node r) {
  Node ret;
  for (int i = int(0); i < int(11); i++) {
    for (int j = int(0); j < int(11); j++) {
      ret.vals[i][j] = l.vals[i][j] + r.vals[i][j];
    }
  }
  ret.vals[l.va.second][r.va.first]++;
  ret.va = pair<int, int>(l.va.first, r.va.second);
  ret.lazy.first = -1;
  return ret;
}
Node upd(int n, int l, int r, int c, int d) {
  if (tree[n].lazy.first != -1) {
    pair<int, int> te = tree[n].lazy;
    te.second >>= 1;
    if (d > 1) tree[n << 1].lazy = tree[n << 1 | 1].lazy = te;
    tree[n].va = pair<int, int>(te.first, te.first);
    tree[n].reset();
  }
  if (l > r) return empt;
  if (!l && r == d - 1) {
    tree[n].reset();
    if (d > 1)
      tree[n << 1].lazy = tree[n << 1 | 1].lazy = pair<int, int>(c, d / 2);
    tree[n].va = pair<int, int>(c, c);
    return tree[n];
  }
  d /= 2;
  upd(n << 1, l, min(d - 1, r), c, d);
  upd(n << 1 | 1, max(0, l - d), r - d, c, d);
  return tree[n] = sum(tree[n << 1], tree[n << 1 | 1]);
}
Node getVal(int n, int l, int r, int d) {
  if (tree[n].lazy.first != -1) {
    pair<int, int> te = tree[n].lazy;
    te.second >>= 1;
    if (d > 1) tree[n << 1].lazy = tree[n << 1 | 1].lazy = te;
    tree[n].va = pair<int, int>(te.first, te.first);
    tree[n].reset();
  }
  if (l > r) return empt;
  if (!l && r == d - 1) {
    return tree[n];
  }
  d /= 2;
  return sum(getVal(n << 1, l, min(d - 1, r), d),
             getVal(n << 1 | 1, max(0, l - d), r - d, d));
}
int main() {
  empt.reset();
  empt.va = pair<int, int>(11 - 1, 11 - 1);
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  int n, m, k, t, l, r, start;
  char c;
  string s, s2;
  while (cin >> n >> m >> k) {
    start = 1 << (int)ceil(log2(n));
    cin >> s;
    for (int i = int(0); i < int(2 * start); i++) {
      tree[i].reset();
    }
    for (int i = int(0); i < int(s.length()); i++) {
      tree[start + i].va = pair<int, int>(s[i] - 'a', s[i] - 'a');
    }
    for (int i = int(s.length() + start); i < int(2 * start); i++) {
      tree[i].va = pair<int, int>(11 - 1, 11 - 1);
    }
    for (int i = int(1); i < int(start); i++) {
      int j = start - i;
      tree[j] = sum(tree[j << 1], tree[j << 1 | 1]);
    }
    for (int i = int(0); i < int(m); i++) {
      cin >> t;
      if (t == 1) {
        cin >> l >> r >> c;
        upd(1, l - 1, r - 1, c - 'a', start);
      } else {
        cin >> s2;
        Node temp = getVal(1, 0, n - 1, start);
        int ans = n, sum = 0;
        memset(present, false, sizeof(present));
        for (int i = int(0); i < int(s2.length()); i++) {
          for (int j = int(i + 1); j < int(s2.length()); j++) {
            present[s2[i] - 'a'][s2[j] - 'a'] = true;
          }
        }
        for (int i = int(0); i < int(11); i++) {
          for (int j = int(0); j < int(11); j++) {
            if (present[i][j]) ans -= temp.vals[i][j];
          }
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}
