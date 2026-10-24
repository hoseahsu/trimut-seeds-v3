#include <bits/stdc++.h>
using namespace std;
int main() {
  int number[50][2] = {0}, n, a, b, i, limit, two[2], j = 0;
  cin >> n;
  limit = n * (n - 1) / 2 - 1;
  for (i = 0; i < limit; i++) {
    cin >> a >> b;
    number[a][0]++;
    number[b][0]++;
    number[a][1]++;
  }
  for (i = 1; i <= n; i++) {
    if (number[i][0] != n - 1) {
      two[j] = i;
      j++;
    }
  }
  a = two[0];
  b = two[1];
  if (number[a][1] >= number[b][1])
    cout << a << " " << b;
  else
    cout << b << " " << a;
}
