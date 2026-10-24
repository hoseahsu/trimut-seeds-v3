#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.141592654;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int A = 0, F = 0, k = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'A')
      A++;
    else if (str[i] == 'F')
      F++;
    else
      k++;
  }
  if (k == 0)
    cout << A << endl;
  else if (k == 1)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
