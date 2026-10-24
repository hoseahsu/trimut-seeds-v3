#include <bits/stdc++.h>
using namespace std;
int arr[100010 + 1], arr1[100010 + 1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < (l - 1); i++)
    if (arr[i] != arr1[i]) {
      cout << "LIE\n";
      return 0;
    }
  for (int i = r; i < n; i++)
    if (arr[i] != arr1[i]) {
      cout << "LIE\n";
      return 0;
    }
  cout << "TRUTH\n";
  return 0;
}
