#include <bits/stdc++.h>
using namespace std;
void input(vector<long long> &v) {
  for (auto &i : v) cin >> i;
}
void output(vector<long long> &v) {
  for (auto i : v) cout << i << ' ';
  cout << endl;
}
long long t;
void solve() {
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    cout << 1 << ' ' << x - 1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  solve();
}
