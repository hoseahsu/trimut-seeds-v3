#include <bits/stdc++.h>
using namespace std;
ifstream in("pairs.in");
ofstream out("pairs.out");
const int DIM = 1e5 + 5;
int nxt[DIM], val[DIM], pos[DIM];
pair<int, int> tdp[DIM][2], cdp[DIM], arr[2][DIM];
deque<int> chn;
bitset<DIM> oki, mrk, ist;
vector<pair<int, int>> sol;
vector<int> edg[DIM];
pair<int, int> operator+(const pair<int, int> &p1, const pair<int, int> &p2) {
  return pair<int, int>(p1.first + p2.first, p1.second + p2.second);
}
pair<int, int> operator-(const pair<int, int> &p1, const pair<int, int> &p2) {
  return pair<int, int>(p1.first - p2.first, p1.second - p2.second);
}
void calcdp(int x) {
  mrk[x] = true;
  pos[x] = 0;
  tdp[x][0] = tdp[x][1] = pair<int, int>(0, 0);
  for (int y : edg[x]) {
    calcdp(y);
    tdp[x][0] = tdp[x][0] + max(tdp[y][0], tdp[y][1]);
    pair<int, int> aux = tdp[y][0] - max(tdp[y][0], tdp[y][1]) +
                         pair<int, int>(1, val[x] != val[y]);
    if (tdp[x][1] < aux) tdp[x][1] = aux, pos[x] = y;
  }
  tdp[x][1] = tdp[x][1] + tdp[x][0];
}
int _nr[2];
void solvedp(int x, bool ok, int nr) {
  if (ok and pos[x]) arr[nr][++_nr[nr]] = make_pair(x, pos[x]);
  for (int y : edg[x]) solvedp(y, (ok and y == pos[x]) ? false : true, nr);
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &nxt[i], &val[i]);
    edg[nxt[i]].push_back(i);
  }
  pair<int, int> ans;
  for (int i = 1; i <= n; ++i)
    if (!mrk[i]) {
      chn.clear();
      for (int x = i; true; x = nxt[x]) {
        chn.push_back(x);
        if (!oki[x])
          oki[x] = true;
        else {
          while (chn.front() != chn.back())
            oki[chn.front()] = false, chn.pop_front();
          break;
        }
      }
      pair<int, int> pr1, pr2;
      edg[chn[1]].erase(find(edg[chn[1]].begin(), edg[chn[1]].end(), chn[0]));
      calcdp(chn[0]);
      _nr[0] = 0;
      solvedp(chn[0], true, 0);
      edg[chn[1]].push_back(chn[0]);
      pr1 = max(tdp[chn[0]][0], tdp[chn[0]][1]);
      edg[chn[2]].erase(find(edg[chn[2]].begin(), edg[chn[2]].end(), chn[1]));
      calcdp(chn[1]);
      _nr[1] = 0;
      solvedp(chn[1], true, 1);
      edg[chn[2]].push_back(chn[1]);
      pr2 = max(tdp[chn[1]][0], tdp[chn[1]][1]);
      if (pr1 > pr2) {
        ans = ans + pr1;
        for (int i = 1; i <= pr1.first; ++i) sol.push_back(arr[0][i]);
      } else {
        ans = ans + pr2;
        for (int i = 1; i <= pr2.first; ++i) sol.push_back(arr[1][i]);
      }
    }
  printf("%d %d\n", ans.first, ans.second);
  for (pair<int, int> pr : sol) printf("%d %d\n", pr.first, pr.second);
  return 0;
}
