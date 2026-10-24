#include <bits/stdc++.h>
using namespace std;
bool isprefix(string a, string b) {
  if (a.size() <= b.size() && b.substr(0, a.size()) == a) return 1;
  return 0;
}
vector<string> fixed;
char arr[101][101];
int main() {
  string a, b;
  cin >> a >> b;
  string c = a;
  sort(c.begin(), c.end());
  int l = 0;
  for (int i = 0; i < c.size(); ++i) {
    if (c[i] != '0') break;
    l++;
  }
  if (l == c.size()) {
    if (a == b)
      cout << "OK" << endl;
    else
      cout << "WRONG_ANSWER" << endl;
    return 0;
  }
  string res = "";
  res += c[l];
  for (int i = 0; i < l; ++i) {
    res += '0';
  }
  res += c.substr(l + 1);
  cerr << res << endl;
  if (res == b)
    cout << "OK" << endl;
  else
    cout << "WRONG_ANSWER" << endl;
}
