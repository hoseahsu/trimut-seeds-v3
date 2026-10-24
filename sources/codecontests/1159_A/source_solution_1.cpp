#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1);
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
const long long mod = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n;
  cin >> n;
  int sum1 = 0, sum2 = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '-')
      sum1++;
    else
      sum2++;
    if (sum1 > sum2) {
      sum1 = 0;
      sum2 = 0;
      sum = 0;
    } else
      sum = sum2 - sum1;
  }
  cout << sum;
}
