#include <bits/stdc++.h>
using namespace std;
long long n, a[500], b[500], ans[500][4], l, r, smm, sum, k;
int flag = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  memset(b, 0, sizeof b);
  memset(a, 0, sizeof a);
  for (long long i = (1); i <= (n); i++) {
    cin >> a[i];
    if (a[i] != 0) flag = 1;
    b[i] = b[i - 1] + a[i];
  }
  if (flag == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    k = 0;
    r = n;
    l = 1;
    smm = 0;
    while (l <= n) {
      r = n;
      smm = b[r] - b[l - 1];
      while (smm == 0) {
        r--;
        smm = b[r] - b[l - 1];
      }
      k++;
      ans[k][1] = l;
      ans[k][2] = r;
      l = r + 1;
    }
    cout << k << endl;
    for (long long i = (1); i <= (k); i++) {
      cout << ans[i][1] << " " << ans[i][2] << endl;
    }
  }
  return 0;
}
