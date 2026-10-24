#include <bits/stdc++.h>
using namespace std;
int A[100000];
int main() {
  int n;
  cin >> n;
  int sh = 0;
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    A[i] = A[i] + a;
    int k = n - i - 1;
    int l = 1;
    while (l <= k) {
      if (l * 2 > k) {
        break;
      } else {
        l = l * 2;
      }
    }
    A[i + l] = A[i + l] + A[i];
    sh = sh + A[i];
    cout << sh << "\n";
  }
  return 0;
}
