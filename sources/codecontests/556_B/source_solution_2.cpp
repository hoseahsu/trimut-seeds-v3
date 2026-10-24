#include <bits/stdc++.h>
using namespace std;
long n, a[10000];
void doc() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}
bool kt() {
  for (int i = 1; i <= n; i++)
    if (a[i] != i - 1) return false;
  return true;
}
void xl() {
  long k1 = abs(a[1] - 0);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      a[i] = a[i] - k1;
      if (a[i] < 0) a[i] += n;
    } else {
      a[i] = a[i] + k1;
      if (a[i] >= n) a[i] = a[i] % n;
    }
  }
  if (kt())
    cout << "Yes";
  else
    cout << "No";
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  doc();
  xl();
}
