#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  if (n & 1)
    ans = (n >> 1) + 1;
  else
    ans = (n >> 1);
  cout << ans;
  return 0;
}
