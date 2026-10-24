#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > matmul(vector<vector<long long> > &a,
                                  vector<vector<long long> > &b) {
  int i, j, k, n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      long long temp = 0;
      for (k = 0; k < n; k++)
        temp = (temp + a[i][k] * b[k][j]) % (1000000007LL);
      ans[i][j] = temp;
    }
  return ans;
}
vector<vector<long long> > matpwr(vector<vector<long long> > &a, long long p) {
  int n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  while (p) {
    if (p & 1) ans = matmul(ans, a);
    a = matmul(a, a);
    p >>= 1;
  }
  return ans;
}
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long invMod(long long n, long long mod = (1000000007LL)) {
  return pwr(n, mod - 2);
}
struct edge {
  int a, b, cap, flow;
  edge() {}
  edge(int a, int b, int cap, int flow) {
    this->a = a;
    this->b = b;
    this->cap = cap;
    this->flow = flow;
  }
};
int n, s, t, dist[205], ptr[202];
vector<int> adj[205];
vector<edge> edgeList;
void add_edge(int a, int b, int cap) {
  adj[a].push_back(edgeList.size());
  edgeList.push_back(edge(a, b, cap, 0));
  adj[b].push_back(edgeList.size());
  edgeList.push_back(edge(b, a, 0, 0));
}
bool bfs() {
  memset(dist, -1, sizeof(dist));
  queue<int> qq;
  dist[s] = 0;
  qq.push(s);
  while (!qq.empty()) {
    int v = qq.front();
    qq.pop();
    for (int i = 0; i < (int)adj[v].size(); i++) {
      int id = adj[v][i];
      int vv = v ^ edgeList[id].a ^ edgeList[id].b;
      if (dist[vv] == -1 && edgeList[id].flow < edgeList[id].cap) {
        dist[vv] = 1 + dist[v];
        qq.push(vv);
      }
    }
  }
  return (dist[t] != -1);
}
int dfs(int v, int flow) {
  if (!flow) return 0;
  if (v == t) return flow;
  for (; ptr[v] < (int)adj[v].size(); ptr[v]++) {
    int id = adj[v][ptr[v]];
    int vv = v ^ edgeList[id].a ^ edgeList[id].b;
    if (dist[vv] != dist[v] + 1) continue;
    int pushed = dfs(vv, min(flow, edgeList[id].cap - edgeList[id].flow));
    if (pushed > 0) {
      edgeList[id].flow += pushed;
      edgeList[1 ^ id].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
int dinitz() {
  int ans = 0;
  while (1) {
    if (!bfs()) break;
    memset(ptr, 0, sizeof(ptr));
    while (int pushed = dfs(s, (100000005)) > 0) ans += pushed;
  }
  return ans;
}
int e, o, even[202], odd[202], arr[202], sieve[20002];
vector<vector<int> > tables;
bool done[202];
void get_table_members(int v) {
  done[v] = true;
  tables.back().push_back(v);
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int id = adj[v][i];
    int vv = v ^ edgeList[id].a ^ edgeList[id].b;
    if (edgeList[id].flow == 0 || done[vv]) continue;
    get_table_members(vv);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  sieve[1] = 1;
  for (int i = 2; i <= 20000; i++)
    if (!sieve[i])
      for (int j = 2 * i; j <= 20000; j += i) sieve[j] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if ((arr[i] & 1) == 0)
      even[e++] = i;
    else
      odd[o++] = i;
  }
  if (e != o) {
    cout << "Impossible";
    return 0;
  }
  s = 0;
  t = n + 1;
  for (int i = 0; i < e; i++) add_edge(s, even[i], 2);
  for (int i = 0; i < o; i++) add_edge(odd[i], t, 2);
  for (int i = 0; i < e; i++)
    for (int j = 0; j < o; j++)
      if (!sieve[arr[even[i]] + arr[odd[j]]]) add_edge(even[i], odd[j], 1);
  if (dinitz() != n) {
    cout << "Impossible";
    return 0;
  }
  done[s] = done[t] = true;
  for (int i = 1; i <= n; i++)
    if (!done[i]) {
      tables.push_back(vector<int>());
      get_table_members(i);
    }
  cout << tables.size() << endl;
  for (int i = 0; i < (int)tables.size(); i++) {
    cout << tables[i].size();
    for (int j = 0; j < (int)tables[i].size(); j++) cout << " " << tables[i][j];
    cout << endl;
  }
  return 0;
}
