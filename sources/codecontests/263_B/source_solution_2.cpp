#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, i, e, f, g, n, m, k, l, A[100005];
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> A[i];
  if (n < k) {
    cout << -1;
    return 0;
  }
  sort(A + 1, A + 1 + n);
  cout << A[n - k + 1] << " " << 0;
}
