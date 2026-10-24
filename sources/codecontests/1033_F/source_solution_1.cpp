#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
const int N = 12;
int cnt[1 << (N * 2)];
int cn[1 << N];
int w, n, m;
void go1(int num, int bt, int cur) {
  if (bt == w) {
    ++cnt[cur];
    return;
  }
  int sh = 2 * bt;
  go1(num, bt + 1, cur + (2 << sh));
  int nb = (num >> bt) & 1;
  go1(num, bt + 1, cur + (nb << sh));
}
int table[2][2][6] = {{{0, 0, 0, 1, 1, 1}, {0, 1, 1, 1, 0, 0}},
                      {{0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1}}};
string ss = "AOXaox";
int id[N];
ll ans;
void go2(int num, int bt, int cur) {
  if (bt == w) {
    if (cn[num]) {
      ans += ll(cnt[cur]) * cn[num];
    }
    return;
  }
  for (int b = 0; b < 2; ++b) {
    int cr = 0;
    for (int j = 0; j < 2; ++j) {
      if (table[b][j][id[bt]] == 0) {
        cr += (1 << j);
      }
    }
    if (cr) {
      go2(num + (b << bt), bt + 1, cur + ((cr - 1) << (2 * bt)));
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> w >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++cn[a];
    go1(a, 0, 0);
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int j = 0; j < w; ++j) {
      id[j] = find(ss.begin(), ss.end(), s[j]) - ss.begin();
    }
    ans = 0;
    go2(0, 0, 0);
    cout << ans << "\n";
  }
}
