#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int ar[200005];
void print(int t) {
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j < ar[i]; j++) cout << v[i][j] << " ";
    cout << endl;
  }
}
int main() {
  int n, t, k, mn, mx, f = 1;
  scanf("%d%d%d", &n, &t, &k);
  mx = n - t;
  ar[0] = 1;
  for (int i = 1; i <= t; i++) scanf("%d", &ar[i]);
  mn = ar[t];
  for (int i = 0; i < t; i++) {
    v[i].push_back(ar[i + 1]);
    for (int j = 1; j < ar[i]; j++) v[i].push_back(0);
  }
  for (int j = 1; j <= ar[t]; j++) v[t].push_back(0);
  if (k >= mn && k <= mx) {
    int z = n - ar[t] - t;
    k = k - ar[t];
    z = z - k;
    for (int i = t - 1; i >= 1 && z != 0; i--) {
      int vl = ar[i + 1];
      for (int j = 0; j < ar[i] && z != 0; j++) {
        if (vl != 0) {
          if (v[i][j] == 0) z--;
          v[i][j] = 1;
          vl--;
        }
      }
      v[i][0] += vl;
    }
    if (z != 0) f = 0;
  } else
    f = 0;
  if (f == 0)
    cout << -1 << endl;
  else {
    cout << n << endl;
    int a = 1;
    for (int i = 0; i < t; i++) {
      mn = a + ar[i];
      for (int j = 0; j < ar[i]; j++) {
        for (int k = 0; k < v[i][j]; k++, mn++) cout << a << " " << mn << endl;
        a++;
      }
    }
  }
}
