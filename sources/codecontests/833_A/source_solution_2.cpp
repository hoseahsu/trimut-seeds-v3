#include <bits/stdc++.h>
using namespace std;
int vec[1000005];
map<long long, int> M;
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= 1000000; i++) {
    if (vec[i]) continue;
    for (int j = i; j <= 1000000; j += i) vec[j] = i;
  }
  for (int i = 1; i <= 1000000; i++) {
    M[1LL * i * i * i] = i;
  }
  for (int i = 0; i < n; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long c = a * b;
    bool bad = 0;
    if (M.find(c) == M.end()) {
      bad = 1;
    } else {
      int x = M[c];
      while (x != 1) {
        int y = vec[x];
        {
          int A = 0, B = 0;
          while (a % y == 0) {
            a /= y;
            A++;
          }
          while (b % y == 0) {
            b /= y;
            B++;
          }
          while (x % y == 0) x /= y;
          if (A + B > 0) {
            if ((A + B) % 3 == 0 && min(A, B) * 2 >= max(A, B))
              ;
            else
              bad = 1;
          }
        }
      }
    }
    puts(bad ? "No" : "Yes");
  }
}
