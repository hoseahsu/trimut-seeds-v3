#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  map<ll, int> cnt;
  cnt[0] = 1;
  int n;
  cin >> n;
  ll sum = 0, res = 0;
  while (n--) {
    int a;
    cin >> a;
    sum += a;
    res += cnt[sum];
    cnt[sum]++;
  }
  cout << res << endl;
  return 0;
}