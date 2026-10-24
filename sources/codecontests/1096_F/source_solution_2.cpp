#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
  out << "[";
  for (int x : vec) out << x << ", ";
  out << "]";
  return out;
}
const long long int mod = 998244353;
long long int mod_pow(long long int a, long long int x) {
  if (x == 0) return 1;
  long long int k = mod_pow(a, x / 2);
  k = k * k % mod;
  if (x & 1) k = k * a % mod;
  return k;
}
long long int divide(long long int a, long long int b) {
  return a % mod * mod_pow(b, mod - 2) % mod;
}
int n;
long long int fen[200100];
int v[200100];
void upd(int a) {
  for (; a <= n; a += a & -a) v[a]++;
}
int sum(int a) {
  int ans = 0;
  for (; a > 0; a -= a & -a) ans += v[a];
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> a(n);
  long long int totx = 0;
  for (int i = 1; i <= n; i++) fen[i] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0)
      totx++;
    else
      fen[a[i]] = 0;
  }
  for (int i = 2; i <= n; i++) fen[i] += fen[i - 1];
  long long int ans = divide(totx * (totx - 1) / 2, 2);
  long long int x = 0;
  if (totx > 0)
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        ans = (ans +
               divide(fen[a[i]] * (totx - x) + (totx - fen[a[i]]) * x, totx)) %
              mod;
      } else {
        x++;
      }
    }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > 0) {
      ans = (ans + sum(a[i])) % mod;
      upd(a[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}
