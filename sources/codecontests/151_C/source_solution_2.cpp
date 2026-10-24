#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
void check_time() {}
const int res = 1e6 + 50;
const long long int mod = 1e9 + 7;
long long int a[res];
long long int n, m, sum, total, ans, digit;
int main() {
  scanf("%I64d", &n);
  if (n == 1) {
    printf(
        "1\n"
        "0");
    return 0;
  }
  for (long long int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      a[digit++] = i;
      n /= i;
    }
  }
  if (n > 1) {
    a[digit++] = n;
  }
  if (digit == 2) {
    printf("2");
  } else {
    printf("1\n%lld\n", a[0] * a[1]);
  }
  return 0;
}
