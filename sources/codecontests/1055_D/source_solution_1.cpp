#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
string t;
int pi[2 * MAXN];
void calc() {
  int n = t.size();
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && t[i] != t[j]) j = pi[j - 1];
    if (t[i] == t[j]) ++j;
    pi[i] = j;
  }
}
int n;
string a[MAXN], b[MAXN];
void solve() {
  int id;
  int idl;
  int idr;
  int idlen;
  for (id = 0; id < n; id++) {
    idl = -1;
    idlen = a[id].size();
    for (int j = 0; j < idlen; j++) {
      if (a[id][j] != b[id][j]) {
        idl = j;
        break;
      }
    }
    if (idl >= 0) {
      idr = idlen - 1;
      for (int j = idlen - 1; j >= idl; j--) {
        if (a[id][j] != b[id][j]) {
          idr = j;
          break;
        }
      }
      break;
    }
  }
  int L = 0, R = idlen - 1;
  for (int i = id + 1; i < n; i++) {
    int l = -1;
    int len = a[i].size();
    for (int j = 0; j < len; j++) {
      if (a[i][j] != b[i][j]) {
        l = j;
        break;
      }
    }
    if (l >= 0) {
      int r = len - 1;
      for (int j = len - 1; j >= l; j--) {
        if (a[i][j] != b[i][j]) {
          r = j;
          break;
        }
      }
      if (r - l == idr - idl) {
        for (int j = l; j <= r; j++) {
          if (a[i][j] != a[id][idl + j - l] || b[i][j] != b[id][idl + j - l]) {
            cout << "NO" << endl;
            return;
          }
        }
        int ld = 0;
        while (idl - (ld + 1) >= 0 && l - (ld + 1) >= 0 &&
               a[id][idl - (ld + 1)] == a[i][l - (ld + 1)] &&
               b[id][idl - (ld + 1)] == b[i][l - (ld + 1)]) {
          ld++;
        }
        int rd = 0;
        while (idr + (rd + 1) < idlen && r + (rd + 1) < len &&
               a[id][idr + (rd + 1)] == a[i][r + (rd + 1)] &&
               b[id][idr + (rd + 1)] == b[i][r + (rd + 1)]) {
          rd++;
        }
        L = max(L, idl - ld);
        R = min(R, idr + rd);
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  string pat = a[id].substr(L, R - L + 1);
  string to = b[id].substr(L, R - L + 1);
  int m = pat.length();
  for (int i = 0; i < n; i++) {
    t = pat + "#" + a[i];
    calc();
    for (size_t j = 2 * m; j < t.size(); j++) {
      if (pi[j] == m) {
        int k = j - 2 * m;
        for (int p = 0; p < m; p++) {
          a[i][k + p] = to[p];
        }
        break;
      }
    }
    if (a[i] != b[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  cout << pat << endl;
  cout << to << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    solve();
  }
}
