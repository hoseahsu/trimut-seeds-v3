#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int k = 0, sign = 0;
    bool ans1 = true;
    int i = 0;
    for (i = 0; i < n; i++) {
      if (a[i] >= k) {
        k++;
      } else {
        break;
      }
    }
    k = 0;
    for (int j = n - 1; j >= i; j--) {
      if (a[j] >= k) {
        if (j == i && k == a[j - 1]) {
          ans1 = false;
          break;
        }
        k++;
      } else {
        ans1 = false;
        break;
      }
    }
    k = 0;
    bool ans2 = true;
    for (int j = n - 1; j >= 0; j--) {
      if (a[j] >= k) {
        k++;
      } else {
        ans2 = false;
        break;
      }
    }
    if (ans1 || ans2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
