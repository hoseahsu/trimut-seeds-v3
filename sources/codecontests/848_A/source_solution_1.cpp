#include <bits/stdc++.h>
using namespace std;
const int M = 5e6 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 9e18;
const double pi = 3.14159265358979323846;
long long int t, n, m, x, sum, k, p, u = 0;
string s, z, ans = "";
long long int P[10000005] = {0};
void sieve() {
  for (long long int i = 2; i < (10000005); i++)
    if (!P[i])
      for (long long int j = i * i; j < (10000005); j += i) P[j] = i;
}
long long int raised(long long int x, long long int v) {
  if (v == 0) return 1 % mod;
  if (v % 2 == 1) return (x * raised(x, v - 1)) % mod;
  long long int r = raised(x, v / 2);
  return (r * r) % mod;
}
bool prime(long long int n) {
  if (n == 1) return 1;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int hcf(long long int a, long long int b) {
  if (a % b == 0) return b;
  return hcf(b, a % b);
}
bool comp(long long int a, long long int b) { return (a < b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t1 = 1;
  cin >> n;
  z = "";
  for (long long int j = 0; j < 26; j++) {
    for (long long int i = 3000; i > 0; i--) {
      if (i * (i - 1) / 2 <= n) {
        n -= i * (i - 1) / 2;
        string g(i, 'a' + j);
        z += g;
        break;
      }
    }
    if (!n) break;
  }
  cout << z;
}
