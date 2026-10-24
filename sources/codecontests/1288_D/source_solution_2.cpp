#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int n, m, a1, a2;
int a[N][10];
bool check(int x) {
  map<int, int> mp;
  for (int i = int(1); i <= int(n); i++) {
    int res = 0;
    for (int j = int(1); j <= int(m); j++) {
      if (a[i][j] >= x) {
        res |= (1 << (m - j));
      }
    }
    if (mp.find(res) == mp.end()) {
      mp[res] = i;
    }
  }
  for (auto it : mp) {
    for (auto i : mp) {
      if ((it.first | i.first) == (1 << m) - 1) {
        a1 = it.second, a2 = i.second;
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = int(1); i <= int(n); i++)
    for (int j = int(1); j <= int(m); j++) cin >> a[i][j];
  int l = 0, r = 1e9, mid;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  check(l - 1);
  cout << a1 << " " << a2;
}
