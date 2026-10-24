#include <bits/stdc++.h>
using namespace std;
int g[(int)200 + 10][(int)200 + 10];
int n;
map<int, int> numpos, rnumpos;
int f[(int)200 + 10][(int)200 + 10];
int visited[(int)200 + 10];
int isEdge[(int)200 + 10][(int)200 + 10];
int p[20100];
void calcPrimes() {
  memset(p, 1, sizeof p);
  p[0] = p[1] = 0;
  for (int i = 2; i < 20100; i++) {
    if (p[i] && i * i < 20100) {
      for (int j = i * i; j < 20100; j += i) {
        p[j] = 0;
      }
    }
  }
}
bool isPrime(int a) { return p[a]; }
set<pair<int, int> > gf;
int gf1[(int)200 + 10][(int)200 + 10];
int dfs(int v = 1, int Cmin = (int)1e9 + 10) {
  if (v == 2) return Cmin;
  visited[v] = true;
  for (int to = 2; to < (int)200 + 10; to++) {
    if (isEdge[v][to] && !visited[to]) {
      if (g[v][to] && f[v][to] < g[v][to]) {
        int delta = dfs(to, min(Cmin, g[v][to] - f[v][to]));
        if (delta > 0) {
          f[v][to] += delta;
          f[to][v] += delta;
          if (v != 1 && to != 2) gf.insert(make_pair(min(v, to), max(v, to)));
          return delta;
        }
      } else if (!g[v][to] && f[v][to] > 0) {
        int delta = dfs(to, min(Cmin, f[v][to]));
        if (delta > 0) {
          f[v][to] -= delta;
          f[to][v] -= delta;
          if (v != 1 && to != 2 &&
              gf.find(make_pair(min(v, to), max(v, to))) != gf.end())
            gf.erase(make_pair(min(v, to), max(v, to)));
          return delta;
        }
      }
    }
  }
  return 0;
}
int maxflow() {
  int ans = 0;
  int curflow = dfs();
  while (curflow) {
    ans += curflow;
    memset(visited, 0, sizeof visited);
    curflow = dfs();
  }
  return ans;
}
vector<int> curans;
void print_ans(int a) {
  curans.push_back(a);
  for (int i = 3; i < (int)200 + 10; i++) {
    if (gf1[a][i]) {
      gf1[a][i] = gf1[i][a] = 0;
      gf.erase(make_pair(min(a, i), max(a, i)));
      print_ans(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> odd, even;
  vector<int> num3, num4;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a & 1)
      odd.push_back(a), num3.push_back(i);
    else
      even.push_back(a), num4.push_back(i);
  }
  for (int i = 0; i < odd.size(); i++) {
    g[1][i + 3] = 2;
    isEdge[1][i + 3] = 1;
    isEdge[i + 3][1] = 1;
  }
  for (int i = 0; i < even.size(); i++) {
    g[i + 3 + odd.size()][2] = 2;
    isEdge[i + 3 + odd.size()][2] = 1;
    isEdge[2][i + 3 + odd.size()] = 1;
  }
  calcPrimes();
  for (int i = 0; i < odd.size(); i++) {
    for (int j = 0; j < even.size(); j++) {
      if (isPrime(odd[i] + even[j])) {
        g[i + 3][j + 3 + odd.size()] = 1;
        isEdge[i + 3][j + 3 + odd.size()] = 1;
        isEdge[j + 3 + odd.size()][i + 3] = 1;
      }
    }
  }
  int ans = maxflow();
  if (ans != 2 * odd.size() || odd.size() != even.size()) {
    cout << "Impossible\n";
    return 0;
  }
  for (pair<int, int> a : gf) {
    gf1[a.first][a.second] = 1;
    gf1[a.second][a.first] = 1;
  }
  vector<vector<int> > an;
  while (!gf.empty()) {
    curans.clear();
    print_ans((*gf.begin()).first);
    curans.pop_back();
    an.push_back(curans);
  }
  cout << an.size() << '\n';
  for (vector<int> aa : an) {
    cout << aa.size();
    for (int bb : aa) {
      if (bb - 3 < odd.size()) {
        cout << " " << num3[bb - 3];
      } else {
        cout << " " << num4[bb - 3 - odd.size()];
      }
    }
    cout << '\n';
  }
}
