#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
bool E[1111111];
unsigned long long P[411111];
unsigned long long lp[1111111];
unsigned long long plen;
void eratosphen() {
  E[0] = E[1] = 1;
  for (unsigned long long i = 0; i < 1111111; i++) {
    if (E[i]) continue;
    for (unsigned long long j = i * i; j < 1111111; j += i) {
      E[j] = 1;
      lp[j] = i;
    }
    P[plen++] = i;
    lp[i] = i;
  }
}
unsigned long long A[555555];
int main(void) {
  eratosphen();
  unsigned long long n, x, y;
  merr << "Done" << '\n';
  cin >> n >> x >> y;
  for (unsigned long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  set<unsigned long long> tocheck{2, 3, 5};
  map<unsigned long long, unsigned long long> mp;
  for (unsigned long long i = 0; i < n; i++) {
    unsigned long long nn = A[i];
    set<unsigned long long> was;
    while (lp[nn] != 0) {
      unsigned long long p = lp[nn];
      tocheck.insert(p);
      if (was.find(p) == was.end()) mp[p]++;
      was.insert(p);
      nn /= p;
    }
  }
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  vector<pair<unsigned long long, unsigned long long>> V;
  for (auto p : mp) {
    V.push_back({p.second, p.first});
  }
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  sort(V.begin(), V.end(),
       greater<pair<unsigned long long, unsigned long long>>());
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  set<unsigned long long> S{2, 3, 5, 7, 11, 13};
  for (unsigned long long i = 0; i < 10 && i < V.size(); i++) {
    S.insert(V[i].second);
  }
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  for (auto p : tocheck) {
    S.insert(p);
    if (S.size() > 40) break;
  }
  merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  unsigned long long ans = min(x * n, y * n);
  tocheck = S;
  merr << tocheck.size() << '\n';
  unsigned long long idx = 0;
  for (auto p : tocheck) {
    unsigned long long res = 0;
    for (unsigned long long i = 0; i < n && res < ans; i++) {
      unsigned long long xx = A[i];
      res += min(x, ((p - xx % p) % p) * y);
    }
    if (res < ans) {
      ans = res;
    }
    idx++;
    if (idx > 40) break;
  }
  cout << ans << '\n';
}
