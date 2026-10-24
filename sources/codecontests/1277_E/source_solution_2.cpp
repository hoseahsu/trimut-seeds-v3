#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powerMod(long long x, long long y) {
  long long res = 1;
  x %= 998244353;
  while (y > 0) {
    if (y & 1) res = (res * x) % 998244353;
    y = y >> 1;
    x = (x * x) % 998244353;
  }
  return res % 998244353;
}
string binary(long long s) {
  string res = "";
  while (s != 0) {
    res += (char)('0' + s % 2);
    s /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
vector<int> parent;
vector<set<int> > adj;
vector<bool> vi;
set<int> ea, emplace_back;
int n, a, b;
int find(int a) { return a == parent[a] ? a : parent[a] = find(parent[a]); }
void join(int a, int b) { parent[find(b)] = find(a); }
void dfs(int p, int node) {
  for (int i : adj[node]) {
    parent[i] = p;
    if (!vi[i]) {
      vi[i] = true;
      dfs(p, i);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int i, j, k, l, m, p, s, t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    --a;
    --b;
    parent.resize(n);
    vi.resize(n, false);
    adj.resize(n);
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < m; i++) {
      cin >> j >> k;
      --j, --k;
      if (j == a || k == a || j == b || k == b) {
        if ((j == a && k == b) || (j == b && k == a))
          ;
        else if (j == a)
          ea.insert(k);
        else if (j == b)
          emplace_back.insert(k);
        else if (k == a)
          ea.insert(j);
        else if (k == b)
          emplace_back.insert(j);
        continue;
      }
      adj[j].insert(k);
      adj[k].insert(j);
    }
    for (i = 0; i < n; i++) {
      if (!vi[i]) {
        vi[i] = true;
        dfs(i, i);
      }
    }
    set<int> da, db;
    for (int i : ea) {
      da.insert(find(i));
    }
    for (int i : emplace_back) {
      db.insert(find(i));
    }
    vector<int> rem;
    for (int i : da) {
      if (db.find(i) != db.end()) {
        rem.emplace_back(i);
      }
    }
    for (int i : rem) {
      da.erase(i);
      db.erase(i);
    }
    vector<int> cnt(n, 0);
    for (i = 0; i < n; i++) {
      cnt[find(i)]++;
    }
    long long aa = 0LL, bb = 0LL;
    for (int i : da) {
      aa += cnt[i];
    }
    for (int i : db) {
      bb += cnt[i];
    }
    cout << (aa * bb) << "\n";
    adj.clear();
    ea.clear();
    emplace_back.clear();
    vi.clear();
    parent.clear();
  }
  return 0;
}
