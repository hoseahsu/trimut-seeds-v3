#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> v1, v2;
  long long int n, i, j = 0, x, c = 0, k, l = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    v1.push_back(x);
    v2.push_back(x);
  }
  sort(v1.begin(), v1.end());
  for (i = 0; i < n; i++) {
    if (v1[i] == v2[i] || i == n - 1) {
      if (c == 1) {
        if (v1[i + 1] == v2[i + 1] || i == n - 1) {
          if (i == n - 1 && v1[i] != v2[i]) {
            reverse(v2.begin() + j, v2.end());
            l = 1;
          } else
            reverse(v2.begin() + j, v2.begin() + i);
          break;
        } else
          continue;
      }
      if (c < 1) j++;
      continue;
    } else {
      if (c != 1) {
        j = i;
        c++;
      }
    }
  }
  for (k = 0; k < n; k++) {
    if (v1[k] != v2[k]) {
      cout << "no";
      exit(0);
    }
  }
  cout << "yes\n";
  if (j == i)
    cout << 1 << " " << 1;
  else if (i == n - 1 && l == 1)
    cout << j + 1 << " " << n;
  else
    cout << j + 1 << " " << i;
}
