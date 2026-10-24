#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, m;
long long seed, vmax, num[100005];
struct Node {
  int l, r;
  mutable long long v;
  Node(int L, int R = -1, long long V = 0) : l(L), r(R), v(V) {}
  bool operator<(const Node &x) const { return l < x.l; }
};
set<Node> s;
long long rnd() {
  long long ret = seed;
  seed = (seed * 7ll + 13ll) % mod;
  return ret;
}
long long ksm(long long x, long long y, long long m) {
  long long ret = 1ll, base = x % m;
  while (y) {
    if (y & 1) ret = (ret * base) % m;
    base = (base * base) % m;
    y >>= 1ll;
  }
  return ret % m;
}
set<Node>::iterator split(int pos) {
  set<Node>::iterator it = s.lower_bound((Node){pos});
  if (it != s.end() && it->l == pos) return it;
  --it;
  int L = it->l, R = it->r;
  long long V = it->v;
  s.erase(it);
  s.insert(Node(L, pos - 1, V));
  return s.insert((Node){pos, R, V}).first;
}
void assign(int l, int r, long long val) {
  set<Node>::iterator itr = split(r + 1), itl = split(l);
  s.erase(itl, itr);
  s.insert((Node){l, r, val});
  return;
}
void add(int l, int r, long long val) {
  set<Node>::iterator itr = split(r + 1), itl = split(l);
  for (register set<Node>::iterator it = itl; it != itr; it++) {
    it->v += val;
  }
  return;
}
long long rankx(int l, int r, int x) {
  int k = x;
  vector<pair<long long, int> > vp;
  vp.clear();
  set<Node>::iterator itr = split(r + 1), itl = split(l);
  for (register set<Node>::iterator it = itl; it != itr; it++) {
    vp.push_back(pair<long long, int>(it->v, it->r - it->l + 1));
  }
  sort(vp.begin(), vp.end());
  for (register vector<pair<long long, int> >::iterator it = vp.begin();
       it != vp.end(); it++) {
    k -= it->second;
    if (k <= 0) return it->first;
  }
  return -1ll;
}
long long sump(int l, int r, int x, int y) {
  long long ret = 0;
  set<Node>::iterator itr = split(r + 1), itl = split(l);
  for (register set<Node>::iterator it = itl; it != itr; it++) {
    ret = (ret + (long long)(it->r - it->l + 1) *
                     ksm(it->v, (long long)x, (long long)y)) %
          y;
  }
  return ret;
}
void init() {
  scanf("%d%d%lld%lld", &n, &m, &seed, &vmax);
  for (register int i = 1; i <= n; i++) {
    num[i] = (rnd() % vmax) + 1;
    s.insert(Node(i, i, num[i]));
  }
  s.insert(Node(n + 1, n + 1, 0));
  return;
}
void solve() {
  int opt, l, r, x, y;
  for (register int i = 1; i <= m; i++) {
    opt = int(rnd() % 4) + 1;
    l = int(rnd() % n) + 1;
    r = int(rnd() % n) + 1;
    if (l > r) swap(l, r);
    if (opt == 3)
      x = int(rnd() % (r - l + 1)) + 1;
    else
      x = int(rnd() % vmax) + 1;
    if (opt == 4) y = int(rnd() % vmax) + 1;
    if (opt == 1) {
      add(l, r, (long long)x);
    } else if (opt == 2) {
      assign(l, r, (long long)x);
    } else if (opt == 3) {
      printf("%lld\n", rankx(l, r, x));
    } else if (opt == 4) {
      printf("%lld\n", sump(l, r, x, y));
    }
  }
  return;
}
int main() {
  init();
  solve();
  return 0;
}
