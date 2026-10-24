#include <bits/stdc++.h>
using namespace std;
const int LOGN = 18;
const int MOD = 998244353;
int g = 3;
int mul(int a, int b) { return int(a * 1ll * b % MOD); }
int norm(int a) {
  while (a >= MOD) a -= MOD;
  while (a < 0) a += MOD;
  return a;
}
int binPow(int a, int k) {
  int ans = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) ans = mul(ans, a);
    a = mul(a, a);
  }
  return ans;
}
int inv(int a) { return binPow(a, MOD - 2); }
vector<int> w[LOGN], rv;
bool precalced = false;
void precalc() {
  if (precalced) return;
  precalced = true;
  int wb = binPow(g, (MOD - 1) / (1 << LOGN));
  for (int st = int(0); st < int(LOGN); st++) {
    w[st].assign(1 << st, 1);
    int bw = binPow(wb, 1 << (LOGN - st - 1));
    int cw = 1;
    for (int k = int(0); k < int((1 << st)); k++) {
      w[st][k] = cw;
      cw = mul(cw, bw);
    }
  }
  rv.assign(1 << LOGN, 0);
  for (int i = int(1); i < int(int((rv).size())); i++)
    rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (LOGN - 1));
}
const int MX = (1 << LOGN) + 3;
inline void fft(int a[MX], int n, bool inverse) {
  precalc();
  int ln = __builtin_ctz(n);
  assert((1 << ln) < MX);
  assert((1 << ln) == n);
  for (int i = int(0); i < int(n); i++) {
    int ni = rv[i] >> (LOGN - ln);
    if (i < ni) swap(a[i], a[ni]);
  }
  for (int st = 0; (1 << st) < n; st++) {
    int len = (1 << st);
    for (int k = 0; k < n; k += (len << 1)) {
      for (int pos = int(k); pos < int(k + len); pos++) {
        int l = a[pos];
        int r = mul(a[pos + len], w[st][pos - k]);
        a[pos] = norm(l + r);
        a[pos + len] = norm(l - r);
      }
    }
  }
  if (inverse) {
    int in = inv(n);
    for (int i = int(0); i < int(n); i++) a[i] = mul(a[i], in);
    reverse(a + 1, a + n);
  }
}
int aa[MX], bb[MX], cc[MX];
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
  int ln = 1;
  while (ln < (int((a).size()) + int((b).size()))) ln <<= 1;
  for (int i = int(0); i < int(ln); i++)
    aa[i] = (i < int((a).size()) ? a[i] : 0);
  for (int i = int(0); i < int(ln); i++)
    bb[i] = (i < int((b).size()) ? b[i] : 0);
  fft(aa, ln, false);
  fft(bb, ln, false);
  for (int i = int(0); i < int(ln); i++) cc[i] = mul(aa[i], bb[i]);
  fft(cc, ln, true);
  vector<int> ans(cc, cc + ln);
  while (ans.back() == 0) ans.pop_back();
  return ans;
}
int n;
vector<int> ps;
inline bool read() {
  if (!(cin >> n)) return false;
  ps.resize(n);
  for (int i = int(0); i < int(n); i++) cin >> ps[i];
  return true;
}
struct cmp {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    return int((a).size()) < int((b).size());
  }
};
inline void solve() {
  map<int, int> cnt;
  for (int i = int(0); i < int(n); i++) cnt[ps[i]]++;
  multiset<vector<int>, cmp> polys;
  for (auto p : cnt) polys.emplace(p.second + 1, 1);
  while (int((polys).size()) > 1) {
    auto it2 = polys.begin();
    auto it1 = it2++;
    polys.insert(multiply(*it1, *it2));
    polys.erase(it1);
    polys.erase(it2);
  }
  auto poly = *polys.begin();
  cout << poly[n / 2] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  if (read()) {
    solve();
  }
  return 0;
}
