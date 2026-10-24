#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200200;
int main() {
  long long n, r[MAXN], a, b, c = 0, last = 0;
  memset(r, 0, sizeof r);
  map<long long, long long> m;
  scanf("%I64d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%I64d %I64d", &a, &b), m[a - 1] += 1, m[b] -= 1;
  for (pair<const long long, long long>& p : m) {
    r[c] += p.first - last;
    c += p.second;
    last = p.first;
  }
  for (int i = 1; i <= n; ++i) printf("%I64d ", r[i]);
}
