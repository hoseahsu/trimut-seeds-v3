#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n, root;
long long boje[5][N];
vector<int> ls[N];
long long res = 1e14 + 11;
vector<int> v;
int r1, r2, r3;
int rez[N];
void dfs(int x, int p) {
  v.push_back(x);
  for (int i = 0; i < ls[x].size(); i++) {
    if (ls[x][i] == p) continue;
    dfs(ls[x][i], x);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lld", &boje[i][j]);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int a1, a2;
    scanf("%d%d", &a1, &a2);
    a1--;
    a2--;
    ls[a1].push_back(a2);
    ls[a2].push_back(a1);
  }
  for (int i = 0; i < n; i++) {
    if (ls[i].size() >= 3) {
      cout << -1;
      return 0;
    }
    if (ls[i].size() == 1) root = i;
  }
  dfs(root, -1);
  for (int x = 1; x < 4; x++) {
    for (int y = 1; y < 4; y++) {
      if (x == y) continue;
      int z = 6 - x - y;
      long long sada = 0;
      for (int i = 0; i < n; i++) {
        if (i % 3 == 0)
          sada += boje[x - 1][v[i]];
        else if (i % 3 == 1)
          sada += boje[y - 1][v[i]];
        else
          sada += boje[z - 1][v[i]];
      }
      if (sada < res) {
        res = sada;
        r1 = x;
        r2 = y;
        r3 = z;
      }
    }
  }
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0)
      rez[v[i]] = r1;
    else if (i % 3 == 1)
      rez[v[i]] = r2;
    else
      rez[v[i]] = r3;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", rez[i]);
  }
  return 0;
}
