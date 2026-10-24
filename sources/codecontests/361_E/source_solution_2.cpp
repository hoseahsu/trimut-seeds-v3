#include <bits/stdc++.h>
using namespace std;
const string NAME = "360C";
const int INF = 1e9 + 7;
const int N = 2e3 + 8, B = 1e9 + 7;
int n, K;
long long f[N][N], sum[N];
string s;
void Enter() {
  cin >> n >> K;
  cin >> s;
  s = ' ' + s;
}
inline void Add(long long &a, const long long b) { a = (a + b) % B; }
void Process() {
  f[0][0] = sum[0] = 1;
  for (int i = (1), _b = (n); i <= _b; ++i)
    for (int j = (0), _b = (K); j <= _b; ++j) {
      Add(f[i][j], sum[j] * (s[i] - 'a'));
      for (int pref = 0; i - pref - 1 >= 0 && j - (n - i + 1) * (pref + 1) >= 0;
           ++pref) {
        Add(f[i][j],
            f[i - pref - 1][j - (pref + 1) * (n - i + 1)] * ('z' - s[i]));
      }
      Add(sum[j], f[i][j]);
    }
}
void Result() {
  long long res = 0;
  if (K == 0) res = 1;
  for (int i = (1), _b = (n); i <= _b; ++i) Add(res, f[i][K]);
  cout << (res + B) % B;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Enter();
  Process();
  Result();
}
