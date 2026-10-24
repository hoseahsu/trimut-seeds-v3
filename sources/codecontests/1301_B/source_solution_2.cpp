#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll ninf = numeric_limits<ll>::min();
const ll inf = numeric_limits<ll>::max();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    ll max = -2;
    ll min = inf;
    ll in;
    ll dif_max = 0;
    vector<ll> v;
    for (int i = 0; i < N and cin >> in; ++i) v.push_back(in);
    ll i = 0;
    if ((v[i + 1] == -1) and v[i] > max) max = v[i];
    if ((v[i + 1] == -1) and v[i] < min and v[i] != -1) min = v[i];
    for (i = 1; i < N - 1; ++i) {
      if ((v[i - 1] == -1 or v[i + 1] == -1) and v[i] > max) max = v[i];
      if ((v[i - 1] == -1 or v[i + 1] == -1) and v[i] < min and v[i] != -1)
        min = v[i];
      if (v[i] != -1 and v[i - 1] != -1) {
        if (abs(v[i - 1] - v[i]) > dif_max) dif_max = abs(v[i - 1] - v[i]);
      }
    }
    if ((v[i - 1] == -1) and v[i] > max) max = v[i];
    if ((v[i - 1] == -1) and v[i] < min and v[i] != -1) min = v[i];
    if (v[i] != -1 and v[i - 1] != -1) {
      if (abs(v[i - 1] - v[i]) > dif_max) dif_max = abs(v[i - 1] - v[i]);
    }
    if (min == inf) {
      cout << "0 0\n";
    } else {
      ll k = (min + max) / 2;
      ll m = max - k;
      if (m > dif_max) dif_max = m;
      cout << dif_max << ' ' << k << endl;
    }
  }
}
