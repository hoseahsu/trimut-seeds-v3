#include <bits/stdc++.h>
using namespace std;
string a;
vector<char> ad;
int lo, cnt, ll;
int main() {
  cin >> a;
  cnt = 0;
  ll = a.length();
  for (int i = 0; i < ll; i++) {
    if (a[i] == 'a') lo = i, cnt++;
  }
  int res = lo + 1;
  if (cnt == ll) {
    cout << a << endl;
    return 0;
  }
  if (lo - cnt + res - ll > 0) {
    cout << ":(\n";
    return 0;
  }
  cnt = ll - cnt;
  if (cnt & 1) {
    cout << ":(\n";
    return 0;
  }
  res = ll - cnt / 2;
  for (int i = 0; i < res; i++) {
    if (a[i] != 'a') ad.push_back(a[i]);
  }
  for (int i = res; i < ll; i++) {
    if (ad[i - res] != a[i]) {
      cout << ":(\n";
      return 0;
    }
  }
  for (int i = 0; i < res; i++) cout << a[i];
  cout << endl;
  return 0;
}
