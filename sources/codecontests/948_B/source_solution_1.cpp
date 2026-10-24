#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SIZE = 1e6 + 100;
constexpr int inf = 1e9;
bool prime[SIZE];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(std::time(nullptr));
  int n;
  cin >> n;
  for (int i = 2; i < SIZE; i++) {
    prime[i] = true;
  }
  vector<int> primes;
  for (ll i = 2; i < SIZE; i++) {
    if (prime[i]) {
      for (ll j = i * i; j < SIZE; j += i) {
        prime[j] = false;
      }
      primes.push_back(i);
    }
  }
  set<int> w;
  for (int p : primes) {
    if (p > n) break;
    if (n % p != 0) continue;
    for (int i = n - p + 1; i <= n; i++) {
      if (i >= 3) w.insert(i);
    }
  }
  int ans = inf;
  for (int cand : w) {
    if (ans < cand / 2) break;
    for (int p : primes) {
      if (p > cand) break;
      if (cand % p != 0) continue;
      for (int i = cand - p + 1; i <= cand; i++) {
        if (i >= 3 && p < i) {
          ans = min(ans, i);
        }
      }
    }
  }
  cout << ans << "\n";
}
