#include <bits/stdc++.h>
using namespace std;
long long H, N;
long long pot(long long a, int pot) {
  if (pot < 0) {
    return 1;
  }
  long long wyn = 1;
  while (pot--) {
    wyn *= a;
  }
  return wyn;
}
long long policz() {
  long long wyn = 0;
  const long long M = pot(2, H);
  long long h = 0;
  long long v = 1;
  long long left = M;
  long long right = 2 * M - 1;
  long long koniec = M + (N - 1);
  int ruch = 0;
  while (v != koniec) {
    if (koniec <= (left + right) / 2) {
      v = 2 * v;
      right = (left + right) / 2;
      if (ruch != 0) {
        wyn += pot(2, H - h);
      } else {
        wyn++;
      }
      ruch = 1;
    } else {
      left = ((left + right) / 2) + 1;
      v = (2 * v) + 1;
      if (ruch != 1) {
        wyn += pot(2, H - h);
      } else {
        wyn++;
      }
      ruch = 0;
    }
    ++h;
  }
  return wyn;
}
int main() {
  scanf("%lld%lld", &H, &N);
  printf("%lld\n", policz());
  return 0;
}
