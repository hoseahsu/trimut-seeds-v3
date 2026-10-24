#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long MOD1 = 1e9 + 123;
long long MOD2 = 1e9 + 321;
vector<int> fun(string &s) {
  int i;
  vector<int> v;
  for (i = 0; i + 1 < s.length(); i++)
    if (s[i] != s[i + 1]) v.push_back(i + 1);
  if (s[s.length() - 1] == '1') v.push_back(s.length());
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t, a, n, q, k, i, l, m, c, u, f, j, p, r, x, y, s, b, d;
  cin >> t;
  while (t--) {
    cin >> n;
    string S, P;
    cin >> S >> P;
    vector<int> v1, v2;
    v1 = fun(S);
    v2 = fun(P);
    reverse(v2.begin(), v2.end());
    cout << v1.size() + v2.size() << " ";
    for (auto h : v1) cout << h << " ";
    for (auto h : v2) cout << h << " ";
    cout << "\n";
  }
  return 0;
}
