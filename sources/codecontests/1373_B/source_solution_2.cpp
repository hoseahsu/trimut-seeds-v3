#include <bits/stdc++.h>
using namespace std;
int prime[1000000];
vector<int> pr;
void calculateprime() {
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (prime[i] == 0) {
      pr.push_back(i);
      for (long long j = i * 2; j <= 1000000; j += i) {
        prime[j] = 1;
      }
    }
  }
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool isprime(long long n) {
  for (long long i = 2; (long long)i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long fib(int n) {
  long long a = 0, b = 1, c, i;
  if (n == 0) return a;
  for (i = 2; i <= n; i++) {
    c = (a + b);
    a = b;
    b = c;
  }
  return b;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extendedgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extendedgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long findgrouplcm(vector<int> &arr, int n) {
  long long ans = arr[0];
  for (long long i = 1; i < n; i++) ans = (arr[i] * (ans / (gcd(arr[i], ans))));
  return ans;
}
long long powerwithmod(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
  if (a.first == b.first) return a.second < b.second;
}
void solve() {
  string str;
  cin >> (str);
  int n = str.size();
  int one = 0, zero = 0;
  for (long long i = 0; i < n; i++) {
    if (str[i] == '1')
      ++one;
    else
      ++zero;
  }
  int i = 0, cnt = 0;
  while (!str.empty() and one and zero) {
    if (str[i] != str[i + 1]) {
      if (i == 0) {
        i = 2;
        str.erase(i, 2);
      } else {
        --i;
      }
      --one;
      --zero;
      ++cnt;
    } else
      ++i;
  }
  if (cnt & 1)
    cout << "DA"
         << "\n";
  else
    cout << "NET"
         << "\n";
}
int main() {
  fast();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
