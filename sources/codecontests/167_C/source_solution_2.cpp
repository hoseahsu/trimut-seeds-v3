#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a, b;
bool go(long long a, long long b) {
  if (a == 0 || b == 0) return false;
  if (a > b) swap(a, b);
  if (!go(a, b % a)) return true;
  long long moves = (b / a);
  if (a % 2 == 1) {
    return (moves % 2) == 0;
  } else {
    long long res = (moves % (a + 1));
    return (res % 2 == 0);
  }
}
void solve() {
  cin >> a >> b;
  bool who = go(a, b);
  if (who)
    cout << "First" << '\n';
  else
    cout << "Second" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tst;
  cin >> tst;
  while (tst--) solve();
  return 0;
}
