#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    ar[i] = temp;
  }
  int m;
  cin >> m;
  int wire, location;
  while (m--) {
    cin >> wire >> location;
    wire--;
    if (wire != 0) ar[wire - 1] += location - 1;
    if (wire != n - 1) ar[wire + 1] += ar[wire] - location;
    ar[wire] = 0;
  }
  for (int i = 0; i < n; ++i) {
    cout << ar[i] << endl;
  }
  return 0;
}
