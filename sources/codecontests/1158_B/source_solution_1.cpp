#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void ckmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void ckmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
using VI = vector<int>;
string solve(int n, int m) {
  int k = (n - m) / 2;
  string s = "";
  for (int i = 0; i < (n); ++i) s += (i % (k + 1) == k) ? '1' : '0';
  return s;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    cout << solve(n, m) << endl;
    break;
  }
  return 0;
}
