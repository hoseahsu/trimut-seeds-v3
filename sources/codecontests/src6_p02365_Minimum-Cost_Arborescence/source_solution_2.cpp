// includes {{{
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
// using namespace std;
// using ll = long long;

// #define DEBUG
// #define DEBUG_OUT std::cout

// #undef DEBUG
// #define DEBUG
// DEBUG {{{
#include <array>
#include <deque>
#include <list>
#include <ostream>
#include <queue>
#include <stack>
#include <tuple>
#include <valarray>
#include <vector>
template < int n, class... T >
typename std::enable_if< (n >= sizeof...(T)) >::type __output_tuple(
    std::ostream &, std::tuple< T... > const &) {}
template < int n, class... T >
typename std::enable_if< (n < sizeof...(T)) >::type __output_tuple(
    std::ostream &os, std::tuple< T... > const &t) {
  os << (n == 0 ? "" : ", ") << std::get< n >(t);
  __output_tuple< n + 1 >(os, t);
}
template < class... T >
std::ostream &operator<<(std::ostream &os, std::tuple< T... > const &t) {
  os << "(";
  __output_tuple< 0 >(os, t);
  os << ")";
  return os;
}
template < class T, class U >
std::ostream &operator<<(std::ostream &os, std::pair< T, U > const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template < class T >
std::ostream &operator<<(std::ostream &os, const std::stack< T > &a) {
  os << "{";
  for(auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template < class T, class Container, class Compare >
std::ostream &operator<<(std::ostream &os,
                         std::priority_queue< T, Container, Compare > a) {
  os << "{ (top) ";
  while(a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template < class T, class Container >
std::ostream &operator<<(std::ostream &os, std::queue< T, Container > a) {
  os << "{ ";
  while(a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
#ifdef DEBUG
#if !defined(DEBUG_OUT)
#define DEBUG_OUT std::cerr
#endif
#define dump(...)                                                                \
  [&]() {                                                                        \
    auto __debug_tap = std::make_tuple(__VA_ARGS__);                             \
    DEBUG_OUT << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = " << __debug_tap \
              << std::endl;                                                      \
  }()
template < class T >
inline void dump2D(T &d, size_t sizey, size_t sizex) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << "\t";
    for(size_t j = 0; j < sizex; j++)
      DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t");
    DEBUG_OUT << std::endl;
  }
}
template < class T >
inline void dump1D(T &d, size_t sizey) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << d[i] << (i + 1 == sizey ? "" : " ");
  }
  DEBUG_OUT << std::endl;
}
template <
    class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
    class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
std::ostream &operator<<(std::ostream &os, const T &a) {
  os << "{";
  for(auto ite = begin(a); ite != end(a); ++ite)
    os << (ite == begin(a) ? "" : ", ") << *ite;
  os << "}";
  return os;
}
#else
#define dump(...) (42)
#define dump2D(...) (42)
#define dump1D(...) (42)
template <
    class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
    class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
std::ostream &operator<<(std::ostream &os, const T &a) {
  for(auto ite = begin(a); ite != end(a); ++ite)
    os << (ite == begin(a) ? "" : " ") << *ite;
  return os;
}
#endif
// }}}

// SCC( size )
// SCC( <directed-graph> )
// .add_edge(from, to)
// === .built() ===
//    - O(N)
// .component_size()
// .get_renew() : return directed-graph whose size is .compoent_size()
//    - O(N log N)
// .get_comp_to_vertex() : it[component_id] is vector<size_type>
//    - O(N)
// .topo[i]
// .comp[i] : alias = .[i]
/// --- Strongly Connected Component {{{ ///
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
// Kosaraju's StronglyConnectedComponent
struct StronglyConnectedComponent {
public:
  using size_type = std::size_t;
  using graph_type = std::vector< std::vector< int > >;
  size_type n;
  graph_type graph, rev;
  std::vector< size_type > topo;
  std::vector< size_type > comp;

private:
  std::vector< int > used;
  size_type k;

public:
  StronglyConnectedComponent() : n(0) {}
  StronglyConnectedComponent(size_type n) : n(n), graph(n), rev(n) {}
  StronglyConnectedComponent(graph_type input_graph)
      : StronglyConnectedComponent(input_graph.size()) {
    for(size_type from = 0; from < n; from++)
      for(auto to : input_graph[from]) add_edge(from, to);
  }

private:
  bool built = 0;

public:
  void add_edge(size_type a, size_type b) {
    assert(!built);
    assert(a < n && b < n);
    graph[a].emplace_back(b);
    rev[b].emplace_back(a);
  }
  void build() {
    assert(!built);
    built = 1;
    used.resize(n, 0);
    comp.resize(n, n);
    for(size_type i = 0; i < n; i++)
      if(!used[i]) dfs1(i);
    reverse(topo.begin(), topo.end());
    k = 0;
    for(auto i : topo)
      if(comp[i] == n) dfs2(i), k++;
  }
  graph_type get_renew() {
    assert(built);
    graph_type renew(k);

    std::set< std::pair< size_type, size_type > > connect;
    for(size_type i = 0; i < n; i++) {
      for(auto j : graph[i]) {
        size_type x = comp[i], y = comp[j];
        if(x == y) continue;
        if(connect.count(std::make_pair(x, y))) continue;
        connect.emplace(x, y);
        renew[x].emplace_back(y);
      }
    }
    return renew;
  }
  std::vector< std::vector< size_type > > get_comp_to_vertex() {
    assert(built);
    std::vector< std::vector< size_type > > comp_to_vertex(k, std::vector< size_type >());
    for(size_type i = 0; i < n; i++) comp_to_vertex[comp[i]].emplace_back(i);
    return comp_to_vertex;
  }

  size_type size() const { return n; }
  size_type component_size() const {
    assert(built);
    return k;
  }
  size_type operator[](size_type i) const {
    assert(built);
    return comp.at(i);
  }

private:
  void dfs1(size_type i) {
    if(used[i]) return;
    used[i] = 1;
    for(auto j : graph[i]) dfs1(j);
    topo.emplace_back(i);
  }
  void dfs2(size_type i) {
    if(comp[i] != n) return;
    comp[i] = k;
    for(auto j : rev[i]) dfs2(j);
  }
};
/// }}}--- ///
using SCC = StronglyConnectedComponent;

// require SCC
// MSA( size )
// MSA( <weighted-arborescense> )
// .add_edge(from, to, weight [, id])
// === .build() or .build_with_construct() ===
//    - O(NM), O(NM log N), resp.
//    - returns the sum value
// .get_using_edges()
/// --- Minimum Spanning Arborescense {{{ ///
#include <set>
#include <tuple>
#include <vector>
template < class T >
struct MinimumSpanningArborescense {
public:
  using size_type = StronglyConnectedComponent::size_type;
  using graph_type = StronglyConnectedComponent::graph_type;
  using id_type = int;
  using weighted_graph_type =
      std::vector< std::vector< std::tuple< size_type, T, id_type, id_type > > >;
  using weighted_graph_without_id_type =
      std::vector< std::vector< std::tuple< size_type, T, id_type, id_type > > >;
  size_type n;
  weighted_graph_type graph;
  MinimumSpanningArborescense(size_type n) : n(n), graph(n) {}
  MinimumSpanningArborescense(weighted_graph_without_id_type graph) : n(graph.size()) {
    for(size_type from = 0; from < n; from++) {
      for(auto e : graph[from]) {
        auto to = std::get< 0 >(e);
        auto w = std::get< 1 >(e);
        add_edge(from, to, w);
      }
    }
  }

private:
  bool built = 0, built_with_construct = 0;
  std::vector< id_type > using_edges;

public:
  void add_edge(size_type from, size_type to, T w, size_type id = 0) {
    assert(!built);
    assert(from < n && to < n);
    graph[from].emplace_back(to, w, id, 0);
  }

public:
  T build(size_type root) {
    assert(!built);
    built = 1;
    std::multiset< id_type > _;
    return calc(graph, root, 0, 1, 0, _);
  }
  T build_with_construct(size_type root) {
    assert(!built);
    built = built_with_construct = 1;
    std::multiset< id_type > using_edges_ms;
    auto res = calc(graph, root, static_cast< T >(0), 1, 1, using_edges_ms);
    using_edges = std::vector< id_type >(using_edges_ms.begin(), using_edges_ms.end());
    return res;
  }
  std::vector< id_type > get_using_edges() {
    assert(built_with_construct);
    return using_edges;
  }

private:
  T calc(const weighted_graph_type &now, size_type start, T sum, bool first_time,
         bool do_construct, std::multiset< id_type > &using_edges) {
    size_type sz = now.size();
    std::vector< size_type > rev(sz, sz);
    std::vector< id_type > using_id(sz), remove_id(sz);
    std::vector< T > weight(sz);
    for(size_type i = 0; i < sz; i++) {
      for(auto e : now[i]) {
        size_type to;
        id_type id, rid;
        T w;
        std::tie(to, w, id, rid) = e;
        if(to == start) continue;
        if(rev[to] == sz || w < weight[to]) {
          weight[to] = w;
          rev[to] = i;
          using_id[to] = id;
          remove_id[to] = rid;
        }
      }
    }

    StronglyConnectedComponent scc(sz);
    for(size_type i = 0; i < sz; i++) {
      if(i == start) continue;
      scc.add_edge(rev[i], i);
      sum += weight[i];
      if(do_construct) {
        using_edges.insert(using_id[i]);
        if(!first_time) {
          using_edges.erase(using_edges.find(remove_id[i]));
        }
      }
    }

    scc.build();

    if(scc.component_size() == sz) return sum;
    weighted_graph_type arranged(scc.component_size());
    for(size_type i = 0; i < sz; i++) {
      for(auto e : now[i]) {
        size_type to, id;
        T w;
        std::tie(to, w, id, std::ignore) = e;
        if(scc[i] == scc[to]) continue;
        arranged[scc[i]].emplace_back(scc[to], w - weight[to], id, using_id[to]);
      }
    }
    return calc(arranged, scc[start], sum, 0, do_construct, using_edges);
  }
};
/// }}}--- ///
template < class T = long long >
using MSA = MinimumSpanningArborescense< T >;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n, m, r;
  std::cin >> n >> m >> r;

  MSA<> msa(n);

  for(int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    msa.add_edge(a, b, c, i);
  }

  // auto ans = msa.build(r);

  auto ans = msa.build_with_construct(r);

  auto edges = msa.get_using_edges();
  assert(edges.size() == n - 1);

  std::cout << ans << std::endl;

  return 0;
}

