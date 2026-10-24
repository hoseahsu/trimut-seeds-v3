#include <bits/stdc++.h>
using namespace std;
int o = 0, m;
long long int n, k = 1;
int main() {
  (scanf("%lld%lld", &n, &m));
  while (m != o && k < n) {
    o++;
    k += m - o;
  }
  if (k >= n)
    cout << o;
  else
    cout << -1;
}
