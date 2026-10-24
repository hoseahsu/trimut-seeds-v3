#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
struct UnionFindTree {
  vector<long long> par, sz;
  UnionFindTree(long long n) {
    par.resize(n);
    sz.resize(n);
    for (long long i = 0; i < n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  long long find(long long x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }
  void unite(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
  }
  bool areSame(long long x, long long y) { return find(x) == find(y); }
  long long size(long long x) { return sz[find(x)]; }
};
const long long SIZE = 1000000;
long long N, M;
long long A[SIZE], B[SIZE];
long long cnt[SIZE];
signed main() {
  scanf("%lld%lld", &N, &M);
  for (long long i = 0; i < (M); i++) scanf("%lld%lld", &A[i], &B[i]);
  vector<long long> vs;
  for (long long i = 0; i < (M); i++) {
    vs.push_back(A[i]);
    vs.push_back(B[i]);
  }
  sort((vs).begin(), (vs).end());
  vs.erase(unique((vs).begin(), (vs).end()), vs.end());
  for (long long i = 0; i < (M); i++) {
    A[i] = lower_bound((vs).begin(), (vs).end(), A[i]) - vs.begin();
    B[i] = lower_bound((vs).begin(), (vs).end(), B[i]) - vs.begin();
  }
  N = vs.size();
  UnionFindTree uf(N);
  for (long long i = 0; i < (M); i++) uf.unite(A[i], B[i]);
  if (uf.size(0) != N) {
    puts("0");
    return 0;
  }
  long long luz = 0;
  for (long long i = 0; i < (M); i++) {
    if (A[i] == B[i])
      luz++;
    else {
      cnt[A[i]]++;
      cnt[B[i]]++;
    }
  }
  long long ans = 0;
  ans += luz * (M - luz);
  ans += luz * (luz - 1) / 2;
  for (long long i = 0; i < N; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
  cout << ans << endl;
  return 0;
}
