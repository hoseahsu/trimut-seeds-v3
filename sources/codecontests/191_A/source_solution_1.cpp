#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
const int N = 5e5 + 5;
int n;
int positions[26][N];
string names[N];
ll values[N][26];
void dp() {
  for (int idx = n; idx > 0; idx--)
    for (char ch = 'a'; ch <= 'z'; ch++) {
      char last = names[idx].back();
      char first = names[idx][0];
      ll v1 = INT_MIN, v2 = INT_MIN, v3 = INT_MIN;
      if (ch == last) v1 = names[idx].size();
      if (positions[last - 'a'][idx + 1] != n + 1) {
        int pos = positions[last - 'a'][idx + 1];
        v2 = names[idx].size() + values[pos][ch - 'a'];
      }
      if (positions[first - 'a'][idx + 1] != n + 1) {
        int pos = positions[first - 'a'][idx + 1];
        v3 = values[pos][ch - 'a'];
      }
      values[idx][ch - 'a'] = max({v1, v2, v3});
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  for (int i = 1; i <= 500000; i++)
    for (int j = 0; j < 26; j++) values[i][j] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> names[i];
  for (int i = 1; i <= n; i++) positions[names[i][0] - 'a'][i] = 1;
  for (int i = 0; i < 26; i++) {
    positions[i][n + 1] = n + 1;
    for (int j = n; j > 0; j--)
      if (positions[i][j])
        positions[i][j] = j;
      else
        positions[i][j] = positions[i][j + 1];
  }
  dp();
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, values[i][names[i][0] - 'a']);
  cout << ans;
}
