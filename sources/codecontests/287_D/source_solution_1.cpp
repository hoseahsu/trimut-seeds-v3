#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 20 + 10;
deque<int> dq;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) dq.push_back(i);
  for (int i = 2; i < n + 1; i++) {
    for (int j = (n - 1) / i; j > 0; j--) swap(dq[(j - 1) * i], dq[j * i]);
    dq.push_back(dq.front());
    dq.pop_front();
  }
  for (int i = 0; i < n; i++) printf("%d ", dq[i]);
  return 0;
}
