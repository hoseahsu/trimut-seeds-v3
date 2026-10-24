#include <bits/stdc++.h>
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const double pi = 3.1415926535897932384626433832795;
using namespace std;
int f[27][5003][27];
long double kol[3000];
long double canwin[30][5010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  long double ans = 0;
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<string, int> > v;
  for (int i = 1; i <= n; i++) {
    v.push_back({s, i});
    for (int j = 0; j < n; j++) f[s[0] - 'a'][j][s[j] - 'a']++;
    char k = s[0];
    s.erase(0, 1);
    s = s + k;
  }
  for (int i = 0; i < n; i++) {
    s = v[i].first;
    int ff = 0;
    for (int j = 0; j < n; j++)
      if (f[s[0] - 'a'][j][s[j] - 'a'] == 1) ff = 1;
    if (ff == 1) {
      for (int j = 0; j < n; j++)
        if (f[s[0] - 'a'][j][s[j] - 'a'] == 1) {
          canwin[s[0] - 'a'][j]++;
        }
    }
    kol[s[0]]++;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    long double ch = 0;
    long double kk = 0;
    for (int j = 0; j < n; j++) kk += canwin[i - 'a'][j];
    for (int j = 0; j < n; j++) ch = max(ch, canwin[i - 'a'][j]);
    ans += ch;
  }
  cout << fixed << setprecision(8) << ans / n << endl;
  return 0;
}
