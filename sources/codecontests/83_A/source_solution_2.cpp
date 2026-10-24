#include <bits/stdc++.h>
using namespace std;
const int mn = 100005;
int n, a[mn];
int main() {
  n = ({
    int t;
    scanf("%d", &t);
    t;
  });
  for (int i = 0; i < n; i++)
    a[i] = ({
      int t;
      scanf("%d", &t);
      t;
    });
  long long ans = 0;
  int i = 0;
  while (i < n) {
    int j;
    for (j = i + 1; j < n && a[j] == a[i]; j++)
      ;
    long long v = j - i;
    ans += v * (v + 1) / 2;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
