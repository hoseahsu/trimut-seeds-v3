#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, count = 0, temp;
  cin >> n;
  int a[n], b[n];
  int p[5] = {0, 0, 0, 0, 0};
  int q[5] = {0, 0, 0, 0, 0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i] - 1]++;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    q[b[i] - 1]++;
  }
  if (n == 1) {
    if (a[0] == b[0])
      cout << "0" << endl;
    else
      cout << "-1" << endl;
  } else {
    for (i = 0; i < 5; i++) {
      if ((p[i] - q[i]) % 2 == 0) {
        temp = (p[i] - q[i]) / 2;
        if (temp < 0) {
          temp = (-1) * temp;
        }
        count = count + temp;
      } else {
        count = -2;
        break;
      }
    }
    cout << count / 2 << endl;
  }
}
