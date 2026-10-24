#include <bits/stdc++.h>
using namespace std;
long long int reversa(long long int d) {
  long long int s = 0, aux;
  while (d > 0LL) {
    s = s * 10LL + d % 10LL;
    d = d / 10LL;
  }
  return s;
}
int main() {
  long long int a, b;
  while (cin >> a >> b) {
    cout << a + reversa(b) << endl;
  }
  return 0;
}
