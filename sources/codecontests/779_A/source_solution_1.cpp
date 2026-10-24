#include <bits/stdc++.h>
using namespace std;
long long int i, j, n;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int a1[100] = {0}, b1[100] = {0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a1[a[i]]++;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    b1[b[i]]++;
  }
  int l = 0, m = 0;
  for (i = 1; i <= 5; i++) {
    if (a1[i] > b1[i]) {
      if ((a1[i] - b1[i]) % 2 != 0) {
        cout << "-1";
        return 0;
      }
      l += (a1[i] - b1[i]) / 2;
    } else if (a1[i] < b1[i]) {
      if ((b1[i] - a1[i]) % 2 != 0) {
        cout << "-1";
        return 0;
      }
      m += (b1[i] - a1[i]) / 2;
    }
  }
  cout << m;
  return 0;
}
