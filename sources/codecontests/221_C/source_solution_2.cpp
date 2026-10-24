#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ct = 0;
  cin >> n;
  vector<int> nums(n), nums_copy(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    nums_copy[i] = nums[i];
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; ++i) {
    if (nums_copy[i] != nums[i]) {
      ++ct;
    }
  }
  if (ct <= 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
