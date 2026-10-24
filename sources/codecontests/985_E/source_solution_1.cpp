#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double pi = 3.14159265358979323846264338327950288;
int main() {
  int n, k;
  long long d;
  cin >> n >> k >> d;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  queue<long long> q;
  q.push(0);
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == n) {
      cout << "YES" << endl;
      return 0;
    }
    cnt = max(cnt, u + k);
    while (cnt <= n && a[cnt - 1] - a[u] <= d) q.push(cnt), cnt++;
  }
  cout << "NO" << endl;
}
