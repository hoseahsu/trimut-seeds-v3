#include <bits/stdc++.h>
using namespace std;
const int MAX_N = (int)1e5 + 20;
double a[MAX_N];
double di[MAX_N];
int n;
double d;
long long ans = 0;
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) di[i] = a[i] - a[0];
  int Size = 0, real = 0;
  while (real < n) {
    while (di[Size] - di[real] <= d && Size < n) Size++;
    Size--;
    long long x = Size - real;
    if (x > 0) ans += (x) * (x - 1) / 2;
    real++;
  }
  cout << ans << endl;
}
