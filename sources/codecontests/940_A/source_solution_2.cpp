#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n, d, ans = 0;
  int x[110] = {0};
  cin >> n >> d;
  int a, t = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    x[a]++;
  }
  for (int i = 1; i <= 100; i++) {
    if (x[i] != 0) {
      t = 0;
      for (int j = max(1, i - d); j <= i; j++) {
        t += x[j];
      }
    }
    ans = max(ans, t);
  }
  cout << n - ans;
  return 0;
}
