#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int arr[n];
    int arr1[m];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> arr1[i];
    }
    int num = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i] == arr1[j]) {
          num = arr[i];
          break;
        }
      }
    }
    if (num != -1) {
      cout << "YES" << endl;
      cout << "1 " << num << endl;
    } else
      cout << "NO" << endl;
  }
}
