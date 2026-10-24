#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int arr[4][4], i, j, c = 0, rowsum[4], maxi = 0, sum;
  vector<pair<int, int>> v;
  arr[1][2] = 0;
  for (i = 1; i <= 3; i++) {
    sum = 0;
    for (j = 1; j <= 3; j++) {
      cin >> arr[i][j];
      if (arr[1][2] == arr[i][j] && i != j) c++;
      sum += arr[i][j];
    }
    if (maxi < sum) maxi = sum;
    rowsum[i] = sum;
  }
  if (c == 6) {
    arr[1][1] = arr[1][2];
    arr[2][2] = arr[1][2];
    arr[3][3] = arr[1][2];
  } else {
    i = maxi + 1;
    while (1) {
      if ((i - rowsum[1]) + (i - rowsum[2]) + (i - rowsum[3]) == i) break;
      i++;
    }
    arr[1][1] = i - rowsum[1];
    arr[2][2] = i - rowsum[2];
    arr[3][3] = i - rowsum[3];
  }
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
