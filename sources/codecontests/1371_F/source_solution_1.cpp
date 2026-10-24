#include <bits/stdc++.h>
using namespace std;
struct T {
  int lz, sz;
  int v[2], t[2], f1[2], f2[2];
  T(int x = 1) {
    lz = 0, sz = x;
    for (int i = 0; i < 2; i++) {
      v[i] = f1[i] = x;
      t[i] = f2[i] = 0;
    }
  }
  void upd() {
    for (int i = 0; i < 2; i++) t[i] ^= 1;
    swap(v[0], v[1]);
    lz ^= 1;
  }
  friend T operator+(T l, T r) {
    T ret(0);
    T c[2] = {l, r};
    int first = 0, g = 0;
    for (int i = 0; i < 2; i++) {
      first += c[i].f1[!i];
      g ^= c[i].t[!i];
      ret.sz += c[i].sz;
      ret.t[i] = c[i].t[i];
      for (int j = 0; j < 2; j++) ret.v[j] = max(ret.v[j], c[i].v[j]);
      if (c[i].f1[i] == c[i].sz) {
        if (c[i].t[i] == c[!i].t[i]) {
          ret.f1[i] = c[i].f1[i] + c[!i].f1[i];
          ret.f2[i] = c[!i].f2[i];
        } else {
          ret.f1[i] = c[i].f1[i];
          ret.f2[i] = c[!i].f1[i];
        }
      } else {
        ret.f1[i] = c[i].f1[i];
        ret.f2[i] = c[i].f2[i];
        ret.f2[i] +=
            (ret.f1[i] + ret.f2[i] == c[i].sz && c[i].t[i] != c[!i].t[i]) *
            c[!i].f1[i];
      }
    }
    if (g) {
      ret.v[c[0].t[1]] = max(ret.v[c[0].t[1]], first);
    } else {
      for (int i = 0; i < 2; i++) {
        int j = !i ^ c[i].t[!i];
        ret.v[j] = max(ret.v[j], first + c[i].f2[!i]);
      }
    }
    return ret;
  }
};
struct segTree {
  int l, r;
  segTree *c[2];
  T val;
  segTree(int a, int b) {
    l = a, r = b;
    val.sz = r - l + 1;
    if (l != r) {
      int mid = (l + r) / 2;
      c[0] = new segTree(l, mid);
      c[1] = new segTree(mid + 1, r);
      val = c[0]->val + c[1]->val;
    }
  }
  T add(int a, int b) {
    if (b < l || r < a) return T(0);
    if (a <= l && r <= b) {
      val.upd();
      return val;
    }
    T ret[2];
    for (int i = 0; i < 2; i++) {
      if (val.lz) c[i]->val.upd();
      ret[i] = c[i]->add(a, b);
    }
    val = c[0]->val + c[1]->val;
    return ret[0] + ret[1];
  }
};
const int mxn = 500000;
int n, q;
segTree tre(1, mxn);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '<') tre.add(i, i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << tre.add(l, r).v[0] << '\n';
  }
  return 0;
}
