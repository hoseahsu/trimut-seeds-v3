#include <bits/stdc++.h>
using namespace std;
int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
bool prime_check(long long int n) {
  long long int i, j;
  if (n == 1) {
    return false;
  }
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long int fact(long long int n) {
  long long int prod = 1;
  for (long long int i = 1; i <= n; i++) {
    prod = (prod * i) % 1000000007;
  }
  return prod;
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, u, v;
  cin >> n;
  int freq[100003] = {};
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    freq[u]++;
    freq[v]++;
  }
  for (i = 0; i < n; i++) {
    if (freq[i] == 2) break;
  }
  if (i == n)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
