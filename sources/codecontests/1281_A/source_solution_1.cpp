#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int i = a.length() - 1;
    if (a[i] == 'o')
      cout << "FILIPINO" << endl;
    else if (a[i] == 'u')
      cout << "JAPANESE" << endl;
    else if (a[i] == 'a')
      cout << "KOREAN" << endl;
  }
  return 0;
}
