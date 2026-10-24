#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch;
  cin >> ch;
  cin.ignore();
  string s;
  getline(cin, s);
  string a = "qwertyuiop";
  string b = "asdfghjkl;";
  string c = "zxcvbnm,./";
  int d = (ch == 'R') ? -1 : 1;
  for (int i = 0; i < s.size(); i++) {
    if (a.find(s[i]) != string::npos)
      cout << a[a.find(s[i]) + d];
    else if (b.find(s[i]) != string::npos)
      cout << b[b.find(s[i]) + d];
    else if (c.find(s[i]) != string::npos)
      cout << c[c.find(s[i]) + d];
  }
}
