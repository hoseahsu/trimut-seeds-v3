#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    int k = 0;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i]) k++;
    k *= 3;
    cout << k;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i]) cout << " " << i + 1 << " 1 " << i + 1;
    cout << "\n";
  }
  return 0;
}
