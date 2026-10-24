#include <bits/stdc++.h>
using namespace std;
string singlept(int pt, int val) {
  ostringstream sstr;
  sstr << "(((abs((1-abs((t-" << pt << "))))-abs((t-" << pt << ")))+1)*"
       << val / 2 << ")";
  return sstr.str();
}
int main() {
  int n, x, y, r;
  cin >> n >> x >> y >> r;
  string retf, rets;
  for (int i = 1; i < n; i++) {
    retf += "(";
    rets += "(";
  }
  retf += singlept(0, x);
  rets += singlept(0, y);
  for (int i = 1; i < n; i++) {
    cin >> x >> y >> r;
    retf += "+" + singlept(i, x) + ")";
    rets += "+" + singlept(i, y) + ")";
  }
  cout << retf << '\n' << rets << '\n';
  return 0;
}
