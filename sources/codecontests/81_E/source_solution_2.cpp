#include <bits/stdc++.h>
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ios_base;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::nth_element;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;
struct __Timestamp {
  ~__Timestamp() {}
} __timestamp;
template <typename T>
void debug(T t) {}
template <typename T, typename... Args>
void debug(T t, Args... args) {}
struct Match {
  int sz, x;
  Match(int sz = 0, int x = 0) : sz(sz), x(x) {}
  Match& operator+=(const Match& o) {
    sz += o.sz;
    x += o.x;
    return *this;
  }
  Match& operator-=(const Match& o) {
    sz -= o.sz;
    x -= o.x;
    return *this;
  }
  Match operator+(const Match& o) const { return {sz + o.sz, x + o.x}; }
  Match operator-(const Match& o) const { return {sz - o.sz, x - o.x}; }
  bool operator>(const Match& o) const {
    if (sz != o.sz) return sz > o.sz;
    return x > o.x;
  }
  bool operator<(const Match& o) const { return o > *this; }
};
const int N = 100005;
int n;
set<int> g[N];
int s[N];
int col[N], cycle[N];
Match dp[N][2];
int mt[N];
vector<int> ans;
bool dfs0(int v, int p, int& c) {
  col[v] = 1;
  for (int u : g[v]) {
    if (u == p || col[u] == 2) continue;
    if (col[u] == 1 || dfs0(u, v, c)) {
      debug("+", v, u, c, '\n');
      col[v] = 2;
      cycle[u] |= c;
      c &= !cycle[v];
      return true;
    }
  }
  col[v] = 2;
  return false;
}
void dfs1(int v) {
  col[v] = 3;
  for (int u : g[v])
    if (col[u] != 3) dfs1(u);
}
void dfs(int v, int p) {
  dp[v][0] = {0, 0};
  dp[v][1] = {0, 0};
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
    dp[v][0] += std::max(dp[u][0], dp[u][1]);
  }
  for (int u : g[v]) {
    if (u == p) continue;
    auto x = dp[v][0] - std::max(dp[u][0], dp[u][1]) + dp[u][0] +
             Match{1, s[u] != s[v]};
    if (x > dp[v][1]) {
      dp[v][1] = x;
      mt[v] = u;
    }
  }
}
void get_matching(int v, int p, int tp, vector<int>& res) {
  for (int u : g[v]) {
    if (u == p) continue;
    if (tp && u == mt[v]) {
      res.push_back(v);
      res.push_back(mt[v]);
      get_matching(u, v, 0, res);
    } else {
      get_matching(u, v, dp[u][1] > dp[u][0], res);
    }
  }
}
vector<int> solve(int v) {
  dfs(v, -1);
  debug('?', dp[v][0].sz, dp[v][0].x, dp[v][1].sz, dp[v][1].x, '\n');
  vector<int> res;
  get_matching(v, -1, dp[v][1] > dp[v][0], res);
  return res;
}
pair<int, int> evaluate(const vector<int>& v) {
  int cc = 0;
  for (int i = 0; i < (int)v.size(); i += 2) {
    cc += s[v[i]] != s[v[i + 1]];
  }
  return {v.size(), cc};
}
void add(const vector<int>& v) {
  for (auto& u : v) ans.push_back(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    int v;
    cin >> v >> s[i];
    g[i].insert(--v);
    g[v].insert(i);
  }
  for (int i = 0; i < (int)(n); i++) {
    if (!col[i]) {
      int c = 1;
      dfs0(i, -1, c);
    }
  }
  for (int v = 0; v < (int)(n); v++) {
    if (!cycle[v] || col[v] == 3) continue;
    vector<int> uu;
    for (int u : g[v]) {
      debug("!!!", v, u, cycle[u], '\n');
      if (uu.size() < 2 && cycle[u]) uu.push_back(u);
    }
    vector<int> res[2];
    for (int i = 0; i < (int)(2); i++) {
      int u = uu[i];
      g[v].erase(u);
      g[u].erase(v);
      res[i] = solve(v);
      g[v].insert(u);
      g[u].insert(v);
    }
    debug('!', v, uu[0], uu[1], res[0].size(), res[1].size(), '\n');
    if (evaluate(res[0]) < evaluate(res[1])) {
      std::swap(res[0], res[1]);
    }
    add(res[0]);
    dfs1(v);
  }
  for (int v = 0; v < (int)(n); v++) {
    if (col[v] == 3) continue;
    add(solve(v));
    dfs1(v);
  }
  auto x = evaluate(ans);
  cout << x.first / 2 << ' ' << x.second << '\n';
  for (int i = 0; i < (int)ans.size(); i += 2) {
    cout << ans[i] + 1 << ' ' << ans[i + 1] + 1 << '\n';
  }
  return 0;
}
