#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MAXN = 20010;
const int MAXK = 110;
int N, K;
int A[MAXN];
int ord[MAXN];
int lo[MAXN], hi[MAXN];
struct line {
  int k, b;
  line() {}
  line(int k_, int b_) : k(k_), b(b_) {}
  int eval(int x) const { return k * x + b; }
};
bool bad(const line& a, const line& b, const line& c) {
  return ll(b.b - a.b) * (b.k - c.k) <= ll(c.b - b.b) * (a.k - b.k);
}
void insert_hull(vector<line>& hull, const line& l) {
  while (hull.size() >= 2 && bad(hull.end()[-2], hull.end()[-1], l)) {
    hull.pop_back();
  }
  if (hull.size()) assert(l.k >= hull.back().k);
  hull.push_back(l);
}
int get_min(vector<line>& hull, int x) {
  if (hull.empty()) {
    return INF;
  }
  while (hull.size() >= 2 && hull.back().eval(x) >= hull.end()[-2].eval(x)) {
    hull.pop_back();
  }
  return hull.back().eval(x);
}
vector<line> segg[2 * MAXN];
void update_g(int a, const line& l) {
  for (a += N + 1; a >= 1; a /= 2) {
    insert_hull(segg[a], l);
  }
}
int query_g(int a, int b, int x) {
  int res = INF;
  for (a += N + 1, b += N + 1; a < b; a /= 2, b /= 2) {
    if (a & 1) {
      res = min(res, get_min(segg[a], x));
      a++;
    }
    if (b & 1) {
      b--;
      res = min(res, get_min(segg[b], x));
    }
  }
  return res;
}
vector<line> segdp[2 * MAXN];
void update_dp(int a, int b, const line& l) {
  for (a += N + 1, b += N + 1; a < b; a /= 2, b /= 2) {
    if (a & 1) {
      insert_hull(segdp[a], l);
      a++;
    }
    if (b & 1) {
      b--;
      insert_hull(segdp[b], l);
    }
  }
}
int query_dp(int a, int x) {
  int res = INF;
  for (a += N + 1; a >= 1; a /= 2) {
    res = min(res, get_min(segdp[a], x));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  iota(ord, ord + N + 1, 0);
  sort(ord, ord + N + 1, [&](int i, int j) { return A[i] < A[j]; });
  vector<int> st;
  for (int i = 0; i <= N; i++) {
    while (st.size() && A[i] >= A[st.back()]) st.pop_back();
    if (st.size()) {
      lo[i] = st.back();
    } else {
      lo[i] = 0;
    }
    st.push_back(i);
  }
  A[N + 1] = INF;
  st = {N + 1};
  for (int i = N; i >= 1; i--) {
    while (A[i] >= A[st.back()]) st.pop_back();
    hi[i] = st.back();
    st.push_back(i);
  }
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  for (int k = 0; k < K; k++) {
    for (int i = 1; i < 2 * (N + 1); i++) {
      vector<line>().swap(segg[i]);
      vector<line>().swap(segdp[i]);
    }
    for (int i = 0; i <= N; i++) {
      if (dp[i] != INF) {
        update_g(i, line(i, dp[i]));
      }
    }
    vector<int> vals(N + 1);
    for (int o = N; o >= 0; o--) {
      int i = ord[o];
      vals[o] = min(INF, query_g(lo[i], i, -A[i]));
    }
    for (int o = 0; o <= N; o++) {
      int i = ord[o];
      update_dp(i, hi[i], line(A[i], vals[o]));
    }
    for (int o = 1; o <= N; o++) {
      assert(-A[ord[o - 1]] >= -A[ord[o]]);
    }
    vector<int> ndp(N + 1);
    for (int i = 0; i <= N; i++) {
      ndp[i] = min(INF, query_dp(i, i));
    }
    swap(dp, ndp);
  }
  cout << dp[N] << '\n';
  return 0;
}
