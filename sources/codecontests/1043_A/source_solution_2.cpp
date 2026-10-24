#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void bruce(int n, vector<int> v) {
  cout << "\nExpected answer:\n";
  int k = 0, total = 0, sum = 0;
  for (int K = 0; K < n; K++) {
    k = max(k, v[K]);
  }
  for (int K = 0; K < n; K++) total += v[K];
  for (int K = 0; K < n; K++) {
    v[K] = k - v[K];
    sum += v[K];
  }
  for (int K = k;; K++) {
    if (sum > total) {
      cout << K << "\n";
      break;
    }
    sum += n;
  }
  cout << "\nAnswer recieved:\n";
}
void task() {
  int n, k = 0, ans, total = 0, sum = 0;
  cin >> n;
  vector<int> ara(n);
  for (int K = 0; K < n; K++) cin >> ara[K];
  for (int K = 0; K < n; K++) {
    k = max(k, ara[K]);
    total += ara[K];
  }
  for (int K = 0; K < n; K++) {
    ara[K] = k - ara[K];
    sum += ara[K];
  }
  if (sum > total) {
    cout << k << "\n";
    return;
  }
  ans = (int)(total - sum) / n;
  ans++;
  ans += k;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  task();
  return 0;
}
