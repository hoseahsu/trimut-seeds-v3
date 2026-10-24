#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long sum = 0, ma = 0, x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
    ma = max(ma, x);
  }
  long long b = sum % (n - 1);
  sum -= b;
  sum /= (n - 1);
  if (b) sum++;
  cout << max(ma, sum);
  return 0;
}
