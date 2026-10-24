#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) return 0;
  if (a == b) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
vector<long long int> primes;
bool prime[1000001];
void pre() {
  for (long long int i = 2; i <= 1000000; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (long long int j = 2 * i; j <= 1000000; j += i) prime[j] = false;
    }
  }
}
bool isAPowerOf2(long long int n) { return (n != 0 && (n & (n - 1)) == 0); }
int main() {
  ios_base::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  memset(prime, true, sizeof(prime));
  pre();
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "1 0";
    return 0;
  }
  long long int answer = 1;
  long long int op = 0;
  set<long long int, greater<long long int>> s1;
  for (long long int i = 0; i < primes.size(); i++) {
    if (n < primes[i]) break;
    if (n % primes[i]) continue;
    long long int count = 0, temp = 0;
    while (n % primes[i] == 0) {
      count++;
      n /= primes[i];
    }
    answer *= primes[i];
    s1.insert(count);
  }
  long long int final = *s1.begin();
  if (s1.size() != 1 || (!isAPowerOf2(final))) {
    op++;
  }
  if (isAPowerOf2(final)) op--;
  while (final) {
    final /= 2;
    op++;
  }
  cout << answer << ' ' << op;
  int dont_hack_please;
  return 0;
}
