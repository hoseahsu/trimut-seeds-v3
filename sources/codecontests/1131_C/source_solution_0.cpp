#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end(), greater<int>());
  vector<int> ans(n, 0);
  int k = 0;
  int i = n / 2;
  int j = i - 1;
  while (j >= 0) {
    if (n > i) ans[i++] = arr[k];
    k++;
    ans[j--] = arr[k];
    k++;
  }
  if (n % 2 != 0) ans[n - 1] = arr[n - 1];
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
