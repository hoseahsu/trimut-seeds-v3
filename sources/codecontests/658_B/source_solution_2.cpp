#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e7 + 7;
const int maxn = 6e5 + 5;
map<int, int> m;
int main() {
  ios::sync_with_stdio(false);
  int n, q, k;
  std::cin >> n >> k >> q;
  int a[n + 1];
  for (long long i = 1; i <= n; ++i) {
    std::cin >> a[i];
    m[a[i]] = i;
  }
  set<int> s;
  while (q--) {
    int type, id;
    std::cin >> type >> id;
    if (type == 1) {
      if (s.size() < k) {
        s.insert(a[id]);
        continue;
      }
      int fl = 0;
      for (auto v : s) {
        if (v < a[id]) {
          fl = 1;
        }
        break;
      }
      if (fl) {
        s.erase(s.begin());
        s.insert(a[id]);
      }
    } else {
      int fl = 0;
      for (auto v : s) {
        if (m[v] == id) {
          fl = 1;
          break;
        }
      }
      if (fl)
        std::cout << "YES"
                  << "\n";
      else
        std::cout << "NO"
                  << "\n";
    }
  }
  return 0;
}
