#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> A(n, 0), B(m, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    int times = n;
    if (n <= 1) {
      cout << "YES" << endl;
      continue;
    }
    while (times--) {
      int flag = 0;
      for (int p = 0; p < m; p++) {
        int i = B[p] - 1;
        if (A[i] > A[i + 1]) {
          swap(A[i], A[i + 1]);
          flag = 1;
        }
      }
      if (flag == 0) break;
    }
    int flag = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] >= A[i - 1])
        continue;
      else {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
