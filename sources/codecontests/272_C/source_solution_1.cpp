#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long int m;
  cin >> m;
  long long int l = LLONG_MIN;
  for (int i = 0; i < m; i++) {
    long long int w, h;
    cin >> w >> h;
    l = max(l, a[w]);
    cout << l << endl;
    l = l + h;
  }
}
