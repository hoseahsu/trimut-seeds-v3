#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
#include <tuple>
#include <utility>
using namespace std;

namespace {
  using Integer = long long; //__int128;
  template<class T, class S> istream& operator >> (istream& is, pair<T,S>& p){return is >> p.first >> p.second;}
  template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
  template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
  template<class T, class S> ostream& operator << (ostream& os, const pair<T,S>& p){return os << p.first << " " << p.second;}
  template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(size_t i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
  template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

  template<class H> void print(const H& head){ cout << head; }
  template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
  template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

  template<class H> void eprint(const H& head){ cerr << head; }
  template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; eprint(tail...); }
  template<class ... T> void eprintln(const T& ... values){ eprint(values...); cerr << endl; }

  class range{ Integer start_, end_, step_; public: struct range_iterator{ Integer val, step_; range_iterator(Integer v, Integer step) : val(v), step_(step) {} Integer operator * (){return val;} void operator ++ (){val += step_;} bool operator != (range_iterator& x){return step_ > 0 ? val < x.val : val > x.val;} }; range(Integer len) : start_(0), end_(len), step_(1) {} range(Integer start, Integer end) : start_(start), end_(end), step_(1) {} range(Integer start, Integer end, Integer step) : start_(start), end_(end), step_(step) {} range_iterator begin(){ return range_iterator(start_, step_); } range_iterator   end(){ return range_iterator(  end_, step_); } };

  inline string operator "" _s (const char* str, size_t size){ return move(string(str)); }
  constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
  constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
  constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

  inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

  mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

  template<class T> string join(const vector<T>& v, const string& sep){ stringstream ss; for(size_t i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str(); }

  inline string operator * (string s, int k){ string ret; while(k){ if(k&1) ret += s; s += s; k >>= 1; } return ret; }
}
constexpr long long mod = 9_ten + 7;

class UnionFindTree{
  struct base_node{
    int parent;
    int rank;
    int size;
  };
  
  vector<base_node> node;
 public:
  UnionFindTree(int n){
    node.resize(n);
    for(int i=0; i<n; i++){
      node[i].parent=i;
      node[i].rank=0;
      node[i].size=1;
    }
  }

  int find(int x){  //return root node of x
    if(node[x].parent == x) return x;
    else{
      return node[x].parent = find(node[x].parent);
    }
  }
  
  bool same(int x, int y){
    return find(x) == find(y);
  }

  int size(int at){
    return node[find(at)].size;
  }

  void unite(int x, int y){
    x = find(node[x].parent);
    y = find(node[y].parent);

    if(x==y) return;

    if(node[x].rank < node[y].rank){
      node[x].parent = y;
      node[y].size += node[x].size;
    }else if(node[x].rank > node[y].rank){
      node[y].parent = x;
      node[x].size += node[y].size;
    }else{
      node[x].rank++;
      unite(x,y);
    }
  }
};



int main(){
  int n,m;
  cin >> n,m;
  vector<int> a(m),b(m),c(m);

  for(auto i : range(m) ){
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    a[i]--; b[i]--;
  }

  UnionFindTree uft(n);
  vector<pair<int,pair<int,int>>> edge(m);
  for(auto i : range(m) ){
    edge[i] = {c[i], {a[i],b[i]}};
  }
  sort(edge.begin(), edge.end());

  vector<vector<int>> G(n);
  vector<vector<long long>> dd(n);
  long long mst_cost = 0;
  for(auto e : edge){
    if(uft.same(e.second.first, e.second.second)) continue;
    uft.unite(e.second.first, e.second.second);
    mst_cost += e.first;

    G[e.second.first].push_back(e.second.second);
    G[e.second.second].push_back(e.second.first);

    dd[e.second.first].push_back(e.first);
    dd[e.second.second].push_back(e.first);
  }

  int sz = 13;
  
  vector<vector<int>> p(n, vector<int>(sz, -1));
  vector<int> depth(n, -1);
  vector<vector<long long>> mx_e(n, vector<long long>(sz, 0));

  function<void(int,int,int)> set_p = [&](int pos, int par, int d){
    depth[pos] = d;
    p[pos][0] = par;
    for(auto i : range(G[pos].size())){
      int nx = G[pos][i];
      if(nx == par) continue;
      mx_e[nx][0] = dd[pos][i];
      set_p(nx, pos, d+1);
    }
  };

  set_p(0,0,0);

  for(int k=1; k<sz; k++){
    for(int i=0; i<n; i++){
      p[i][k] = p[p[i][k-1]][k-1];
      mx_e[i][k] = max(mx_e[i][k-1], mx_e[p[i][k-1]][k-1]);
    }
  }
  

  int q;
  cin >> q;
  while(q--){
    int u,v;
    scanf("%d%d", &u,&v);
    u--; v--;

    long long sub = 0;

    if(depth[u] > depth[v]) swap(u,v);
    for(int k=0; k<sz; k++){
      if( ((depth[v] - depth[u]) >> k) & 1){
        sub = max(sub, mx_e[v][k]);
        v = p[v][k];
      }
    }
    for(int k=sz-1; k>=0; k--){
      if(p[u][k] != p[v][k]) {
        sub = max(sub, mx_e[u][k]);
        sub = max(sub, mx_e[v][k]);
        u = p[u][k];
        v = p[v][k];
      }
    }
    if(u!=v){
      sub = max({sub, mx_e[u][0], mx_e[v][0]});
    }

    //println( mst_cost - sub );
    printf("%lld\n", mst_cost - sub);
  }

  return 0;
}
