#include <bits/stdc++.h>
using namespace std;
int A[10], n;
char str[100100];
int pm(int a, int b) {
  long long ret = 1, x = a;
  while (b) {
    if (b & 1) ret = (ret * x) % 1000000007;
    x = (x * x) % 1000000007;
    b >>= 1;
  }
  return ret;
}
int trans(char c) {
  if (c == 'A') return 0;
  if (c == 'C') return 1;
  if (c == 'G') return 2;
  if (c == 'T') return 3;
  return 4;
}
int main() {
  while (scanf("%d", &n) == 1) {
    scanf("%s", str);
    memset(A, 0, sizeof(A));
    for (int i = 0; str[i]; i++) A[trans(str[i])]++;
    sort(A, A + 4);
    int co = 0;
    for (int i = 0; i < 4; i++)
      if (A[i] == A[3]) co++;
    int ans = pm(co, n);
    cout << ans << endl;
  }
}
