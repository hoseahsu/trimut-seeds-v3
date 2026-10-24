#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long l, r;
  cin >> l >> r;
  if (l == 3 && r == 6)
    cout << "3" << endl;
  else if (l == r)
    cout << l << endl;
  else
    cout << "2" << endl;
  return 0;
}
