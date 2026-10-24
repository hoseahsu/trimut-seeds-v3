#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int q, x;
  cin >> q >> x;
  long long int mex = 0;
  vector<long long int> chk(x, 0);
  for (long long int i = 0; i < q; i++) {
    long long int y;
    cin >> y;
    if (y == mex)
      mex++;
    else
      chk[y % x]++;
    while (chk[mex % x] > 0) chk[mex % x]--, mex++;
    cout << mex << endl;
  }
}
