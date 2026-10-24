#include <bits/stdc++.h>
using namespace std;
int c2i(char c) {
  if (c <= '9') return c - '0';
  return c - 'A' + 10;
}
long long conv(string s, int b) {
  for (register int i = (0); i < (int)(((int)(s).size())); ++i)
    if (c2i(s[i]) >= b) return -1U / 2;
  long long res = 0;
  for (register int i = (0); i < (int)(((int)(s).size())); ++i)
    res = res * b + c2i(s[i]);
  return res;
}
int main() {
  string tmp;
  cin >> tmp;
  for (register int i = (0); i < (int)(((int)(tmp).size())); ++i)
    if (tmp[i] == ':') tmp[i] = ' ';
  istringstream sin(tmp);
  string a, b;
  sin >> a >> b;
  vector<bool> base(1000, true);
  base[0] = base[1] = false;
  for (register int i = (2); i < (int)(1000); ++i)
    if (conv(a, i) >= 24 || conv(b, i) >= 60) base[i] = false;
  bool has = false;
  if (base[999]) {
    cout << -1 << "\n";
    return 0;
  }
  for (register int i = (0); i < (int)(1000); ++i)
    if (base[i]) {
      cout << i << " ";
      has = true;
    }
  if (!has) cout << "0";
  cout << "\n";
  return 0;
}
