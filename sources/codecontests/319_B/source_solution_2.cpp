#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int A[N];
int steps[N] = {0};
stack<int> s;
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  int ans = 0;
  steps[n] = 0;
  s.push(n);
  for (i = n - 1; i >= 1; i--) {
    while (!s.empty() && A[i] > A[s.top()]) {
      steps[i] = max(steps[i] + 1, steps[s.top()]);
      s.pop();
    }
    s.push(i);
    ans = max(ans, steps[i]);
  }
  printf("%d\n", ans);
  return 0;
}
