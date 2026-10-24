#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = 1100;
ll n, nx[N], acc[N];
ll d[N][N];
vector<array<ll, 3>> res;
void swapr(ll i, ll j) {
  for (ll ii = 1; ii <= (ll)(n); ++ii) swap(d[i][ii], d[j][ii]);
}
void swapc(ll i, ll j) {
  for (ll ii = 1; ii <= (ll)(n); ++ii) swap(d[ii][i], d[ii][j]);
}
void init() {}
void solve() {
  cin >> n;
  for (ll _ = 1; _ <= (ll)(n - 1); ++_) {
    ll x, y;
    cin >> x >> y;
    ++nx[x];
    d[x][y] = 1;
  }
  for (ll i = 1; i <= (ll)(n); ++i) acc[i] = acc[i - 1] + nx[i];
  for (ll i = n; i >= 1; --i)
    if (nx[i]) {
      ll row = i;
      if (acc[i] > i - 1) {
        res.push_back({1, i, acc[i] + 1});
        swapr(i, acc[i] + 1);
        row = acc[i] + 1;
      }
      vector<ll> v1, v2;
      ll const s = acc[i] - nx[i] + 1, e = row;
      for (ll i = 1; i <= (ll)(n); ++i) {
        if ((i < s || i >= e) && d[row][i]) v1.push_back(i);
        if (i >= s && i < e && !d[row][i]) v2.push_back(i);
      }
      for (ll i = 0, end = v1.size(); i < end; ++i) {
        res.push_back({2, v1[i], v2[i]});
        swapc(v1[i], v2[i]);
      }
    }
  cout << res.size() << '\n';
  for (auto const &ch : res)
    cout << ch[0] << ' ' << ch[1] << ' ' << ch[2] << '\n';
}
}  // namespace
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(20);
  init();
  solve();
  return 0;
}
