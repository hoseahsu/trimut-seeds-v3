#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100010] = {0}, b[100010] = {0}, a1[100010] = {0}, b1[100010] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    a1[i] = a[i] - a[i - 1];
    b1[i] = b[i] - b[i - 1];
  }
  sort(a1 + 1, a1 + 1 + n);
  sort(b1 + 1, b1 + 1 + n);
  if (a[1] == b[1] && a[n] == b[n]) {
    for (int i = 1; i <= n; i++) {
      if (a1[i] != b1[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
  } else {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
