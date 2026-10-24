#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  long long int cnt = 0, sum = 0;
  for (int i = 0; i < k; i++) {
    long long int x, y;
    cin >> x >> y;
    x--;
    cnt += y;
    sum = (sum + x * y) % n;
  }
  if (cnt > n or (cnt == n and sum != n * (n - 1) / 2 % n))
    cout << -1 << endl;
  else
    cout << 1 << endl;
  return 0;
}
