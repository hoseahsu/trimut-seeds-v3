#include <bits/stdc++.h>
using namespace std;
const int MAX = 205, MAXL = 1 << 20;
char qq[MAXL];
char s[MAX][MAX];
pair<int, int> kamo[MAX][MAX];
vector<pair<int, int> > R[MAX][MAX];
int indeg[MAX][MAX];
int cik[MAX][MAX];
int imacik[MAX * MAX][10];
int brred, brstup;
int pr[10], ps[10];
int bio[MAX][MAX];
int dokle[MAX][MAX];
int imaq[MAXL][10];
int brc = 1;
int Vani(int red, int stup) {
  return red < 0 || red >= brred || stup < 0 || stup >= brstup;
}
void Osisaj() {
  queue<pair<int, int> > Q;
  for (int i = 0; i < brred; i++)
    for (int j = 0; j < brstup; j++)
      if (!indeg[i][j]) Q.push(pair<int, int>(i, j));
  for (; !Q.empty();) {
    pair<int, int> tmp = Q.front();
    bio[tmp.first][tmp.second] = 1;
    Q.pop();
    pair<int, int> nn = kamo[tmp.first][tmp.second];
    indeg[nn.first][nn.second]--;
    if (!indeg[nn.first][nn.second]) Q.push(nn);
  }
  for (int i = 0; i < brred; i++) {
    for (int j = 0; j < brstup; j++) {
      if (!bio[i][j]) {
        int sz = 0;
        for (pair<int, int> tmp = pair<int, int>(i, j);
             tmp != pair<int, int>(i, j) || !sz;
             sz++, tmp = kamo[tmp.first][tmp.second]) {
          bio[tmp.first][tmp.second] = 1;
          cik[tmp.first][tmp.second] = brc;
          imacik[brc][s[tmp.first][tmp.second] - '0'] = 1;
        }
        brc++;
      }
    }
  }
}
int Rijesi() {
  queue<pair<int, int> > Q;
  memset(dokle, 0, sizeof dokle);
  int len = (int)strlen(qq);
  for (int i = 0; i <= len; i++)
    for (int j = 0; j < 10; j++) imaq[i][j] = 0;
  for (int i = len - 1; i >= 0; i--) {
    imaq[i][qq[i] - '0'] = 1;
    for (int j = 0; j < 10; j++) imaq[i][j] |= imaq[i + 1][j];
  }
  for (int i = 0; i < brred; i++)
    for (int j = 0; j < brstup; j++) {
      indeg[i][j] = (int)R[i][j].size();
      if (!indeg[i][j]) Q.push(pair<int, int>(i, j));
    }
  for (; !Q.empty();) {
    pair<int, int> tmp = Q.front();
    Q.pop();
    int nd = dokle[tmp.first][tmp.second];
    if (s[tmp.first][tmp.second] == qq[nd]) nd++;
    if (nd == len) return 1;
    pair<int, int> nn = kamo[tmp.first][tmp.second];
    dokle[nn.first][nn.second] = max(dokle[nn.first][nn.second], nd);
    indeg[nn.first][nn.second]--;
    if (!indeg[nn.first][nn.second]) Q.push(nn);
  }
  for (int i = 0; i < brred; i++) {
    for (int j = 0; j < brstup; j++) {
      if (cik[i][j]) {
        int da = 1;
        int indc = cik[i][j];
        for (int k = 0; k < 10; k++)
          if (!imacik[indc][k] && imaq[dokle[i][j]][k]) da = 0;
        if (da) return 1;
      }
    }
  }
  return 0;
}
int main() {
  int brq;
  scanf("%d%d%d", &brred, &brstup, &brq);
  for (int i = 0; i < brred; i++) scanf("%s", s[i]);
  for (int i = 0; i < 10; i++) scanf("%d%d", &pr[i], &ps[i]);
  for (int i = 0; i < brred; i++) {
    for (int j = 0; j < brstup; j++) {
      int nr = i + pr[s[i][j] - '0'];
      int ns = j + ps[s[i][j] - '0'];
      if (Vani(nr, ns))
        kamo[i][j] = pair<int, int>(i, j);
      else
        kamo[i][j] = pair<int, int>(nr, ns);
      indeg[kamo[i][j].first][kamo[i][j].second]++;
      R[kamo[i][j].first][kamo[i][j].second].push_back(pair<int, int>(i, j));
    }
  }
  Osisaj();
  for (int i = 0; i < brq; i++) {
    scanf("%s", qq);
    printf("%s\n", Rijesi() ? "YES" : "NO");
  }
  return 0;
}
