#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MAX_N = 100011;
const long long INF = (1 << 29) + 123;
const long long MOD = 1000000007;
const long double PI = 4 * atan((long double)1);
template <typename T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << " ";
  dbg_out(T...);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MX = 1 << 20;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int m = n;
  vector<int> LOC[n + 1];
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    LOC[A[i]].push_back(i);
  }
  int hi = 0, best = -1;
  for (int i = 1; i <= m; i++)
    if (ckmax(hi, (int)LOC[i].size())) best = i;
  bool done = 0;
  for (int i = 1; i <= m; i++)
    if (i != best && hi == (int)LOC[i].size()) done = 1;
  if (done) {
    cout << n << nl;
    return 0;
  }
  n += 2;
  int a[n];
  for (int i = 0; i < n - 2; i++) a[i + 1] = A[i];
  a[0] = a[n - 1] = best;
  vector<int> loc[n + 1];
  for (int i = 0; i < n; i++) loc[a[i]].push_back(i);
  hi = (int)loc[best].size();
  int idxBest[n];
  for (int i = 0; i < n; i++)
    if (i == 0)
      idxBest[i] = 1;
    else
      idxBest[i] = idxBest[i - 1] + (a[i] == best);
  int ans = 0;
  int SQRTN = sqrt(n) - 300;
  for (int i = 1; i <= m; i++) {
    int SZ = (int)loc[i].size();
    if (i == best || !SZ) continue;
    if (SZ > SQRTN) {
      int j = 0, k = 0;
      int sum = 0;
      int firstLoc[2 * n + 1];
      for (int ii = 0; ii < 2 * n + 1; ii++) firstLoc[ii] = -1;
      firstLoc[sum + n] = 0;
      while (j != hi - 1 || k != SZ) {
        int curPos;
        if (k < SZ && loc[best][j] > loc[i][k]) {
          curPos = loc[i][k] + 1;
          ckmax(ans, curPos - 1 - firstLoc[sum + n]);
          sum++;
          k++;
        } else {
          curPos = loc[best][j] + 1;
          ckmax(ans, curPos - 1 - firstLoc[sum + n]);
          sum--;
          j++;
        }
        if (firstLoc[sum + n] == -1) firstLoc[sum + n] = curPos;
      }
      ckmax(ans, loc[best][j] - firstLoc[sum + n]);
    } else {
      int kkk = 0;
      for (int kk = 0; kk < SZ; kk++) {
        int j = max(0, idxBest[loc[i][kk]] - SZ - 2);
        int jEnd = min(hi, idxBest[loc[i][kk]] + SZ + 2);
        while (kkk < SZ && loc[best][j] > loc[i][kkk]) kkk++;
        int k = kkk;
        int PAD = 2 * SZ + 5;
        int firstLoc[2 * PAD + 1];
        for (int ii = 0; ii < 2 * PAD + 1; ii++) firstLoc[ii] = -1;
        int sum = -1;
        if (j == 0) firstLoc[0 + PAD] = 0;
        firstLoc[sum + PAD] = loc[best][j] + 1;
        j++;
        while (j < jEnd) {
          int curPos;
          if (k < SZ && loc[i][k] < loc[best][j]) {
            curPos = loc[i][k] + 1;
            ckmax(ans, loc[i][k] - firstLoc[sum + PAD]);
            sum++;
            k++;
          } else {
            curPos = loc[best][j] + 1;
            ckmax(ans, loc[best][j] - firstLoc[sum + PAD]);
            sum--;
            j++;
          }
          if (firstLoc[sum + PAD] == -1) firstLoc[sum + PAD] = curPos;
        }
        if (j != hi) ckmax(ans, loc[best][j] - firstLoc[sum + PAD]);
      }
    }
  }
  cout << ans << nl;
  return 0;
}
