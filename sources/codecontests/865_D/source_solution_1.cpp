#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> x;
int main() {
  int n, a;
  long long ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (x.empty() == 0 && x.top() < a) {
      ans += a - x.top();
      x.pop();
      x.push(a);
    }
    x.push(a);
  }
  cout << ans;
  return 0;
}
