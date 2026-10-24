#include <bits/stdc++.h>
using namespace std;
int a[100666], DR[100666], ST[100666];
vector<int> H[100666 * 5];
int S[100666 * 5], D[100666 * 5];
int sp[100666], ec[100666], ts[100666];
int result[100666];
bool comp(int i1, int i2) { return a[i1] > a[i2]; }
bool comp2(int i1, int i2) { return DR[i1] < DR[i2]; }
void addi(int st, int dr, int nod, int X, int Y, int ind) {
  S[nod] = st;
  D[nod] = dr;
  if (st >= X && dr <= Y) {
    H[nod].push_back(ind);
    return;
  }
  int mij = (st + dr) / 2;
  if (mij >= X) addi(st, mij, nod * 2, X, Y, ind);
  if (mij + 1 <= Y) addi(mij + 1, dr, nod * 2 + 1, X, Y, ind);
}
void solve(int st_ec, int dr_ec, int st_time, int dr_time) {
  int mij = (st_time + dr_time) / 2, i, mv = (1 << 30), mvind;
  for (i = st_ec; i <= dr_ec; ++i)
    if (-sp[ec[i]] + a[ec[i]] * (DR[ts[mij]] - ec[i] + 1) < mv)
      mv = -sp[ec[i]] + a[ec[i]] * (DR[ts[mij]] - ec[i] + 1), mvind = i;
  if (dr_time - st_time == 0) {
    result[ts[mij]] = min(result[ts[mij]], mv);
    return;
  }
  solve(mvind, dr_ec, mij + 1, dr_time);
  solve(st_ec, mvind, st_time, mij);
}
int main() {
  int n, i, m;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[n - i + 1];
  cin >> m;
  for (i = 1; i <= m; ++i) {
    int xx, yy;
    cin >> xx >> yy;
    DR[i] = n - (yy - (xx - 1)) + 1;
    ST[i] = n - yy + 1;
    addi(1, n, 1, ST[i], DR[i], i);
  }
  for (i = n; i > 0; --i) sp[i] = a[i] + sp[i + 1];
  for (i = 1; i <= m; ++i) result[i] = (1 << 30);
  for (i = 1; i <= n * 4; ++i)
    if (H[i].empty() == false) {
      int K = 0;
      for (int j = S[i]; j <= D[i]; ++j) ec[++K] = j;
      sort(ec + 1, ec + K + 1, comp);
      int N = H[i].size();
      for (int j = 0; j < N; ++j) ts[j + 1] = H[i][j];
      sort(ts + 1, ts + N + 1, comp2);
      solve(1, K, 1, N);
    }
  for (i = 1; i <= m; ++i)
    cout << result[i] + sp[DR[i] + 1] + sp[ST[i]] - sp[DR[i] + 1] << '\n';
  return 0;
}
