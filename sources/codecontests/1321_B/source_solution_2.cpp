#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, M = 4e5 + 2;
int n;
int b[N], c[N];
long long d[1000000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> b[i], c[i] = i - b[i], d[c[i] + M] += 1ll * b[i];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, d[c[i] + M]);
  cout << ans;
}
