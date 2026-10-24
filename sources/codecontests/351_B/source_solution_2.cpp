#include <bits/stdc++.h>
using namespace std;
double num[3005];
int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
    for (int j = 0; j < i; ++j)
      if (num[j] > num[i]) res++;
  }
  int add = 1;
  int ans = 0;
  while (res != 0) {
    ans += (add);
    if (add == 1)
      add = 3;
    else
      add = 1;
    res--;
  }
  cout << fixed << setprecision(6) << (double)ans << endl;
  return 0;
}
