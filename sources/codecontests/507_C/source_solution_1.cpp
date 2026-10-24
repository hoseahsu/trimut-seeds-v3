#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
long long ans = 0, h;
void recur(long long cur, long long node, long long i, long long f) {
  if (h == i) return;
  if (f == 0) {
    if (node > cur / 2) {
      ans += cur;
      recur(cur / 2, node - cur / 2, i + 1, 0);
    } else {
      ans++;
      recur(cur / 2, node, i + 1, 1);
    }
  } else {
    if (node > cur / 2) {
      ans++;
      recur(cur / 2, node - cur / 2, i + 1, 0);
    } else {
      ans += cur;
      recur(cur / 2, node, i + 1, 1);
    }
  }
  return;
}
int main() {
  long long int i, j, n, m, k;
  cin >> h >> m;
  j = (long long)pow(2, h);
  recur(j, m, 0, 0);
  cout << ans << '\n';
}
