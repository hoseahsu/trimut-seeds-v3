#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long mod = 1e9 + 7;
long long fmod(long long b, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1ll) res = (res * b) % mod;
    b = (b * b) % mod;
    exp /= 2ll;
  }
  return res;
}
string second;
int buc[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, n, i, j, m;
  int cnt1 = 0, cnt2 = 0;
  cin >> second;
  n = second.length();
  second = "#" + second;
  int lst = 1;
  for (i = 1; i <= n; i++) {
    if (second[i] == 'a') {
      cnt1++;
      lst = i;
    } else
      cnt2++;
  }
  if (cnt1 == 0 || cnt2 == 0) {
    for (i = 1; i <= n; i++) cout << "0 ";
    cout << "\n";
    return 0;
  }
  if (cnt1 == 1) {
    for (i = 1; i <= n; i++) {
      if (second[i] != 'a')
        cout << "0 ";
      else
        cout << "1 ";
    }
    cout << "\n";
    return 0;
  }
  for (i = 1; i <= n; i++) {
    if (second[i] == 'b') continue;
    if (second[i] == 'a' && i > 1) {
      if (second[i - 1] == 'a') continue;
      int j = i - 1;
      while (j > 1 && second[j] == 'b') j--;
      buc[j] ^= 1;
      buc[i - 1] ^= 1;
    }
  }
  buc[lst] ^= 1;
  for (i = 1; i <= n; i++) cout << buc[i] << " ";
  cout << "\n";
  return 0;
}
