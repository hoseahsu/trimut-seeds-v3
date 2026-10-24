#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int a[2010], b[2010];
bool check(long long x) {
  int st = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = st; j < k; j++) {
      if (abs(p - b[j]) + abs(a[i] - b[j]) <= x) {
        flag = true;
        st = j + 1;
        break;
      }
    }
    if (!flag) return false;
  }
  return true;
}
int main() {
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
  }
  sort(a, a + n);
  sort(b, b + k);
  long long l = 0, r = 2e15;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld\n", l);
}
