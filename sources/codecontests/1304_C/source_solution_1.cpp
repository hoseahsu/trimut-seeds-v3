#include <bits/stdc++.h>
using namespace std;
struct cmr {
  long long int t, l, h;
};
int main() {
  int tt = 1;
  scanf("%d", &tt);
  ;
  while (tt--) {
    long long int i, n, flag = 1, ans = 0, ctemp = 0, time = 0, chigh = 0,
                        clow = 0;
    cin >> n >> ctemp;
    long long int plow = ctemp, phigh = ctemp;
    cmr cust[n];
    for (int i = 0; i < n; i++) cin >> cust[i].t >> cust[i].l >> cust[i].h;
    for (long long int i = 0; i < n && flag; i++) {
      if (cust[i].l > phigh + (cust[i].t - time))
        flag = 0;
      else if (cust[i].h < plow - (cust[i].t - time))
        flag = 0;
      clow = max(plow - (cust[i].t - time), cust[i].l);
      chigh = min(phigh + (cust[i].t - time), cust[i].h);
      time = cust[i].t;
      plow = clow;
      phigh = chigh;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
