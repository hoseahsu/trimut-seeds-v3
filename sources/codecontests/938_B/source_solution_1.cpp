#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans *= a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long powm(long long a, long long b) {
  a %= MOD;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ans;
}
void IO() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  IO();
  ;
  int n;
  cin >> n;
  int A[n];
  for (int &x : A) cin >> x;
  if (n == 1) {
    cout << min(A[0] - 1, 1000000 - A[0]);
    return 0;
  }
  int ans = min(A[n - 1] - 1, 1000000 - A[0]);
  for (int i = n - 2; i >= 0; i--)
    ans = min(ans, (A[i] - 1 + (1000000 - A[i + 1])) -
                       min(A[i] - 1, 1000000 - A[i + 1]));
  cout << ans << "\n";
  return 0;
}
