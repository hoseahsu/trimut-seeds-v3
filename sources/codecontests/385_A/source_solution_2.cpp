#include <bits/stdc++.h>
using namespace std;
const int nmax = 100010;
vector<long long> ans;
int main() {
  int n, c;
  cin >> n >> c;
  int a[111];
  int max = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int tmp = a[i];
    if (tmp - a[i + 1] - c > max) {
      max = tmp - a[i + 1] - c;
    }
  }
  cout << max;
  return 0;
}
