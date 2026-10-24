#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n;
  if (n == 0) cout << "a" << endl;
  vector<long long> v;
  long long a = 97;
  while (n) {
    long long m = 1;
    while (m * (m - 1) / 2 <= n) m++;
    m--;
    n -= (m * (m - 1) / 2);
    for (long long i = 0; i < m; i++) v.push_back(a);
    a++;
  }
  for (long long i = 0; i < v.size(); i++) cout << (char)v[i];
  cout << endl;
}
