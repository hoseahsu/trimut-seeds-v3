#include <bits/stdc++.h>
using namespace std;
int read() {
  int x;
  scanf("%I64d", &x);
  return x;
}
int getrand() {
  srand(time(0));
  int x = rand();
  while (x-- > 0) {
    rand();
  }
  return rand() % 732 + 1;
}
const int N = 12345;
vector<int> v[N];
int x[N], y[N], z[N];
int d[N];
bool used[N], use[N];
int p[N];
int main() {
  int n, m, i, j, s, t, l;
  cin >> n >> m >> l >> s >> t;
  for (i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    v[x[i]].push_back(i);
    v[y[i]].push_back(i);
    if (z[i])
      used[i] = 1;
    else
      z[i] = 1;
  }
  while (1) {
    for (i = 0; i < n; i++) d[i] = 1e9 + 7, use[i] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));
    d[s] = 0;
    while (!q.empty()) {
      int xx = q.top().second;
      q.pop();
      if (use[xx]) continue;
      use[xx] = 1;
      for (int i = 0; i < v[xx].size(); i++) {
        int to = v[xx][i];
        int yy = x[to];
        if (yy == xx) yy = y[to];
        int zz = z[to];
        if (d[yy] > d[xx] + zz) {
          d[yy] = d[xx] + zz;
          q.push(make_pair(-d[yy], yy));
          p[yy] = to;
        }
      }
    }
    if (d[t] > l) {
      puts("NO");
      return 0;
    }
    if (d[t] == l) break;
    int id = -1;
    int r = t;
    while (r != s) {
      int ind = p[r];
      if (!used[ind]) {
        id = ind;
        break;
      }
      if (x[ind] == r)
        r = y[ind];
      else
        r = x[ind];
    }
    if (id == -1) {
      puts("NO");
      return 0;
    }
    z[id] += l - d[t];
  }
  puts("YES");
  for (i = 1; i <= m; i++) {
    cout << x[i] << " " << y[i] << " " << z[i] << endl;
  }
}
