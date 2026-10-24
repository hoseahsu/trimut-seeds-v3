#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const long long mod = 1e9 + 7;
int num[205];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s, j;
    s = j = 0;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
    }
    for (int i = 2; i <= n; i++) {
      if (num[i] > num[i - 1])
        s++;
      else
        j++;
    }
    if (num[n] > num[1])
      j++;
    else
      s++;
    if (s < 2 || j < 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
