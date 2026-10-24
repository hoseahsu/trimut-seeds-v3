#include <bits/stdc++.h>
using namespace std;
const int MAXN = 901;
vector<int> gra0[MAXN], gra1[MAXN], isop;
int fa[MAXN], cnt[MAXN], d[MAXN], anc[MAXN];
bool mp0[MAXN][MAXN], mp1[MAXN][MAXN];
int dn;
int DSU_Father(int a) {
  if (fa[a] == a)
    return a;
  else
    return fa[a] = DSU_Father(fa[a]);
}
void DSU_Merge(int a, int b) {
  if (DSU_Father(a) == DSU_Father(b)) return;
  if (cnt[a] < cnt[b]) swap(a, b);
  cnt[DSU_Father(a)] += cnt[DSU_Father(b)];
  fa[DSU_Father(b)] = DSU_Father(a);
  return;
}
void DFS0(int nowp, int pre) {
  d[nowp] = anc[nowp] = dn++;
  for (vector<int>::iterator iter = gra0[nowp].begin();
       iter != gra0[nowp].end(); iter++)
    if (*iter != pre) {
      if (d[*iter] == -1) {
        DFS0(*iter, nowp);
        if (anc[*iter] <= d[nowp]) DSU_Merge(nowp, *iter);
        anc[nowp] = min(anc[nowp], anc[*iter]);
      } else
        anc[nowp] = min(anc[nowp], d[*iter]);
    }
  return;
}
void DFS1(int nowp, int pre) {
  if (gra1[nowp].size() == 1) isop.push_back(nowp);
  for (vector<int>::iterator iter = gra1[nowp].begin();
       iter != gra1[nowp].end(); iter++)
    if (*iter != pre) DFS1(*iter, nowp);
  return;
}
int main() {
  int n, m, n0;
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    gra0[a - 1].push_back(b - 1);
    gra0[b - 1].push_back(a - 1);
    mp0[a - 1][b - 1] = mp0[b - 1][a - 1] = true;
  }
  for (int i = 0; i < n; i++) fa[i] = i, cnt[i] = 1, d[i] = -1, anc[i] = -1;
  dn = 0;
  n0 = 0;
  DFS0(0, -1);
  for (int i = 0; i < n; i++)
    if (i == DSU_Father(i)) n0++;
  for (int i = 0; i < n; i++)
    for (vector<int>::iterator iter = gra0[i].begin(); iter != gra0[i].end();
         iter++)
      if (DSU_Father(i) != DSU_Father(*iter) &&
          !mp1[DSU_Father(i)][DSU_Father(*iter)]) {
        gra1[DSU_Father(i)].push_back(DSU_Father(*iter));
        gra1[DSU_Father(*iter)].push_back(DSU_Father(i));
        mp1[DSU_Father(i)][DSU_Father(*iter)] = true;
        mp1[DSU_Father(*iter)][DSU_Father(i)] = true;
      }
  if (n0 == 1)
    printf("0\n");
  else if (n == 2)
    printf("-1\n");
  else if (n0 == 2) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        if (DSU_Father(i) != DSU_Father(j) && !mp0[i][j]) {
          printf("1\n%d %d\n", i + 1, j + 1);
          found = true;
          break;
        }
      if (found) break;
    }
  } else {
    int c;
    for (int i = 0; i < n; i++)
      if (gra1[i].size() > 1) {
        c = i;
        break;
      }
    DFS1(c, -1);
    if (isop.size() % 2 == 1) isop.push_back(c);
    printf("%d\n", isop.size() / 2);
    for (int i = 0; i < isop.size() / 2; i++) {
      bool found = false;
      for (int x = 0; x < n; x++)
        if (DSU_Father(x) == isop[i]) {
          for (int y = 0; y < n; y++)
            if (DSU_Father(y) == isop[i + isop.size() / 2] && !mp0[x][y]) {
              mp0[x][y] = mp0[y][x] = true;
              printf("%d %d\n", x + 1, y + 1);
              found = true;
              break;
            }
          if (found) break;
        }
      if (!found) {
        for (int x = 0; x < n; x++)
          if (x != isop[i] && !mp0[x][isop[i]]) {
            printf("%d %d\n", x + 1, isop[i] + 1);
            break;
          }
      }
    }
  }
  return 0;
}
