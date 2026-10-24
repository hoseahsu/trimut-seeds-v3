#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 998244353;
int n, k;
int main() {
  cin >> n;
  for (int i = 1; i <= n * 2 / 3; i++) printf("0 %d\n", i);
  for (int i = 1; i <= n - (n * 2 / 3); i++) printf("3 %d\n", i * 2);
  return 0;
}
