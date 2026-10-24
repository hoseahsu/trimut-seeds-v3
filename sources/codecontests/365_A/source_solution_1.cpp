#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int count = 0;
  while (n--) {
    int A[k + 5];
    for (int i = 0; i <= k; i++) {
      A[i] = 0;
    }
    int a;
    cin >> a;
    while (a > 0) {
      int d = a % 10;
      A[d] = 1;
      a /= 10;
    }
    int flag = 0;
    for (int i = 0; i <= k; i++) {
      if (A[i] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      count++;
    }
  }
  cout << count;
}
