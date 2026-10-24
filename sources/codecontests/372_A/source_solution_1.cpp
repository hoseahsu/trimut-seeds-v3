#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
set<int> st;
int a[500005], mark[500005];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int pos = n - 1;
  for (i = n / 2 - 1; i >= 0; i--) {
    if (a[i] * 2 <= a[pos]) {
      mark[i] = 1;
      pos--;
    }
    if (pos <= (n / 2 - 1)) {
      break;
    }
  }
  int cnt = 0;
  for (i = 0; i < n; i++) {
    if (mark[i] == 1) {
      cnt++;
    }
  }
  cnt = n - cnt;
  printf("%d\n", cnt);
  return 0;
}
