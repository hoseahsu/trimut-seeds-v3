#include <bits/stdc++.h>
using namespace std;
vector<int> u[3005];
int sp[3005][3005];
int n, m;
vector<pair<int, int> > fin[3005];
vector<pair<int, int> > fout[3005];
int p[4];
int bp[4];
int bl;
void upd() {
  int l = 0;
  for (int i = (0); i < (3); i++) l += sp[p[i]][p[i + 1]];
  if (l > bl) {
    for (int i = (1); i < (4); i++)
      for (int j = (0); j < (i); j++)
        if (p[i] == p[j]) return;
    for (int i = (0); i < (4); i++) bp[i] = p[i];
    bl = l;
  }
}
int q[3005], qs, qe;
int main() {
  scanf("%d%d", &n, &m);
  for (int z = (0); z < (m); z++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    u[x].push_back(y);
  }
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++) sp[i][j] = 1e5;
    qs = qe = 0;
    q[qe++] = i;
    sp[i][i] = 0;
    while (qs != qe) {
      int f = q[qs++];
      for (int j : u[f]) {
        if (sp[i][j] > 1e4) {
          sp[i][j] = sp[i][f] + 1;
          q[qe++] = j;
        }
      }
    }
  }
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++)
      if (j != i && sp[j][i] < 1e4) {
        fin[i].emplace_back(sp[j][i], j);
        if (int(fin[i].size()) > 3) {
          sort(fin[i].begin(), fin[i].end());
          fin[i].erase(fin[i].begin());
        }
      }
    for (int j = (0); j < (n); j++)
      if (j != i && sp[i][j] < 1e4) {
        fout[i].emplace_back(sp[i][j], j);
        if (int(fout[i].size()) > 3) {
          sort(fout[i].begin(), fout[i].end());
          fout[i].erase(fout[i].begin());
        }
      }
  }
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++)
      if (i != j && sp[i][j] < 1e4) {
        p[1] = i;
        p[2] = j;
        for (auto &f : fin[i])
          for (auto &e : fout[j]) {
            p[0] = f.second;
            p[3] = e.second;
            upd();
          }
      }
  for (int i = (0); i < (4); i++) printf("%d%c", 1 + bp[i], " \n"[i == 3]);
}
