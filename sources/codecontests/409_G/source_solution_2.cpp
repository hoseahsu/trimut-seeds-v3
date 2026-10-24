#include <bits/stdc++.h>
using namespace std;
int a[128][128];
int main() {
  string str1, str2;
  double a, b;
  int n;
  double ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans += b;
  }
  cout << ans / n + 5 << endl;
  return 0;
}
