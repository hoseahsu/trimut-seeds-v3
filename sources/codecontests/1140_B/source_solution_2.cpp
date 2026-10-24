#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, MI;
  string a;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k = 0;
    MI = 105;
    cin >> n;
    cin >> a;
    for (int j = 0; j < n - 1; j++) {
      if (a[j] == '<' && a[j + 1] == '>') {
        k = min(j + 1, n - (j + 1));
        if (MI > k) MI = k;
      }
    }
    if (a[0] == '>' || a[n - 1] == '<') MI = 0;
    if (MI != 105)
      cout << MI << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
