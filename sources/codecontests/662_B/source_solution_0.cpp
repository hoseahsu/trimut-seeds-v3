#include <bits/stdc++.h>
using namespace std;
int n, m;
char in[10];
vector<list<int> > V;
map<pair<int, int>, bool> M;
struct Edge {
  int x, y;
  bool c;
};
Edge E[101000];
bool v[101000];
bool T[101000];
bool col;
void BFS() {
  queue<int> Q;
  for (int i = 1; i <= n; ++i)
    if (v[i] == false) {
      list<int> L;
      Q.push(i);
      L.push_back(i);
      v[i] = true;
      while (!Q.empty()) {
        int c = Q.front();
        Q.pop();
        for (auto it = V[c].begin(); it != V[c].end(); ++it)
          if (v[*it] == false) {
            v[*it] = true;
            L.push_back(*it);
            Q.push(*it);
            if (M[pair<int, int>(c, *it)] == col)
              T[*it] = T[c];
            else
              T[*it] = (T[c] + 1) % 2;
          }
      }
      int ncol = 0;
      for (auto it = L.begin(); it != L.end(); ++it)
        if (T[*it] == true) ++ncol;
      if (L.size() - ncol < ncol) {
        for (auto it = L.begin(); it != L.end(); ++it) T[*it] = !T[*it];
      }
    }
}
stack<int> Ans;
bool ans = false;
bool check() {
  bool po = true;
  for (auto it = M.begin(); it != M.end() && po == true; ++it) {
    if (it->second == col) {
      if (T[it->first.first] + T[it->first.second] == 1) po = false;
    } else {
      if (T[it->first.first] + T[it->first.second] != 1) po = false;
    }
  }
  if (po == false) return false;
  int ncol = 0;
  for (int i = 1; i <= n; ++i)
    if (T[i] == true) ++ncol;
  if (ncol < Ans.size() || ans == false) {
    while (!Ans.empty()) Ans.pop();
    ans = true;
    for (int i = 1; i <= n; ++i)
      if (T[i] == true) Ans.push(i);
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  V.resize(n + 100);
  int a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    scanf("%s", in);
    V[a].push_back(b);
    V[b].push_back(a);
    M[pair<int, int>(a, b)] = M[pair<int, int>(b, a)] = (in[0] == 'R');
  }
  col = false;
  BFS();
  check();
  for (int i = 1; i <= n; ++i) {
    T[i] = false;
    v[i] = false;
  }
  col = true;
  BFS();
  check();
  if (ans == false)
    puts("-1");
  else {
    printf("%d\n", Ans.size());
    while (!Ans.empty()) {
      printf("%d ", Ans.top());
      Ans.pop();
    }
    puts("");
  }
  return 0;
}
