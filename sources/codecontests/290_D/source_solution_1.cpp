#include <bits/stdc++.h>
using namespace std;
int main() {
  string s27;
  int n16;
  cin >> s27 >> n16;
  for (int i = 0; i < s27.size(); i++) {
    char c = s27[i];
    int d = 0;
    if (c >= 'a' && c <= 'z')
      d = c - 'a';
    else
      d = c - 'A';
    if (d + 'a' < n16 + 97)
      s27[i] = 'A' + d;
    else
      s27[i] = 'a' + d;
  }
  cout << s27;
}
