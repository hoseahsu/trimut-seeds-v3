#include <bits/stdc++.h>
using namespace std;
int const GRAY = -2;
int const BLACK = -1;
int const WHITE = 0;
int const INF = 1e8;
long long const INFe15 = 1e15;
long long const INFe64 = 1e18;
inline double sqr(double a) { return a * a; }
template <typename T>
void alert(const T& t) {
  cout << t;
  exit(0);
}
struct cell_t {
  int l, r, u, d;
  int v;
};
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<cell_t> v((n + 2) * (m + 2));
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (i && j && i <= n && j <= m) {
        scanf("%d", &v[i * m + j].v);
      }
      v[i * m + j].u = (i - 1) * m + j;
      v[i * m + j].d = (i + 1) * m + j;
      v[i * m + j].l = i * m + (j - 1);
      v[i * m + j].r = i * m + (j + 1);
    }
  }
  for (int z = 0; z < q; z++) {
    int a, b, c, d, h, w;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
    int one = 0;
    for (int i = 0; i < a; i++) one = v[one].d;
    for (int j = 0; j < b; j++) one = v[one].r;
    int two = 0;
    for (int i = 0; i < c; i++) two = v[two].d;
    for (int j = 0; j < d; j++) two = v[two].r;
    swap(v[v[one].u].d, v[v[two].u].d);
    swap(v[one].u, v[two].u);
    for (int i = 1; i < w; i++) {
      one = v[one].r;
      two = v[two].r;
      swap(v[v[one].u].d, v[v[two].u].d);
      swap(v[one].u, v[two].u);
    }
    swap(v[v[one].r].l, v[v[two].r].l);
    swap(v[one].r, v[two].r);
    for (int i = 1; i < h; i++) {
      one = v[one].d;
      two = v[two].d;
      swap(v[v[one].r].l, v[v[two].r].l);
      swap(v[one].r, v[two].r);
    }
    swap(v[v[one].d].u, v[v[two].d].u);
    swap(v[one].d, v[two].d);
    for (int i = 1; i < w; i++) {
      one = v[one].l;
      two = v[two].l;
      swap(v[v[one].d].u, v[v[two].d].u);
      swap(v[one].d, v[two].d);
    }
    swap(v[v[one].l].r, v[v[two].l].r);
    swap(v[one].l, v[two].l);
    for (int i = 1; i < h; i++) {
      one = v[one].u;
      two = v[two].u;
      swap(v[v[one].l].r, v[v[two].l].r);
      swap(v[one].l, v[two].l);
    }
  }
  int line = 0;
  for (int i = 0; i < n; i++) {
    line = v[line].d;
    int col = line;
    for (int j = 0; j < m; j++) {
      col = v[col].r;
      printf("%d ", v[col].v);
    }
    cout << endl;
  }
  return 0;
}
