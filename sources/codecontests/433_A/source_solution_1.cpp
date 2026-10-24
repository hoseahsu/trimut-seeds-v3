#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  map<int, int> m;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    m[a[i]]++;
  }
  for (size_t i = 0; i <= m[100]; i++) {
    for (size_t j = 0; j <= m[200]; j++) {
      if (i * 100 + j * 200 == sum - (i * 100 + j * 200)) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
