#include <bits/stdc++.h>
using namespace std;
int vis[1001][1001];
int main() {
  map<string, int> mp;
  mp["Anka"] = 1;
  mp["Chapay"] = 2;
  mp["Cleo"] = 3;
  mp["Troll"] = 4;
  mp["Dracul"] = 5;
  mp["Snowy"] = 6;
  mp["Hexadecimal"] = 7;
  int n, i, j, k, a[3], b, c, par[] = {1, 2, 3, 4, 5, 6, 7}, cnt = 0, ii, jj;
  cin >> n;
  for (i = 0; i < n; i++) {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vis[mp[s1]][mp[s3]] = 1;
  }
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  int aa, bb, cc, dif = 2e9;
  for (i = 1; i <= 7; i++) {
    for (j = 1; j <= 7; j++) {
      if (7 - i - j <= 0) continue;
      int mx = -1, mn = 2e9, l[] = {7 - i - j, i, j};
      sort(l, l + 3);
      mx = max(mx, a[0] / l[0]), mn = min(mn, a[0] / l[0]);
      mx = max(mx, a[1] / l[1]), mn = min(mn, a[1] / l[1]);
      mx = max(mx, a[2] / l[2]), mn = min(mn, a[2] / l[2]);
      if ((mx - mn) <= dif) {
        aa = l[0], bb = l[1], cc = l[2];
        do {
          int y = 0;
          for (ii = 0; ii < aa; ii++) {
            for (jj = 0; jj < aa; jj++) {
              if (vis[par[ii]][par[jj]]) y++;
            }
          }
          for (ii = aa; ii < aa + bb; ii++) {
            for (jj = aa; jj < aa + bb; jj++) {
              if (vis[par[ii]][par[jj]]) y++;
            }
          }
          for (ii = aa + bb; ii < 7; ii++) {
            for (jj = aa + bb; jj < 7; jj++) {
              if (vis[par[ii]][par[jj]]) y++;
            }
          }
          if (dif == mx - mn)
            cnt = max(cnt, y);
          else
            cnt = y;
          dif = mx - mn;
        } while (next_permutation(par, par + 7));
      }
    }
  }
  cout << dif << ' ' << cnt;
}
