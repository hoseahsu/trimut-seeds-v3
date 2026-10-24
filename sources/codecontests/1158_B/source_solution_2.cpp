#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int t = (n - k) / 2;
  t++;
  for (int i = 1; i <= n; i++) {
    cout << (i % t == 0);
  }
}
