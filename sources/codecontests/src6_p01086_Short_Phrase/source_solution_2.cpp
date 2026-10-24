#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    auto c = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      string w; cin >> w;
      c[i] = w.length();
    }
    auto solve = [&]() {
      for (int i = 0; i < n; ++i) {
        auto sum = vector<int>{5, 7, 5, 7, 7};
        int pos = 0;
        for (int j = i; j < n; ++j) {
          if (sum[pos] == 0) ++pos;
          if (pos == 5) return i + 1;
          if (sum[pos] > 0) sum[pos] -= c[j];
        }
        if (sum[pos] == 0 && pos + 1 == 5) return i + 1;
      }
      return 0;
    };
    cout << solve() << endl;
  }
  return 0;
}

