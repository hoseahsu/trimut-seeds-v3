#include <bits/stdc++.h>
using namespace std;
int sdf = 0;
bool equi(string a, string b) {
  int l = a.size();
  if (l % 2 == 1) return a == b;
  if (a == b)
    return 1;
  else
    return (equi(a.substr(0, l / 2), b.substr(l / 2, l / 2)) &&
            equi(b.substr(0, l / 2), a.substr(l / 2, l / 2))) ||
           (equi(a.substr(0, l / 2), b.substr(0, l / 2)) &&
            equi(b.substr(l / 2, l / 2), a.substr(l / 2, l / 2)));
}
int main() {
  string a, b;
  cin >> a >> b;
  if (equi(a, b))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
