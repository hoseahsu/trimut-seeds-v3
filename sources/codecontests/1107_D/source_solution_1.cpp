#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
const long long N = 6000;
vector<string> a(N, "");
bool can(long long k, long long n) {
  for (long long i = 0; i < n; i += k) {
    for (long long j = 0; j < n; j += k) {
      for (long long x = 0; x < k; x++) {
        for (long long y = 0; y < k; y++) {
          if (a[i + x][j + y] != a[i][j]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  map<char, string> m;
  m['0'] = "0000";
  m['1'] = "0001";
  m['2'] = "0010";
  m['3'] = "0011";
  m['4'] = "0100";
  m['5'] = "0101";
  m['6'] = "0110";
  m['7'] = "0111";
  m['8'] = "1000";
  m['9'] = "1001";
  m['A'] = "1010";
  m['B'] = "1011";
  m['C'] = "1100";
  m['D'] = "1101";
  m['E'] = "1110";
  m['F'] = "1111";
  for (long long i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (long long j = 0; j < n / 4; j++) {
      string val = m[x[j]];
      for (char ch : val) a[i].push_back(ch);
    }
  }
  for (long long i = n; i >= 1; i--) {
    if (n % i == 0 && can(i, n)) {
      cout << i << "\n";
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
