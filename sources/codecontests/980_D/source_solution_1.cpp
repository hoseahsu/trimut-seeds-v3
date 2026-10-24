#include <bits/stdc++.h>
using namespace std;
const int MAXn = 5000;
int n, a[5004], inp, saz[MAXn + 4][MAXn + 4], dd, kvadrati[10004];
unordered_map<int, int> sazimanje;
unordered_map<int, int> faktori;
int div(int x) {
  for (int i = 2; i <= 10000; i++)
    if (x % kvadrati[i] == 0) return kvadrati[i];
  return -1;
}
int convert(int x) {
  faktori.clear();
  int djel, neg = 0;
  if (x == 0) return 0;
  if (x < 0) {
    x = -x;
    neg = 1;
  }
  while (1) {
    dd = div(x);
    if (dd == -1) break;
    x = x / dd;
  }
  if (neg) return -x;
  return x;
}
int main() {
  for (int i = 0; i <= MAXn; i++)
    for (int j = 0; j < MAXn; j++) saz[i][j] = 0;
  for (int i = 0; i <= 10000; i++) kvadrati[i] = i * i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    a[i] = convert(inp);
  }
  for (int i = 0; i < n; i++) sazimanje[a[i]] = i;
  int groupes[5004], g, sn;
  memset(groupes, 0, sizeof(groupes));
  for (int i = 0; i < n; i++) {
    g = 0;
    sn = 1;
    for (int j = i; j < n; j++) {
      if (a[j] != 0)
        sn = 0;
      else {
        if (sn == 1)
          groupes[1]++;
        else
          groupes[g]++;
        continue;
      }
      if (saz[i][sazimanje[a[j]]] == 0) {
        saz[i][sazimanje[a[j]]] = 1;
        g++;
      }
      groupes[g]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << groupes[i] << ' ';
  }
  return 0;
}
