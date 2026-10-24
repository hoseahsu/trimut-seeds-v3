#include <bits/stdc++.h>
using namespace std;
inline long long Readint() {
  long long ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int MAXQ = 1000000;
const int LL = 21;
const int no = 4;
map<long long, int> ocr;
char s[24][3];
long long que[MAXQ];
int out[MAXQ];
double dp[MAXQ];
int vis[MAXQ];
int L = 0, R = 0;
vector<long long> to[MAXQ][3];
inline int make_id(long long hash) {
  if (ocr.count(hash)) return ocr[hash];
  ocr[hash] = R;
  que[R++] = hash;
  return R - 1;
}
int n;
long long get_hash(int len, char ss[][3], int R, int G, int B) {
  char s[24][3] = {0};
  long long ret = 0;
  for (int i = 1, _END_ = len; i <= _END_; i++)
    for (int j = 0, _END_ = 2; j <= _END_; j++) s[i][j] = ss[i][j];
  for (int i = len, _END_ = 1; i >= _END_; i--)
    if (s[i][0] > s[i][2]) swap(s[i][0], s[i][2]);
  int tmp[20] = {0};
  for (int i = len - 1, _END_ = 1; i >= _END_; i--) {
    for (int j = 0, _END_ = 2; j <= _END_; j++) tmp[i] = tmp[i] * 3 + s[i][j];
  }
  sort(tmp + 1, tmp + len);
  for (int i = len - 1; i >= 1; i--) ret = ret * 27 + tmp[i];
  ret = ret * LL + (len - 1);
  ret = ret * 10 + R;
  ret = ret * 10 + G;
  ret = ret * 10 + B;
  ret = ret * 4 + s[len][0];
  ret = ret * 4 + s[len][1];
  ret = ret * 4 + s[len][2];
  return ret;
}
void dfs(int id) {
  long long sta = que[id];
  char ltop[3];
  int lR, lG, lB;
  int lstlen;
  int nxtlen;
  int nR, nG, nB;
  char lst[24][3];
  char now[24][3];
  int flag = 0;
  long long now_hash;
  for (int j = 2, _END_ = 0; j >= _END_; j--) ltop[j] = sta % 4, sta /= 4;
  lB = sta % 10;
  sta /= 10;
  lG = sta % 10;
  sta /= 10;
  lR = sta % 10;
  sta /= 10;
  lstlen = sta % LL;
  sta /= LL;
  for (int i = 1, _END_ = lstlen; i <= _END_; i++)
    for (int j = 2, _END_ = 0; j >= _END_; j--) lst[i][j] = sta % 3, sta /= 3;
  for (int j = 0, _END_ = 2; j <= _END_; j++)
    if (ltop[j] == 3) flag = 1;
  for (int i = 1, _END_ = lstlen; i <= _END_; i++) {
    nxtlen = 0;
    for (int k = 1, _END_ = i - 1; k <= _END_; k++) {
      nxtlen++;
      for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = lst[k][j];
    }
    for (int k = i + 1, _END_ = lstlen; k <= _END_; k++) {
      nxtlen++;
      for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = lst[k][j];
    }
    nxtlen++;
    for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = ltop[j];
    if (!flag) {
      nxtlen++;
      for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = 3;
    }
    for (int j = 0, _END_ = 2; j <= _END_; j++) {
      nR = lR;
      nG = lG;
      nB = lB;
      if (j == 0) {
        if (lst[i][2] == 0)
          nR++;
        else if (lst[i][2] == 1)
          nG++;
        else
          nB++;
      } else if (j == 2) {
        if (lst[i][0] == 0)
          nR++;
        else if (lst[i][0] == 1)
          nG++;
        else
          nB++;
      }
      for (int k = 0, _END_ = 2; k <= _END_; k++)
        if (now[nxtlen][k] == 3) {
          now[nxtlen][k] = lst[i][j];
          now_hash = get_hash(nxtlen, now, nR, nG, nB);
          to[id][lst[i][j]].push_back(make_id(now_hash));
          out[id]++;
          now[nxtlen][k] = 3;
        }
    }
  }
  nxtlen = 0;
  for (int k = 1, _END_ = lstlen; k <= _END_; k++) {
    nxtlen++;
    for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = lst[k][j];
  }
  nxtlen++;
  for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = ltop[j];
  if (!flag) {
    nxtlen++;
    for (int j = 0, _END_ = 2; j <= _END_; j++) now[nxtlen][j] = 3;
  }
  if (lR) {
    lR--;
    for (int k = 0, _END_ = 2; k <= _END_; k++)
      if (now[nxtlen][k] == 3) {
        now[nxtlen][k] = 0;
        now_hash = get_hash(nxtlen, now, lR, lG, lB);
        to[id][0].push_back(make_id(now_hash));
        out[id]++;
        now[nxtlen][k] = 3;
      }
    lR++;
  }
  if (lG) {
    lG--;
    for (int k = 0, _END_ = 2; k <= _END_; k++)
      if (now[nxtlen][k] == 3) {
        now[nxtlen][k] = 1;
        now_hash = get_hash(nxtlen, now, lR, lG, lB);
        to[id][1].push_back(make_id(now_hash));
        out[id]++;
        now[nxtlen][k] = 3;
      }
    lG++;
  }
  if (lB) {
    lB--;
    for (int k = 0, _END_ = 2; k <= _END_; k++)
      if (now[nxtlen][k] == 3) {
        now[nxtlen][k] = 2;
        now_hash = get_hash(nxtlen, now, lR, lG, lB);
        to[id][2].push_back(make_id(now_hash));
        out[id]++;
        now[nxtlen][k] = 3;
      }
    lB++;
  }
}
double DP(int id) {
  if (vis[id]) return dp[id];
  vis[id] = 1;
  if (!out[id]) return dp[id] = 0;
  double res = 5.0 / 6;
  double ret = 1.0;
  double qwq;
  double dt;
  for (int i = 0, _END_ = 2; i <= _END_; i++) {
    if (i == 0)
      qwq = 1.0 / 6;
    else
      qwq = 2.0 / 6;
    if (to[id][i].size()) {
      dt = DP(to[id][i][0]);
      for (int j = 1, _END_ = to[id][i].size() - 1; j <= _END_; j++)
        dt = min(dt, DP(to[id][i][j]));
      ret += qwq * dt;
    } else
      res -= qwq;
  }
  dp[id] = ret / res;
  return dp[id];
}
void init() {
  scanf("%d", &n);
  for (int i = 1, _END_ = n; i <= _END_; i++) {
    scanf("%s", s[i]);
    for (int j = 0, _END_ = 2; j <= _END_; j++)
      if (s[i][j] == 'R')
        s[i][j] = 0;
      else if (s[i][j] == 'G')
        s[i][j] = 1;
      else
        s[i][j] = 2;
  }
  make_id(get_hash(n, s, 0, 0, 0));
  while (L < R) dfs(L++);
  printf("%.10lf\n", DP(0));
}
int main() {
  int _ = 0;
  init();
  close();
  return 0;
}
