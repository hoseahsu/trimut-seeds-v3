#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int st2[210];
char s[110];
int main() {
  st2[0] = 1;
  for (int i = 1; i < 210; i++) st2[i] = (2 * st2[i - 1]) % MOD;
  int res = 0;
  gets(s);
  int n = strlen(s);
  reverse(s, s + n);
  for (int i = 0; i < n; i++)
    if (s[i] == '1') res = (res + st2[2 * i] * 1LL * st2[n - i - 1]) % MOD;
  printf("%d\n", res);
  ;
  return 0;
}
