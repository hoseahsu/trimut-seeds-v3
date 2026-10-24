#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { cin >> x; }
void _R(int64_t &x) { cin >> x; }
void _R(double &x) { cin >> x; }
void _R(long double &x) { cin >> x; }
void _R(char &x) { cin >> x; }
void _R(char *x) { cin >> x; }
void _R(string &x) { cin >> x; }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { cout << x; }
void _W(const int64_t &x) { cout << x; }
void _W(const double &x) { cout << fixed << setprecision(8) << x; }
void _W(const long double &x) { cout << fixed << setprecision(16) << x; }
void _W(const char &x) { cout << x; }
void _W(const char *x) { cout << x; }
void _W(const string &x) { cout << x; }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  cout << ' ';
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << (sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int N = 1e5 + 10;
const int lgn = 20;
vector<pair<int, int> > g[N];
int ances[N][lgn + 1], tin[N], tout[N], color[N], forest[N], n, q, f, s, t, a,
    b, c, d, e, timer;
pair<int, int> data[N][lgn + 1];
void dfs(int r, int p = -1, int wt = -1) {
  color[r] = 1;
  forest[r] = f;
  tin[r] = timer++;
  if (p == -1) {
    data[r][0] = {0, 0};
    ances[r][0] = r;
  } else {
    data[r][0] = make_pair(wt == 0, wt == 1);
    ances[r][0] = p;
  }
  for (auto to : g[r]) {
    if (to.first == p) continue;
    if (color[to.first] == 0) {
      dfs(to.first, r, to.second);
    }
  }
  tout[r] = timer++;
  color[r] = 2;
}
bool is_ances(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (is_ances(a, b)) {
    return a;
  }
  if (is_ances(b, a)) {
    return b;
  }
  for (int j = (lgn); j > (-1); j--) {
    if (!is_ances(ances[a][j], b)) {
      a = ances[a][j];
    }
  }
  return ances[a][0];
}
pair<int, int> solve(int u, int v) {
  pair<int, int> d = {0, 0};
  for (int j = (lgn); j > (-1); j--) {
    if (!is_ances(ances[v][j], u) || ances[v][j] == u) {
      d.first += data[v][j].first;
      d.second += data[v][j].second;
      v = ances[v][j];
    }
  }
  return d;
}
void solve() {
  R(n);
  int pi, ti;
  vector<int> roots;
  for (int i = (1); i < (n + 1); i++) {
    R(pi, ti);
    if (pi == -1 && ti == -1) {
      roots.emplace_back(i);
    } else {
      g[pi].emplace_back(make_pair(i, ti));
    }
  }
  for (auto r : roots) {
    dfs(r, -1);
    f++;
  }
  for (int j = (1); j < (lgn + 1); j++) {
    for (int i = (1); i < (n + 1); i++) {
      ances[i][j] = ances[ances[i][j - 1]][j - 1];
      pair<int, int> p1 = data[i][j - 1];
      pair<int, int> p2 = data[ances[i][j - 1]][j - 1];
      data[i][j] = {p1.first + p2.first, p1.second + p2.second};
    }
  }
  R(q);
  for (int i = (1); i < (q + 1); i++) {
    int ti, u, v;
    R(ti, u, v);
    if (ti == 1) {
      if (forest[u] != forest[v] || u == v) {
        W("NO");
      } else {
        int w = lca(u, v);
        if (w != u) {
          W("NO");
        } else {
          pair<int, int> data = solve(u, v);
          if (data.second == 0) {
            W("YES");
          } else {
            W("NO");
          }
        }
      }
    } else {
      if (forest[u] != forest[v] || u == v) {
        W("NO");
      } else {
        int w = lca(u, v);
        pair<int, int> data1 = solve(w, u);
        pair<int, int> data2 = solve(w, v);
        if (data1.second == 0 && data2.first == 0 && w != v) {
          W("YES");
        } else {
          W("NO");
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}
