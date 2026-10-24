#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long f(long long a, long long b) {
  if (b == 0) return 0;
  return a / b + f(b, a % b);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  cout << f(a, b) << endl;
}
