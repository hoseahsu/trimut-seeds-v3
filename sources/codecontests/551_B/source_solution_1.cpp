#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans % mod * a % mod;
    a = a % mod * a % mod;
    b >>= 1;
  }
  return ans;
}
long long gcd(long long x, long long y) {
  if (x == 1 || y == 1)
    return 1;
  else {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x % y == 0) return y;
    if (y % x == 0) return x;
    if (x > y)
      return gcd(x % y, y);
    else
      return gcd(x, y % x);
  }
}
long long toInt(string str) {
  if (str == "?" || str == "+" || str == "-" || str == "=") return -1;
  long long ans = 0;
  for (int i = (str[0] == '-'); i < str.size(); i++) {
    ans *= 10;
    ans += str[i] - '0';
  }
  if (str[0] == '-') ans = -ans;
  return ans;
}
string toString(long long a) {
  if (a == 0) return "0";
  string temp = "";
  if (a < 0) temp.push_back('-');
  long long tp = a;
  while (tp) {
    temp.push_back('0' + tp % 10);
    tp /= 10;
  }
  string temp2 = temp;
  for (int ii = 0; ii < temp.size(); ii++) {
    temp[ii] = temp2[temp.size() - 1 - ii];
  }
  return temp;
}
long long inf = (long long)1 << 30;
const int maxn = 50 + 5;
int cnta[maxn], cntb[maxn], cntc[maxn];
int tpcnt[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream in("Text.txt");
  long long n, m, t, x, y, k = 1, d;
  string str, a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < a.size(); i++) cnta[a[i] - 'a']++;
  for (int i = 0; i < b.size(); i++) cntb[b[i] - 'a']++;
  for (int i = 0; i < c.size(); i++) cntc[c[i] - 'a']++;
  int mx = 100000;
  for (int i = 0; i < 26; i++)
    if (cntb[i]) mx = min(mx, cnta[i] / cntb[i]);
  int ansb = 0, ansc = 0;
  int mx2 = 0;
  int mx1;
  for (int i = 0; i <= mx; i++) {
    for (int i = 0; i < 26; i++) tpcnt[i] = cnta[i];
    for (int j = 0; j < 26; j++) tpcnt[j] -= i * cntb[j];
    mx1 = 100000;
    for (int j = 0; j < 26; j++)
      if (cntc[j]) mx1 = min(tpcnt[j] / cntc[j], mx1);
    if (mx1 + i > mx2) ansb = i, ansc = mx1, mx2 = i + mx1;
  }
  for (int i = 0; i < ansb; i++) {
    cout << b;
    for (int i = 0; i < 26; i++) cnta[i] -= cntb[i];
  }
  for (int i = 0; i < ansc; i++) {
    cout << c;
    for (int i = 0; i < 26; i++) cnta[i] -= cntc[i];
  }
  for (int i = 0; i < 26; i++)
    while (cnta[i]-- > 0) cout << char('a' + i);
  return 0;
}
