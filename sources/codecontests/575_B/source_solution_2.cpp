#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double PI = acos(-1);
template <typename A, typename B>
long long fast_exp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1LL) {
      res *= a;
      res %= 1000000007;
    }
    b >>= 1LL;
    a *= a;
    a %= 1000000007;
  }
  return res;
}
struct node {
  node *p, *jmp[22];
  int id;
  int depth;
  int cnt[3] = {0, 0, 0};
  node(node* _p = NULL, int _id = -1) : p(_p), id(_id) {
    depth = p ? 1 + p->depth : 0;
    memset(jmp, 0, sizeof(jmp));
    jmp[0] = p;
    for (int i = 1; (1 << i) <= depth; i++) {
      jmp[i] = jmp[i - 1]->jmp[i - 1];
    }
  }
};
node* st[200000];
node* lca(node* a, node* b) {
  if (!a || !b) return NULL;
  if (a->depth < b->depth) swap(a, b);
  for (int i = 21; i >= 0; i--) {
    while (a->depth - (1 << i) >= b->depth) {
      a = a->jmp[i];
    }
  }
  if (a == b) return a;
  for (int i = 21; i >= 0; i--) {
    while (a->depth >= (1 << i) && a->jmp[i] != b->jmp[i]) {
      a = a->jmp[i];
      b = b->jmp[i];
    }
  }
  return a->p;
}
int n;
vector<vector<int>> t;
vector<int> stops;
vector<pair<int, int>> s;
void construct(int u, node* p) {
  st[u] = new node(p, u);
  for (int v : t[u]) {
    if (p != NULL and p->id == v) {
      continue;
    }
    construct(v, st[u]);
  }
}
void augment(int u, node* p) {
  for (int v : t[u]) {
    if (p == NULL or p->id != v) {
      augment(v, st[u]);
      for (int i = 0; i < 3; i++) {
        st[u]->cnt[i] += st[v]->cnt[i];
      }
    }
  }
}
signed main(int argc, char* argv[], char* envp[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  cerr << fixed;
  cout << fixed;
  cin >> n;
  t.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    a--, b--;
    t[a].push_back(b);
    t[b].push_back(a);
    if (x != 0) {
      s.push_back({a, b});
    }
  }
  construct(0, NULL);
  int k;
  cin >> k;
  stops.push_back(0);
  for (int i = 0; i < k; i++) {
    int stop;
    cin >> stop;
    stop--;
    if (!stops.empty() and stops.back() == stop) continue;
    stops.push_back(stop);
  }
  k = stops.size();
  for (int i = 0; i < k - 1; i++) {
    int a = stops[i];
    int b = stops[i + 1];
    st[a]->cnt[0] += 1;
    st[b]->cnt[2] += 1;
    lca(st[a], st[b])->cnt[1] += 1;
  }
  augment(0, NULL);
  for (int i = 0; i < n; i++)
    ;
  vector<long long> p2(1000005);
  p2[0] = 1;
  for (int i = 1; i < 1000005; i++) {
    p2[i] = 2LL * p2[i - 1];
    p2[i] %= 1000000007;
  }
  long long ans = 0;
  for (pair<int, int> a : s) {
    int x = a.first;
    int y = a.second;
    long long cnt;
    if (st[x]->depth > st[y]->depth) {
      cnt = st[x]->cnt[2] - st[x]->cnt[1];
    } else {
      assert(st[x]->depth < st[y]->depth);
      cnt = st[y]->cnt[0] - st[y]->cnt[1];
    };
    assert(cnt >= 0);
    ans += (p2[cnt] - 1LL + 1000000007) % 1000000007;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
