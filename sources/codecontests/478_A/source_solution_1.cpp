#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, a, b, c, n, t, m, p, q, d, e, f, l, nl, np;
  deque<long long int> v, s, vv, ss;
  map<long long int, long long int> ma, sa;
  string st, et, ft, pt, ct;
  deque<char> de;
  ios_base::sync_with_stdio(false);
  cin >> a >> b >> c >> d >> e;
  a = a + b + c + d + e;
  if (a % 5 == 0 && a != 0)
    cout << a / 5 << endl;
  else
    cout << -1 << endl;
}
