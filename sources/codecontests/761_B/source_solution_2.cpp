#include <bits/stdc++.h>
using namespace std;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, m, x;
  cin >> n >> m;
  vector<long long> v1, v2;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v1.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    v2.push_back(x);
  }
  for (int i = 0; i <= m; i++) {
    vector<long long> temp = v2;
    for (int h = 0; h < n; h++) {
      temp[h] = (temp[h] + i) % m;
    }
    sort(temp.begin(), temp.end());
    long long counter = 0;
    for (int h = 0; h < n; h++) {
      if (temp[h] == v1[h]) counter++;
    }
    if (counter == n) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
