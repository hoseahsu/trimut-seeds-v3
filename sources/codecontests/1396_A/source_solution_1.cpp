#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << "1 1" << endl << a[1] * (n - 1) << endl;
  (n == 1) ? cout << "1 1" << endl << "0" : cout << "2 " << n << endl;
  for (int i = 2; i <= n; i++) cout << a[i] * (n - 1) << " ";
  cout << endl << "1 " << n << endl;
  for (int i = 1; i <= n; i++) cout << -a[i] * n << " ";
}
