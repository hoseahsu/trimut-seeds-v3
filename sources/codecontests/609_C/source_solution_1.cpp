#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], sum = 0, count = 0;
  for (__typeof(n) i = (0); i != (n); i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  int k = sum % n;
  sum /= n;
  k = n - k;
  for (__typeof(n) i = (0); i != (n); i++) {
    count += abs(sum + (i < k ? 0 : 1) - a[i]);
  }
  count /= 2;
  cout << count << endl;
  return 0;
}
