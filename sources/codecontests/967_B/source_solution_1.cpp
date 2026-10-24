#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const double ex = 1e-10;
using namespace std;
int a[112345];
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  int t = a[0];
  sort(a + 1, a + N);
  int x = 0;
  for (int i = 0; i < N; i++) {
    x += a[i];
    if (x * B > t * A) {
      printf("%d\n", N - i);
      return 0;
    }
  }
  puts("0");
  return 0;
}
