#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (auto& i : s) i == '-' ? a++ : b++;
  if (a == 0 or b == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (a % b == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
