#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = n / 2;
  cout << x << endl;
  if (n % 2 == 0)
    for (int i = 0; i < x; i++)
      cout << "2"
           << " ";
  else {
    for (int i = 0; i < x - 1; i++)
      cout << "2"
           << " ";
    cout << 3;
  }
  return 0;
}
