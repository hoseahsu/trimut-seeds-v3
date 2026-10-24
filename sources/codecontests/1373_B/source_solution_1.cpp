#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long double PI = acos(-1);
const long double E = 2.71828183;
const int MOD = 1e9 + 7;
vector<int> bfs(vector<vector<int> > adj, int src) {
  queue<int> q;
  q.push(src);
  vector<int> dst(adj.size(), INF);
  dst[src] = 0;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int nbr : adj[c]) {
      if (dst[nbr] == INF) {
        dst[nbr] = dst[c] + 1;
        q.push(nbr);
      }
    }
  }
  return dst;
}
vector<int> bfsParents(vector<vector<int> > adj, int src) {
  vector<int> parents = vector<int>(adj.size(), INF);
  parents[src] = -1;
  queue<int> q;
  q.push(src);
  vector<int> dst(adj.size(), INF);
  dst[src] = 0;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int nbr : adj[c]) {
      if (dst[nbr] == INF) {
        parents[nbr] = c;
        dst[nbr] = dst[c] + 1;
        q.push(nbr);
      }
    }
  }
  return parents;
}
list<int> shortestPath(vector<vector<int> > adj, int src, int dst) {
  vector<int> bfsParetns = bfsParents(adj, src);
  list<int> ans;
  ans.push_back(dst);
  while (ans.front() != src) ans.push_front(bfsParetns[ans.front()]);
  return ans;
}
long long powMod(long long base, long long exp, long long mod) {
  long long ans = 1;
  for (long long i = 0; i < exp; i++) ans = ((ans % mod) * (base % mod)) % mod;
  return ans;
}
vector<int> divisorsOf(int n) {
  vector<int> ans;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) ans.push_back(i);
    if (i * i != n && i != 1) ans.push_back(n / i);
  }
  return ans;
}
long long gcd(long long a, long long b) {
  return (a % b == 0 ? b : gcd(b, a % b));
}
long double log(long double a, long double b) { return log(b) / log(a); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    exp--;
    res *= base;
  }
  return res;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
void solve() {
  string s;
  cin >> s;
  int z = 0, o = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      z++;
    else
      o++;
  }
  if (min(o, z) % 2 == 1)
    cout << "DA\n";
  else
    cout << "NET\n";
}
