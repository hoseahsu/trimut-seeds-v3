#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y, d;
} e[500001];
bool operator<(struct edge a, struct edge b) { return a.d < b.d; }
int N, M;
vector<struct edge> v;
vector<int> q[500001], toq[500001];
int rt[500001], siz[500001];
int cprt[500001], cpsiz[500001];
bool failed[500001];
vector<int> changed;
bool cmp(int X, int Y) { return e[X].d < e[Y].d; }
int root(int x) {
  while (x != rt[x]) {
    rt[x] = rt[rt[x]];
    x = rt[x];
  }
  return x;
}
int fakeroot(int x) {
  while (x != cprt[x]) {
    x = cprt[x];
  }
  return x;
}
void merge(int x, int y) {
  int a = root(x);
  int b = root(y);
  if (siz[a] < siz[b]) {
    rt[a] = b;
    cprt[a] = b;
    siz[b] += siz[a];
    cpsiz[b] += cpsiz[a];
  } else {
    rt[b] = a;
    cprt[b] = a;
    siz[a] += siz[b];
    cpsiz[a] += cpsiz[b];
  }
}
void fakemerge(int x, int y) {
  int a = fakeroot(x);
  int b = fakeroot(y);
  changed.push_back(a);
  changed.push_back(b);
  if (cpsiz[a] < cpsiz[b]) {
    cprt[a] = b;
    cpsiz[b] += cpsiz[a];
  } else {
    cprt[b] = a;
    cpsiz[a] += cpsiz[b];
  }
}
int cur[500001];
void recover() {
  for (int i = 0; i < changed.size(); i++) {
    int j = changed[i];
    cprt[j] = rt[j];
    cpsiz[j] = siz[j];
  }
}
bool check(vector<int>& v) {
  changed.clear();
  for (int i = 0; i < v.size(); i++) {
    int j = v[i];
    if (fakeroot(e[j].x) == fakeroot(e[j].y)) {
      recover();
      return false;
    }
    fakemerge(e[j].x, e[j].y);
  }
  recover();
  return true;
}
int cnt[500001];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
    cnt[e[i].d]++;
    v.push_back(e[i]);
  }
  sort(v.begin(), v.end());
  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int K;
    set<int> st;
    scanf("%d", &K);
    for (int j = 0; j < K; j++) {
      int X;
      scanf("%d", &X);
      X--;
      q[i].push_back(X);
      st.insert(e[X].d);
    }
    sort(q[i].begin(), q[i].end(), cmp);
    for (auto x : st) {
      toq[x].push_back(i);
    }
  }
  for (int i = 1; i <= N; i++) {
    rt[i] = i;
    cprt[i] = i;
    siz[i] = 1;
    cpsiz[i] = 1;
  }
  int CUR = 0;
  for (int i = 1; i <= 500000; i++) {
    for (int j = 0; j < toq[i].size(); j++) {
      if (!failed[toq[i][j]]) {
        int ind = cur[toq[i][j]];
        int store = ind;
        vector<int> temp;
        while (ind < q[toq[i][j]].size() &&
               e[q[toq[i][j]][ind]].d == e[q[toq[i][j]][store]].d) {
          temp.push_back(q[toq[i][j]][ind]);
          ind++;
          cur[toq[i][j]]++;
        }
        if (!check(temp)) {
          failed[toq[i][j]] = true;
        }
      }
    }
    if (cnt[i] > 0) {
      int temp = CUR;
      while (CUR < M && v[CUR].d == v[temp].d) {
        if (root(v[CUR].x) != root(v[CUR].y)) merge(v[CUR].x, v[CUR].y);
        CUR++;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    if (failed[i])
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
