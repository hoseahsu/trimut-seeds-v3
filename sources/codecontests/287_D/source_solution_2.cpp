#include <bits/stdc++.h>
using namespace std;
int ans[2000010];
int n, start = 0;
void debug() {
  cout << "... ";
  for (int i = start; i < start + n; i++) {
    i == start ? cout << ans[i] : cout << " " << ans[i];
  }
  cout << endl;
}
int main() {
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) ans[i] = i;
  for (i = 2; i <= n; i++) {
    int a, b = ans[start];
    for (j = 1; j * i < n; j++) {
      a = ans[start + i * j];
      ans[start + i * j] = b;
      b = a;
    }
    start++;
    ans[start + n - 1] = b;
  }
  for (int i = start; i < start + n; i++) {
    i == start ? cout << ans[i] + 1 : cout << " " << ans[i] + 1;
  }
  cout << endl;
  return 0;
}
