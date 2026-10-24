#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <class T>
auto add = [](T a, T b) -> T { return a + b; };
template <class T>
auto f_max = [](T a, T b) -> T { return max(a, b); };
template <class T>
auto f_min = [](T a, T b) -> T { return min(a, b); };
template <class T>
using V = vector<T>;
using Vl = V<long long int>;
using VVl = V<Vl>;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& in : v) is >> in;
  return is;
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }
long long int digit(long long int a) { return (long long int)log10(a); }
long long int e_dist(pair<long long int, long long int> a,
                     pair<long long int, long long int> b) {
  return abs(a.first - b.first) * abs(a.first - b.first) +
         abs(a.second - b.second) * abs(a.second - b.second);
}
long long int m_dist(pair<long long int, long long int> a,
                     pair<long long int, long long int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
void Worshall_Floyd(VVl& g) {
  for (long long int k = (0), k_end_ = (((long long int)(g).size()));
       k < k_end_; ++k)
    for (long long int i = (0), i_end_ = (((long long int)(g).size()));
         i < i_end_; ++i)
      for (long long int j = (0), j_end_ = (((long long int)(g).size()));
           j < j_end_; ++j)
        chmin(g[i][j], g[i][k] + g[k][j]);
}
const long long int MOD1000000007 = 1000000007, MOD998244353 = 998244353,
                    INF = 1e18;
long long int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1},
              dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
bool YN(bool flag) {
  cout << (flag ? "YES" : "NO") << '\n';
  return flag;
}
bool yn(bool flag) {
  cout << (flag ? "Yes" : "No") << '\n';
  return flag;
}
struct Edge {
  long long int from, to;
  long long int cost;
  Edge(long long int u, long long int v, long long int c) {
    cost = c;
    from = u;
    to = v;
  }
  bool operator<(const Edge& e) const { return cost < e.cost; }
};
struct WeightedEdge {
  long long int to;
  long long int cost;
  WeightedEdge(long long int v, long long int c = 1) {
    to = v;
    cost = c;
  }
  bool operator<(const WeightedEdge& e) const { return cost < e.cost; }
};
using WeightedGraph = V<V<WeightedEdge>>;
long long int N, M;
int main() {
  cin >> N >> M;
  Vl arr(N), P(M);
  cin >> arr >> P;
  Vl dist(N - 1);
  for (long long int i = (0), i_end_ = (N - 1); i < i_end_; ++i) {
    dist[i] = arr[i + 1] - arr[i];
  }
  long long int _gcd = dist[0];
  for (long long int i = (0), i_end_ = (N - 1); i < i_end_; ++i)
    _gcd = gcd(_gcd, dist[i]);
  for (long long int i = (0), i_end_ = (M); i < i_end_; ++i) {
    if (_gcd % P[i] == 0) {
      YN(true);
      cout << arr[0] << " " << i + 1 << '\n';
      return 0;
    }
  }
  YN(false);
}
