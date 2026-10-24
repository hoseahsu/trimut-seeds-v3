#include <bits/stdc++.h>
using namespace std;
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename T>
void read_integer(T &r) {
  bool sign = 0;
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c == '-') {
      sign = 1;
      break;
    }
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') break;
    r = r * 10 + (c - '0');
  }
  if (sign) r = -r;
}
long long binpowmod(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long c = binpowmod(a, b >> 1, mod);
  return (((c * c) % mod) * (b & 1 ? a : 1)) % mod;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long c = binpow(a, b >> 1);
  return c * c * (b & 1 ? a : 1);
}
inline int getbit(int x, int b) { return (x >> b) & 1; }
inline int setbit(int x, int b) { return x | (1 << b); }
inline void _setbit(int &x, int b) { x = setbit(x, b); }
inline long long setbit(long long x, int b) { return x | (1ll << b); }
inline void _setbit(long long &x, int b) { x = setbit(x, b); }
inline int unsetbit(int x, int b) { return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b) { x = unsetbit(x, b); }
inline int countbit(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline long long countbit(long long x) {
  return countbit(int(x & INT_MAX)) + countbit(int(x >> 32) & INT_MAX);
}
inline void printbit(int x, int len) {
  for (int i = len - 1; i >= 0; i--) printf("%d", getbit(x, i));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
template <typename A, typename B>
ostream &operator<<(ostream &stream, const pair<A, B> &p) {
  stream << "{" << p.first << "," << p.second << "}";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const vector<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A, typename B>
ostream &operator<<(ostream &stream, const map<A, B> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const set<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const stack<A> &v) {
  stack<A> st = v;
  stream << "[";
  while (!st.empty()) {
    stream << st.top() << " ";
    st.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const priority_queue<A> &v) {
  priority_queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.top() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const queue<A> &v) {
  queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const deque<A> &v) {
  deque<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop_front();
  }
  stream << "]";
  return stream;
}
void run();
int main() {
  srand(time(NULL));
  run();
  return 0;
}
const int mod = 1e9 + 7;
const int N = 1003;
struct Edge {
  int a, b;
  long long cost;
  Edge(int _a = 0, int _b = 0, long long _cost = 0)
      : a(_a), b(_b), cost(_cost) {}
  int to(int from) { return from == a ? b : a; }
};
vector<int> g[N];
vector<Edge> e;
vector<long long> d(N, LLONG_MAX);
vector<int> p(N, -1);
vector<bool> u(N * 100, false);
long long dejkstra(int s, int t, bool f = false) {
  std::fill(d.begin(), d.end(), LLONG_MAX);
  set<pair<long long, int> > st;
  d[s] = 0;
  st.insert({0, s});
  while (!st.empty()) {
    int v = (*st.begin()).second;
    st.erase(st.begin());
    for (int i = 0; i < ((int)g[v].size()); ++i) {
      auto edg = e[g[v][i]];
      if (edg.cost == 0 && f) continue;
      long long cost = max(1ll, edg.cost);
      if (d[edg.to(v)] > d[v] + cost) {
        st.erase({d[edg.to(v)], edg.to(v)});
        d[edg.to(v)] = d[v] + cost;
        p[edg.to(v)] = g[v][i];
        st.insert({d[edg.to(v)], edg.to(v)});
      }
    }
  }
  0 ? (cout << "d[t]"
            << " = " << (d[t]) << "\n")
    : cout;
  return d[t];
}
void run() {
  int n, m, L, s, t;
  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &L, &s, &t);
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(((int)e.size()));
    g[b].push_back(((int)e.size()));
    e.push_back(Edge(a, b, c));
  }
  if (dejkstra(s, t, true) < L) {
    printf("NO\n");
    return;
  }
  while (dejkstra(s, t) <= L) {
    int v = t;
    vector<int> vct;
    while (v != s) {
      int id = p[v];
      if (e[id].cost == 0) {
        vct.push_back(id);
        u[id] = 1;
      }
      v = e[id].to(v);
    }
    if (vct.empty()) break;
    int need = L - d[t];
    e[vct.back()].cost = 1 + need;
  }
  if (dejkstra(s, t) != L) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < m; ++i)
    if (e[i].cost == 0) e[i].cost = u[i] ? 1ll : 1ll << 50;
  printf("YES\n");
  for (int i = 0; i < m; ++i) printf("%d %d %lld\n", e[i].a, e[i].b, e[i].cost);
}
