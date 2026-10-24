#include <bits/stdc++.h>
using namespace std;
void ASS(bool b) {
  if (!b) {
    ++*(int*)0;
  }
}
#pragma comment(linker, "/STACK:106777216")
const int N = 1 << 19;
vector<int> v;
int Id(int x) {
  vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
  ASS(*it == x);
  return it - v.begin();
}
struct Entity {
  int s, f, t;
  void read() {
    scanf("%d %d %d", &s, &f, &t);
    v.push_back(s);
    v.push_back(f);
  }
};
struct S {
  int f, t, id;
};
vector<S> Buses[N];
vector<S> Pass[N];
int ans[N];
struct SS {
  int t, id;
  bool operator<(const SS& s) const { return t < s.t; }
};
set<SS> a[N * 2];
void Add(int pos, int t, int id) {
  SS ss;
  ss.t = t;
  ss.id = id;
  for (int i = pos + N; i; i >>= 1) a[i].insert(ss);
}
SS Up(set<SS>& st, int t) {
  SS ss;
  ss.t = t;
  set<SS>::iterator it = st.lower_bound(ss);
  if (it == st.end()) {
    SS res;
    res.t = 1 << 30;
    res.id = -1;
    return res;
  } else {
    return *it;
  }
}
SS Best(int L, int R, int t) {
  SS res;
  res.t = 1 << 30;
  res.id = -1;
  for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
    if (L & 1) {
      res = min(res, Up(a[L], t));
      L++;
    }
    if (R & 1) {
      R--;
      res = min(res, Up(a[R], t));
    }
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<Entity> buses(n);
  for (int i = 0; i < (int)(n); i++) buses[i].read();
  vector<Entity> pass(m);
  for (int i = 0; i < (int)(m); i++) pass[i].read();
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < (int)(n); i++) {
    S ss;
    ss.f = Id(buses[i].f);
    ss.t = buses[i].t;
    ss.id = i + 1;
    Buses[Id(buses[i].s)].push_back(ss);
  }
  for (int i = 0; i < (int)(m); i++) {
    S ss;
    ss.f = Id(pass[i].f);
    ss.t = pass[i].t;
    ss.id = i;
    Pass[Id(pass[i].s)].push_back(ss);
  }
  for (int L = 0; L < (int)(N); L++) {
    for (int i = 0; i < (int)(Buses[L].size()); i++)
      Add(Buses[L][i].f, Buses[L][i].t, Buses[L][i].id);
    for (int i = 0; i < (int)(Pass[L].size()); i++)
      ans[Pass[L][i].id] = Best(Pass[L][i].f, N, Pass[L][i].t).id;
  }
  for (int i = 0; i < (int)(m); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
