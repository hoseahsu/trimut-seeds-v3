#include <bits/stdc++.h>
using namespace std;
int main() {
  string pass;
  int n;
  cin >> pass >> n;
  string bark;
  bool solved = false, e = false, s = false;
  for (int i = 0; i < n; i++) {
    cin >> bark;
    if (bark == pass) solved = true;
    if (bark.at(1) == pass.at(0)) e = true;
    if (bark.at(0) == pass.at(1)) s = true;
  }
  cout << ((solved || (s && e)) ? "YES" : "NO");
  return 0;
}
