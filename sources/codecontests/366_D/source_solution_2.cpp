#include <bits/stdc++.h>
using namespace std;
void RD(int &x) { scanf("%d", &x); }
void RD(long long &x) { scanf("%I64d", &x); }
void RD(unsigned long long &x) { scanf("%I64u", &x); }
void RD(unsigned int &x) { scanf("%u", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(unsigned int &x, unsigned int &y) { scanf("%u%u", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(unsigned int &x, unsigned int &y, unsigned int &z) {
  scanf("%u%u%u", &x, &y, &z);
}
void RD(char &x) { x = getchar(); }
void RD(char *s) { scanf("%s", s); }
void RD(string &s) { cin >> s; }
void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(long long x) { printf("%I64d\n", x); }
void PR(unsigned int x) { printf("%u\n", x); }
void PR(double x) { printf("%.10lf\n", x); }
void PR(double x, double y) { printf("%.5lf %.5lf\n", x, y); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }
void upMin(int &x, int y) {
  if (x > y) x = y;
}
void upMin(long long &x, long long y) {
  if (x > y) x = y;
}
void upMin(double &x, double y) {
  if (x > y) x = y;
}
void upMax(int &x, int y) {
  if (x < y) x = y;
}
void upMax(long long &x, long long y) {
  if (x < y) x = y;
}
void upMax(double &x, double y) {
  if (x < y) x = y;
}
const long long inf = ((long long)1) << 60;
const double dinf = 1e10;
const int INF = 100000000;
const int N = 5005;
struct node {
  int v, L, R, next;
};
node edges[N * 10];
int head[N], e;
void add(int u, int v, int L, int R) {
  edges[e].v = v;
  edges[e].L = L;
  edges[e].R = R;
  edges[e].next = head[u];
  head[u] = e++;
}
int n, m;
struct Node {
  vector<int> L, R;
  int insert(int l, int r) {
    int i;
    for (i = 0; i < L.size(); i++) {
      int ll = L[i], rr = R[i];
      if (ll <= l && rr >= r) return 0;
    }
    L.push_back(l);
    R.push_back(r);
    return 1;
  }
};
Node f[N];
queue<int> Q;
int main() {
  while (scanf("%d", &n) != -1) {
    RD(m);
    memset(head, -1, sizeof(head));
    e = 0;
    int u, v, L, R, i;
    for (i = 1; i <= m; i++) {
      RD(u, v);
      RD(L, R);
      add(u, v, L, R);
      add(v, u, L, R);
    }
    for (i = 1; i <= n; i++) {
      f[i].L.clear();
      f[i].R.clear();
    }
    f[1].insert(1, 1000000);
    Q.push(1);
    int inq[N] = {0};
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (u == n) continue;
      inq[u] = 0;
      int i, v;
      for (i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].v;
        int L = edges[i].L;
        int R = edges[i].R;
        int j, flag = 0;
        for (j = 0; j < f[u].L.size(); j++) {
          int ll = f[u].L[j];
          int rr = f[u].R[j];
          upMax(ll, L);
          upMin(rr, R);
          if (ll <= rr) flag |= f[v].insert(ll, rr);
        }
        if (flag && !inq[v]) Q.push(v), inq[v] = 1;
      }
    }
    int ans = 0;
    for (i = 0; i < f[n].L.size(); i++) {
      upMax(ans, f[n].R[i] - f[n].L[i] + 1);
    }
    if (ans)
      PR(ans);
    else
      puts("Nice work, Dima!");
  }
}
