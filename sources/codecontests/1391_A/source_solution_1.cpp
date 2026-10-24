#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
long long const md = 998244353;
long long mypowr(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long mypow(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
ifstream in("input.txt");
ofstream out("output.txt");
unordered_map<int, int> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
