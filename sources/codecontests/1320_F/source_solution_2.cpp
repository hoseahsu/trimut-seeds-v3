#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
int n, m, K, x, a[N];
vector<int> vec[N];
bool IN(int x, int y, int z) {
  return 1 <= x && x <= n && 1 <= y && y <= m && 1 <= z && z <= K;
}
int ID(int x, int y, int z) {
  assert(IN(x, y, z));
  return (x - 1) * m * K + (y - 1) * K + (z - 1);
}
void GG() {
  puts("-1");
  exit(0);
}
void erase(int, int, int);
void Insert(int, int, int, int, int);
bool flg = 0;
void insert(int d, int x, int y, int z, int c) {
  if (!IN(x, y, z)) {
    if (c) GG();
    return;
  }
  int id = ID(x, y, z);
  if (!c) {
    if (a[id] > 0) erase(x, y, z);
    a[id] = 0;
    Insert(d, x, y, z, c);
  } else if (a[id] == -1 || a[id] == c) {
    a[id] = c;
    vec[id].push_back(d);
  } else if (!a[id])
    Insert(d, x, y, z, c);
  else {
    erase(x, y, z);
    a[id] = 0;
    Insert(d, x, y, z, c);
  }
}
void Insert(int d, int x, int y, int z, int c) {
  insert(d, x + dx[d], y + dy[d], z + dz[d], c);
}
void erase(int x, int y, int z) {
  int id = ID(x, y, z);
  for (; vec[id].size();) {
    int v = vec[id].back();
    vec[id].pop_back();
    Insert(v, x, y, z, a[id]);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  memset(a, -1, sizeof(a));
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(1); j <= (int)(K); j++)
      scanf("%d", &x), insert(0, 1, i, j, x);
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(1); j <= (int)(K); j++)
      scanf("%d", &x), insert(1, n, i, j, x);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(K); j++)
      scanf("%d", &x), insert(2, i, 1, j, x);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(K); j++)
      scanf("%d", &x), insert(3, i, m, j, x);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      scanf("%d", &x), insert(4, i, j, 1, x);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      scanf("%d", &x), insert(5, i, j, K, x);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      for (int k = (int)(1); k <= (int)(K); k++) {
        int ans = a[ID(i, j, k)];
        printf("%d%c", max(ans, 0), k == K ? '\n' : ' ');
      }
  return 0;
}
