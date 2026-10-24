#include <bits/stdc++.h>
using namespace std;
int n, i;
int main() {
  cin >> n;
  cout << n / 2 << '\n';
  for (i = 1; i * 2 <= n - 2; i++) cout << 2 << " ";
  cout << 2 + n % 2;
}
