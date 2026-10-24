#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << endl;
  else {
    int x = n % 4;
    if (x == 0)
      cout << 6 << endl;
    else if (x == 1)
      cout << 8 << endl;
    else if (x == 2)
      cout << 4 << endl;
    else
      cout << 2 << endl;
  }
}
