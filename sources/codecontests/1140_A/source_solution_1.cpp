#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int count = 0;
  int max = a[1];
  for (int i = 1; i <= n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
    if (i == max) {
      count++;
      continue;
    }
  }
  cout << count << endl;
  return 0;
}
