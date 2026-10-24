#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, ds1, ds2;
  int b;
  b = 0;
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < s1.length(); i += 2) {
    ds1 = "";
    ds2 = "";
    ds1 += s1[i];
    ds1 += s1[i + 1];
    ds2 += s2[i];
    ds2 += s2[i + 1];
    if (ds1 == "8<" && ds2 == "[]")
      b++;
    else if (ds1 == "8<" && ds2 == "()")
      b--;
    else if (ds1 == "[]" && ds2 == "()")
      b++;
    else if (ds1 == "[]" && ds2 == "8<")
      b--;
    else if (ds1 == "()" && ds2 == "8<")
      b++;
    else if (ds1 == "()" && ds2 == "[]")
      b--;
  }
  if (b > 0)
    cout << "TEAM 1 WINS";
  else if (b < 0)
    cout << "TEAM 2 WINS";
  else
    cout << "TIE";
  return 0;
}
