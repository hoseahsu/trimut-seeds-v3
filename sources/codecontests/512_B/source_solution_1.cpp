#include <bits/stdc++.h>
using namespace std;
map<int, int> nima;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n;
int l[1000], c[1000];
void solve() {
  for (int i = 0; i < n; ++i) {
    if (nima.find(l[i]) != nima.end()) {
      if (nima[l[i]] > c[i]) nima[l[i]] = c[i];
    } else
      nima[l[i]] = c[i];
    for (map<int, int>::iterator iter = nima.begin(); iter != nima.end();
         ++iter) {
      int old = iter->first;
      int y = iter->second;
      int new_old = gcd(old, l[i]);
      if (nima.find(new_old) != nima.end()) {
        if (nima[new_old] > y + c[i]) nima[new_old] = y + c[i];
      } else {
        nima[new_old] = y + c[i];
      }
    }
  }
  if (nima.find(1) != nima.end()) {
    cout << nima[1] << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &l[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  solve();
}
