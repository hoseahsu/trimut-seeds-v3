#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long p = 1e9 + 7;
long long g[N];
int main() {
  int n, m;
  cin >> n >> m;
  g[1] = 1, g[2] = 2;
  int len = max(n, m);
  for (int i = 3; i <= len; i++) g[i] = g[i - 1] + g[i - 2] % p;
  long long Ans = g[n] + g[m] % p;
  Ans--;
  if (Ans < 0) Ans += p;
  Ans *= 2;
  Ans %= p;
  cout << Ans << endl;
}
