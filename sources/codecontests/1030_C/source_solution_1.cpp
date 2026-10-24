#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    num[i] = a - '0';
  }
  int flag = 0;
  for (int i = 0; i <= 9 * n; i++) {
    int cnt = 0, j, sum = 0;
    for (j = 0; j < n; j++) {
      sum += num[j];
      if (sum == i) {
        cnt++;
        sum = 0;
      } else if (sum > i)
        break;
    }
    if (sum == 0 && cnt >= 2) flag = 1;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
