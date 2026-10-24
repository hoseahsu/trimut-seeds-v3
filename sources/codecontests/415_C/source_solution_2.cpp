#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long int n, k;
  cin >> n >> k;
  if (n > (2 * k + 1)) {
    printf("-1\n");
    return 0;
  }
  if (n == 1) {
    if (k == 0) {
      printf("1\n");
      return 0;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  if (n % 2 == 0) {
    cout << k - ((n - 2) / 2) << " " << 2 * (k - ((n - 2) / 2)) << " ";
    long long int a = 2 * (k - ((n - 2) / 2));
    for (int i = 1; i <= (n - 2); i++) {
      cout << ++a << " ";
    }
  } else {
    cout << k - ((n - 3) / 2) << " " << 2 * (k - ((n - 3) / 2)) << " ";
    long long int a = 2 * (k - ((n - 3) / 2));
    for (int i = 1; i <= (n - 2); i++) {
      cout << ++a << " ";
    }
  }
  cout << "\n";
  return 0;
}
