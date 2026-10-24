#include <bits/stdc++.h>
using namespace std;
bool get(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return 0;
  if (!get(b, a % b)) return 1;
  if (b % 2)
    return a / b % 2 == 0;
  else
    return a / b % (b + 1) % 2 == 0;
}
int main() {
  int t;
  long long a, b;
  for (scanf("%d", &t); t--; scanf("%I64d%I64d", &a, &b),
                             printf("%s\n", get(a, b) ? "First" : "Second"))
    ;
  return 0;
}
