#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int m;
  cin >> m;
  long long int copy = m;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  long long int maxi = arr[n - 1];
  for (long long int i = 0; i < n; i++) {
    m -= maxi - arr[i];
  }
  if (m < 0) {
    cout << maxi << " " << maxi + copy;
  } else {
    long long int div = m / n;
    if (m % n != 0) {
      div++;
    }
    cout << maxi + div << " " << maxi + copy;
  }
}
