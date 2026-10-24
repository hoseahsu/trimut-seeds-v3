#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long fun(long long c) {
  long long ans = 0;
  long long temp = 1ll;
  for (int i = 0; i < (long long)a.size(); i++) {
    ans += abs(a[i] - temp);
    temp *= c;
    if (temp >= 1e15) return -1;
  }
  return ans;
}
void run_case() {
  long long n;
  cin >> n;
  a = vector<long long>(n);
  for (long long &i : a) cin >> i;
  sort(a.begin(), a.end());
  long long ans = LLONG_MAX;
  int c = 1;
  while (1) {
    long long curr = fun(c);
    if (curr == -1) break;
    ans = min(ans, curr);
    c++;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int i = 1; i <= tc; i++) run_case();
  return 0;
}
