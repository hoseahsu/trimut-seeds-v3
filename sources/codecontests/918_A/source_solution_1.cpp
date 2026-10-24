#include <bits/stdc++.h>
using namespace std;
int a[32] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
bool fun(int x) {
  for (int i = 1; i <= 30; i++)
    if (a[i] == x) return true;
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (fun(i))
      cout << "O";
    else
      cout << 'o';
  }
  cout << endl;
  return 0;
}
