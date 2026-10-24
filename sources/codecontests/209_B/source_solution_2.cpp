#include <bits/stdc++.h>
using namespace std;
long long min(long long x, long long y) { return x < y ? x : y; }
int main() {
  long long c[3], f = 0;
  cin >> c[0] >> c[1] >> c[2];
  long long mini = (long long)pow(2, 50), flag = 1;
  for (int i = 0, _ = 3; i < _; i++)
    for (int j = i + 1, _ = 3; j < _; j++) {
      if (c[i] % 2 == c[j] % 2) {
        mini = min(mini, max(c[i], c[j]));
        flag = 0;
      }
    }
  if (flag)
    cout << -1;
  else
    cout << mini;
  return 0;
}
