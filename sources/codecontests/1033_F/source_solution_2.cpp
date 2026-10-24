#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _dbg(const char* _s, T _h) {
  cerr << _s << " = " << _h << "\n";
}
template <typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
  int _b = 0;
  while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',') cerr << *_s++;
  cerr << " = " << _h << ",";
  _dbg(_s + 1, _t...);
}
using ll = long long;
const ll INF = static_cast<ll>(1e9) + 7ll;
const ll LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;
int w, n, m;
ll ans = 0;
string second;
int P[2][MAXN];
int c[MAXN], three[MAXN], cnt[MAXN];
bool read() {
  if (!(cin >> w >> n >> m)) return false;
  for (ll i = 0; i < (ll)(n); ++i) {
    int x;
    cin >> x;
    ++c[x];
  }
  return true;
}
void go(int i, int mask, int mask3) {
  if (i == w) {
    ans += c[mask] * cnt[mask3];
    return;
  }
  if (P[1][second[i]] != -1) {
    go(i + 1, mask + (1 << i), mask3 + three[i] * P[1][second[i]]);
  }
  if (P[0][second[i]] != -1) {
    go(i + 1, mask, mask3 + three[i] * P[0][second[i]]);
  }
}
void solve() {
  P[0]['a'] = -1;
  P[0]['o'] = P[0]['x'] = 1;
  P[0]['A'] = 2;
  P[1]['O'] = -1;
  P[1]['X'] = P[1]['a'] = 1;
  P[1]['o'] = 2;
  three[0] = 1;
  for (int i = 1; i <= w; ++i) three[i] = three[i - 1] * 3;
  for (int mask = 0; mask < (1 << w); ++mask) {
    if (c[mask] == 0) continue;
    for (int smask = 0; smask < (1 << w); ++smask) {
      int res = 0;
      for (int i = 0; i < w; ++i) {
        if ((smask >> i) & 1) {
          res += 2 * three[i];
        } else {
          res += ((mask >> i) & 1) * three[i];
        }
      }
      cnt[res] += c[mask];
    }
  }
  for (ll i = 0; i < (ll)(m); ++i) {
    cin >> second;
    reverse(second.begin(), second.end());
    ;
    go(0, 0, 0);
    cout << ans << '\n';
    ans = 0;
  }
}
int main() {
  cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  while (read()) solve();
  return 0;
}
