#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int T;
string S;
long long MUL(long long a, long long b) {
  long long Res = 0;
  while (b) {
    if (b & 1) Res = (Res + a) % MOD;
    a = (a + a) % MOD;
    b = b >> 1;
  }
  return Res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    cin >> S;
    long long Ans = S.size();
    for (register int i = 1; i <= x; ++i) {
      long long A = (Ans - (long long)i + MOD) % MOD;
      long long B = (long long)(S[i - 1] - '0');
      Ans = (MUL(A, B) + (long long)i) % MOD;
      if (S.size() < x) {
        string str = S.substr(i);
        int Count = S[i - 1] - '0';
        for (register int j = 1; j <= Count - 1; ++j) {
          S += str;
          if (S.size() > x) break;
        }
      }
    }
    cout << Ans % MOD << endl;
  }
  return 0;
}
