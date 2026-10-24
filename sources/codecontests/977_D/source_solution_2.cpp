#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
ll count3(ll a) {
  ll res = 0;
  while (a % 3 == 0) {
    res++;
    a /= 3;
  }
  return res;
}
int main() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].second;
    a[i].first = -count3(a[i].second);
  }
  sort(a.begin(), a.end());
  for (ll i = 0; i < n; i++) {
    cout << a[i].second << ' ';
  }
  cout << endl;
}
