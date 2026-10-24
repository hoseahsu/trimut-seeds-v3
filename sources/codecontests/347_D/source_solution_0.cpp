#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 1;
string s1, s2, v;
int dyn[N][N][N];
int vu[N][N][N];
int p[N][26];
int f(int i, int j, int k) {
  if (k == v.size()) return -N;
  if (i == s1.size() || j == s2.size()) return 0;
  if (!vu[i][j][k]) {
    vu[i][j][k] = true;
    dyn[i][j][k] = max(f(i + 1, j, k), f(i, j + 1, k));
    if (s1[i] == s2[j]) {
      dyn[i][j][k] = max(dyn[i][j][k], f(i + 1, j + 1, p[k][s1[i] - 'A']) + 1);
    }
  }
  return dyn[i][j][k];
}
void g(int i, int j, int k, string s) {
  if (i == s1.size() || j == s2.size()) {
    cout << s << endl;
    return;
  }
  if (dyn[i][j][k] == dyn[i + 1][j][k])
    g(i + 1, j, k, s);
  else if (dyn[i][j][k] == dyn[i][j + 1][k])
    g(i, j + 1, k, s);
  else
    g(i + 1, j + 1, p[k][s1[i] - 'A'], s + s1[i]);
}
int main() {
  cin >> s1 >> s2 >> v;
  for (int i = 0; i < v.size(); i++)
    for (char j = 'A'; j <= 'Z'; j++)
      for (int k = 0; k <= i; k++)
        if (v.substr(k, i - k) + j == v.substr(0, i - k + 1)) {
          p[i][j - 'A'] = i - k + 1;
          break;
        }
  int r = f(0, 0, 0);
  if (r == 0)
    cout << 0 << endl;
  else
    g(0, 0, 0, "");
  return 0;
}
