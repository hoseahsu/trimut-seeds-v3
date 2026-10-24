#include <bits/stdc++.h>
using namespace std;
int n;
int k[1005];
int HMF() {
  int sum = 0;
  for (int i = 1; i <= n; i = i + 1)
    if (k[i] < 0) sum = sum + 1;
  return sum;
}
int HMZ() {
  int sum = 0;
  for (int i = 1; i <= n; i = i + 1)
    if (k[i] > 0) sum = sum + 1;
  return sum;
}
int HM0() {
  int sum = 0;
  for (int i = 1; i <= n; i = i + 1)
    if (k[i] == 0) sum = sum + 1;
  return sum;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i = i + 1) cin >> k[i];
  for (int i = 1; i <= n; i = i + 1)
    if (k[i] > 0) cout << k[i] << " ";
  int fs = HMF();
  int zs = HMZ();
  int zero = HM0();
  if (fs == 1 && zs > 0) return 0;
  if (fs == 1 && zs == 0) {
    if (zero == 0)
      cout << k[1];
    else
      cout << 0;
    return 0;
  }
  if (fs % 2 == 0) {
    for (int i = 1; i <= n; i = i + 1)
      if (k[i] < 0) cout << k[i] << " ";
  }
  bool flag = 0;
  if (fs % 2 == 1) {
    int maxn = -1000000;
    int MAX = -1;
    for (int i = 1; i <= n; i = i + 1) {
      if (k[i] < 0 && k[i] > maxn) {
        maxn = k[i];
        MAX = i;
      }
    }
    for (int i = 1; i <= n; i = i + 1)
      if (k[i] < 0 && i != MAX) cout << k[i] << " ";
  }
  if (zs == 0 && fs == 0) cout << 0;
  return 0;
}
