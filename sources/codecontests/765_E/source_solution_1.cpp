#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18 + 7;
vector<set<pair<int, int> > > g;
int is_lst[200500];
vector<int> merge_que;
vector<pair<int, int> > check_que;
vector<map<int, vector<int> > > all_edge;
int del[200500];
void norm(vector<int> &ar) {
  int i = (int)ar.size() - 1;
  for (; i >= 0 && del[ar[i]]; --i)
    ;
  while ((int)ar.size() != i + 1) ar.pop_back();
  --i;
  if (i < 0) return;
  for (; i >= 0 && del[ar[i]]; --i)
    ;
  if (i < 0) {
    swap(ar[0], ar.back());
    while (ar.size() > 1) ar.pop_back();
    return;
  }
  swap(ar[i + 1], ar.back());
  while ((int)ar.size() > i + 2) ar.pop_back();
  return;
}
void erase_edge(int v, int to) {
  auto it = g[v].lower_bound(make_pair(to, 0));
  if (it != g[v].end() && it->first == to) g[v].erase(it);
  return;
}
int merge(int v) {
  if (del[v]) return 0;
  pair<int, int> q = *g[v].begin();
  pair<int, int> w = *(++g[v].begin());
  if (is_lst[q.first]) swap(q, w);
  if (is_lst[q.first]) return q.second + w.second;
  erase_edge(q.first, v);
  erase_edge(w.first, v);
  g[v].clear();
  del[v] = 1;
  g[q.first].insert(make_pair(w.first, q.second + w.second));
  g[w.first].insert(make_pair(q.first, q.second + w.second));
  if (is_lst[w.first]) {
    all_edge[q.first][q.second + w.second].push_back(w.first);
    check_que.push_back(make_pair(q.first, q.second + w.second));
  }
  return 0;
}
int norm(int a) {
  while (a % 2 == 0) a /= 2;
  return a;
}
void check_edge(int v, int len) {
  if (del[v]) return;
  vector<int> &ar = all_edge[v][len];
  norm(ar);
  while ((int)ar.size() > 1) {
    int a = ar[(int)ar.size() - 1], b = ar[(int)ar.size() - 2];
    erase_edge(v, a);
    erase_edge(a, v);
    del[a] = 1;
    del[a] = 1;
    ar.pop_back();
  }
  if (g[v].size() == 2) merge_que.push_back(v);
  return;
}
void check1(int n) {
  int flag = 1;
  int s = 0;
  for (int i = 0; i < (n); ++i) {
    if (g[i].size() > 2) flag = 0;
    for (auto it = g[i].begin(); it != g[i].end(); ++it) s += it->second;
  }
  if (flag) {
    cout << norm(s) << endl;
    ;
    exit(0);
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  all_edge.resize(n);
  g.resize(n);
  for (int i = 0; i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].insert(make_pair(b, 1));
    g[b].insert(make_pair(a, 1));
  }
  check1(n);
  for (int i = 0; i < (n); ++i)
    if (g[i].size() == 1) is_lst[i] = 1;
  for (int i = 0; i < (n); ++i) {
    if (g[i].size() == 2) merge_que.push_back(i);
  }
  for (int i = 0; i < (n); ++i) {
    if (!is_lst[i]) continue;
    int to = g[i].begin()->first;
    all_edge[to][1].push_back(i);
  }
  for (int i = 0; i < (n); ++i) check_que.push_back(make_pair(i, 1));
  while (check_que.size() || merge_que.size()) {
    while (check_que.size()) {
      pair<int, int> a = check_que.back();
      check_que.pop_back();
      check_edge(a.first, a.second);
    }
    while (merge_que.size()) {
      int v = merge_que.back();
      merge_que.pop_back();
      int a = merge(v);
      if (a) {
        check1(n);
        assert(0);
      }
    }
  }
  check1(n);
  cout << -1;
  return 0;
}
