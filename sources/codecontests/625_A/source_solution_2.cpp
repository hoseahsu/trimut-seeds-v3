#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int Scan() {
  int res = 0, ch, flag = 0;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return flag ? -res : res;
}
int main() {
  long long int n;
  cin >> n;
  long long int a, b, c;
  cin >> a >> b >> c;
  if (a <= b - c) {
    printf("%I64d\n", n / a);
    return 0;
  }
  long long int cnt = 0;
  if (n >= b) {
    cnt += (n - b) / (b - c);
    cnt++;
    n -= cnt * (b - c);
  }
  cnt += n / a;
  printf("%I64d\n", cnt);
  return 0;
}
